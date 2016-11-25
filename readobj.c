//
// Created by Robert JONES on 2016/11/21.
//

#include "scope.h"

void    save_vert(t_env *env, char **split){
    static unsigned int  vcount;
    int i;

    if (vcount < env->num_vertex) {
        i = 0;
        while (split[++i] && i < 6)
            env->ogl.vertices[vcount++] = atof(split[i]);
        if (i < 5)
            env->ogl.vertices[vcount++] = 1.0;
        if (i < 4 || i > 5)
            ft_exit("insufficient data to make point \n", EXIT_FAILURE, env);
    }
}

void    save_face(t_env *env, char **split)
{
    int                 i;
    static unsigned int face_count;

    if (face_count < env->num_faces)
    {
        i = 0;
        while (++i < 4) {
            env->ogl.indices[face_count++] = ft_atoi(split[i]);
            printf("saving index %s at %d\n", split[i], face_count);
        }
        if (split[4])
        {
            i = 1;
            while (++i < 5) {
                env->ogl.indices[face_count++] = ft_atoi(split[i]);
                printf("saving index %s at %d\n", split[i], face_count);
            }
        }
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