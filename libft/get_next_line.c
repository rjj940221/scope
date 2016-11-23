#include "libft.h"

int add_buff(char **saveline, int fd){
    char buff[BUFF_SIZE + 1];
    char *tmp;
    int  re;

    tmp = *saveline;
    re = read(fd, buff, BUFF_SIZE - 1);
    buff[re] = '\0';
    if (*saveline == NULL)
        *saveline = ft_strdup(buff);
    else {
        tmp = *saveline;
        *saveline = ft_strjoin(*saveline, buff);
        ft_strdel(&tmp);
    }
    return (re);
}

int ft_return(int exitcode, char** del){
    ft_strdel(del);
    return(exitcode);
}

int get_next_line(const int fd, char **line)
{
    static t_file   files[MAX_FILE_DESC];
    char            *nline;
    char            *tmp;

    if (fd == -1 || fd >= MAX_FILE_DESC)
        return (-1);

    while ((files[fd].sline == NULL) || ((nline = ft_strchr(files[fd].sline, '\n')) == NULL && files[fd].read_re > 0))
        files[fd].read_re = add_buff(&files[fd].sline, fd);
    if (files[fd].sline[0] == '\0' && files[fd].read_re == 0)
        return (ft_return(0, &files[fd].sline));
    if (files[fd].read_re == -1)
        return(ft_return(-1, &files[fd].sline));
    if (nline == NULL)
    {
        *line = ft_strdup(files[fd].sline);
        return (ft_return(1, &files[fd].sline));
    }
    *line = ft_strsub(files[fd].sline, 0, (int)(nline - files[fd].sline));
    tmp = files[fd].sline;
    files[fd].sline = ft_strsub(files[fd].sline, (int)(nline - files[fd].sline) + 1,
                                (ft_strlen(files[fd].sline) - ((int)(nline - files[fd].sline) + 1)));
    ft_strdel(&tmp);
    return (1);
}