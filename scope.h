//
// Created by Robert JONES on 2016/11/21.
//

#ifndef SCOPE_SCOPE_H_H
#define SCOPE_SCOPE_H_H

#include "libft/libft.h"
#include <unistd.h>
#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <glew.h>
#include <glfw3.h>
#include <assert.h>
#define true 1
#define false 0

typedef struct s_point
{
    double x;
    double y;
    double z;
    double w;
}               t_point;

typedef t_point ** t_face;
typedef double t_matrix[4][4];
typedef struct s_kval
{
    double r;
    double g;
    double b;
}               t_kval;

typedef struct s_material
{
    char *name;
    t_kval ka;
    t_kval ks;
    t_kval kd;
    double  specular_exponent;
    double  transparency;
    int     illum;
}               t_material;

typedef struct s_env
{
    unsigned int num_vertex;
    unsigned int num_faces;
    unsigned int num_materials;
    t_point      *verticy;
    t_face       *faces;
    t_material   *material;
}               t_env;


void    read_obj(char *file, t_env *env);
int     check_file(char *file);
void    count_materials(char *file, t_env *env);
void    init_env(t_env *env);
void    assing_mem(t_env *env);
void    ft_exit(char *msg, int exit_code, t_env *env);
void    save_materials(split[1], env);
void    tranclation(t_point *apply, t_point move_by);
t_point point_delta(t_point *p1, t_point p2);
void    negate_point(t_point *p);
void    rotate_x(t_point *apply, t_point center, double angle);
void    rotate_y(t_point *apply, t_point center, double angle);
void    rotate_z(t_point *apply, t_point center, double angle);
GLuint  load_program(char *vertex_shader, char *fragment_shader);
char    *shaderLoadSource(char *file);
#endif //SCOPE_SCOPE_H_H
