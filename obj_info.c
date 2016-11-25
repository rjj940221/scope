//
// Created by Robert JONES on 2016/11/25.
//

# include "scope.h"

void count_face_points(char **split, t_env *env)
{
    int i;

    i = 1;
    while(split[i])
        i++;
    i--;
    if (i == 3)
        env->num_faces += 3;
    else if (i == 4)
        env->num_faces += 6;
    else
    {
        ft_printf("there are %d elemints in the face\n", i);
        ft_exit("", EXIT_FAILURE, env);
    }
}

void count_components(char *file, t_env *env)
{
    int fd;
    char *line;
    char **split;

    fd = open(file, O_RDONLY);
    if (fd != -1)
    {
        while (get_next_line(fd, &line) > 0)
        {
            split = ft_strsplit(line, ' ');
            if(split[0][0] != '#') {
                if (ft_strcmp(split[0], "v") == 0)
                    (env->num_vertex) += 4;
                else if (ft_strcmp(split[0], "f") == 0)
                    count_face_points(split, env);
                else if (ft_strcmp(split[0], "mtllib") == 0)
                    count_materials(split[1], env);
            }
            ft_strdel(&line);
            ft_strarrdel(split);
        }
        close(fd);
    }
}