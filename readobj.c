//
// Created by Robert JONES on 2016/11/21.
//

# include "scope.h"


void count_components(char *file, t_env *env)
{
    int fd;
    char *line;
    char **split;
    int  end;
    int  linere;

    fd = open(file, O_RDONLY);
    if (fd != -1)
    {
        while (get_next_line(fd, &line) > 0)
        {
            split = ft_strsplit(line, ' ');
            if(split[0][0] != '#') {
                if (ft_strcmp(split[0], "v") == 0)
                    (env->num_vertex)++;
                else if (ft_strcmp(split[0], "f") == 0)
                    (env->num_faces)++;
                else if (ft_strcmp(split[0], "mtllib") == 0)
                    count_materials(split[1], env);
            }
            ft_strdel(&line);
            ft_strarrdel(split);
        }
        close(fd);
    }
}

void    save_vert(t_env *env, char **split){
    static int  vcount;
    int i;

    if (vcount < env->num_vertex) {
        i = 0;
        while (split[++i])
        {
            if (i == 1)
                env->verticy[vcount].x = ft_atod(split[1]);
            if (i == 2)
                env->verticy[vcount].y = ft_atod(split[2]);
            if (i == 3)
                env->verticy[vcount].z = ft_atod(split[3]);
            if (i == 4)
                env->verticy[vcount].w = ft_atod(split[4]);
        }
        if (i < 5)
            env->verticy[vcount].w = 1.0;
        if (i < 4)
            ft_exit("inserficient data to make point \n", EXIT_FAILURE, env);
        vcount++;
    }
}

void    save_face(t_env *env, char **split)
{
    int                 i;
    int                 offset;
    static unsigned int face_count;

    if (face_count < env->num_faces)
    {
        i = 0;
        while (split[++i])
            ;
        env->faces[face_count] = (t_face)malloc(sizeof(t_point *) * (i));
        i = 0;
        while (split[++i])
        {
            offset = ft_atoi(split[i]);
            if (offset < 0)
                offset = env->num_vertex - offset;
            offset -= 1;
            env->faces[face_count][i - 1] = &(env->verticy[offset]);
        }
        env->faces[face_count][i - 1] = NULL;
        face_count++;
    }
}

void read_obj(char *file, t_env *env)
{
    int fd;
    char *line;
    char **split;

    if (!check_file(file))
        exit(EXIT_FAILURE);
    count_components(file, env);
    assing_mem(env);
    fd = open(file, O_RDONLY);
    if (fd != -1){
        while (get_next_line(fd, &line))
        {
            split = ft_strsplit(line, ' ');
            if(split[0][0] != '#') {
                if (ft_strcmp(split[0], "v") == 0)
                   save_vert(env, split);
                else if (ft_strcmp(split[0], "f") == 0)
                    save_face(env, split);
                else if (ft_strcmp(split[0], "mtllib") == 0)
                    save_materials(split[1], env);
            }
            ft_strdel(&line);
            ft_strarrdel(split);
        }
        close(fd);
    }
}