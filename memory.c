#include "scope.h"

void init_env(t_env *env) {
    env->num_vertex = 0;
    env->num_materials = 0;
    env->num_faces = 0;
}

void assing_mem(t_env *env) {
    if (!(env->faces = (t_face *) malloc(sizeof(t_face) * env->num_faces)))
        ft_exit("failed to assigne memory for faces\n", EXIT_FAILURE, env);
    if (!(env->verticy = (t_face *) malloc(sizeof(t_point) * env->num_vertex)))
        ft_exit("failed to assigne memory for verticy\n", EXIT_FAILURE, env);
    if (!(env->material = (t_face *) malloc(sizeof(t_material) * env->num_materials)))
        ft_exit("failed to asingen memory for materials\n", EXIT_FAILURE, env);
}

void ft_exit(char *msg, int exit_code, t_env *env) {
    int i;

    ft_putstr(msg);
    if (env->verticy) {
        free(env->verticy);
        env->verticy = NULL;
    }
    if (env->faces) {
        i = -1;
        while (++i < env->num_faces) {
            /*if (env->faces[i]) {
                free(env->faces[i]);
                env->faces[i] = NULL;
            }*/
        }
        free(env->faces);
        env->faces = NULL;
    }
    if (env->material) {
        free(env->material);
        env->material = NULL;
    }
    exit(exit_code);
}

void ft_strarrdel(char **del) {
    int i;

    i = -1;
    if (del) {
        while (del[++i]) {
            free(del[i]);
            del[i] = NULL;
        }
        free(del);
        del = NULL;
    }
}