#include "scope.h"

void print_env(t_env *env) {
    int i = -1;
    while (++i < env->num_vertex)
        printf("x: %f, y: %f, z: %f, w: %f\n", env->verticy[i].x, env->verticy[i].y, env->verticy[i].z,
               env->verticy[i].w);
    i = -1;
    while (++i < env->num_faces){
        int j = -1;
        ft_putchar('(');
        while (env->faces[i][++j]){
            printf("x: %f, y: %f, z: %f, w: %f ", env->faces[i][j]->x, env->faces[i][j]->y, env->faces[i][j]->z,env->faces[i][j]->w);
        }
        ft_putstr(")\n");
    }
    ft_printf("faces iterated %d\n", i);
}

int main(int ac, char **av) {
    t_env env;

    if (ac != 2) {
        ft_putstr("please specify one and only one file.\n");
        return (0);
    }
    init_env(&env);
    read_obj(av[1], &env);
    print_env(&env);
    ft_printf("num : vert %d face %d mater %d \n", env.num_vertex, env.num_faces, env.num_materials);

    ft_exit("ran successfully\n", EXIT_SUCCESS, &env);
    return 1;
}