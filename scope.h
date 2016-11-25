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
    float x;
    float y;
    float z;
    float w;
}               t_point;

typedef float t_matrix[4][4];

typedef struct s_kval
{
    float r;
    float g;
    float b;
}               t_kval;

typedef struct s_perspective
{
    float fov;
    float ratio;
    float near;
    float far;
}              t_perspective;

typedef struct s_material
{
    char *name;
    t_kval ka;
    t_kval ks;
    t_kval kd;
    float  specular_exponent;
    float  transparency;
    int     illum;
}               t_material;

typedef struct s_open_gl
{
    GLFWwindow  *window;
    GLuint      VBO;
    GLuint      VAO;
    GLuint      EBO;
    GLuint      shader_program;
    GLfloat     *vertices;
    GLuint      *indices;
    GLuint      matrix_pass;
}               t_open_gl;

typedef struct s_env
{
    unsigned int num_vertex;
    unsigned int num_faces;
    unsigned int num_materials;
    t_open_gl    ogl;
    t_material   *material;
    t_matrix     mvp;
    t_matrix     m;
    t_matrix     v;
    t_matrix     p;
}               t_env;


void        read_obj(char *file, t_env *env);
int         check_file(char *file);
void        count_materials(char *file, t_env *env);
void        init_env(t_env *env);
void        assing_mem(t_env *env);
void        ft_exit(char *msg, int exit_code, t_env *env);
void        save_materials(split[1], env);
void        tranclation(t_point *apply, t_point move_by);
t_point     point_delta(t_point *p1, t_point *p2);
void        negate_point(t_point *p);
void        apply_rotate_x(t_point *apply, t_point center, float angle);
void        apply_rotate_y(t_point *apply, t_point center, float angle);
void        apply_rotate_z(t_point *apply, t_point center, float angle);
GLuint      load_program(char *vertex_shader, char *fragment_shader);
char        *shaderLoadSource(char *file);
void        count_fae_points(char **split, t_env *env);
void        count_components(char *file, t_env *env);
void        init_ogl(t_env *env);
void        loop_ogl(t_env *env);
void        bind_buffers(t_env *env);
void        key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
float       dot_product(t_point *p1, t_point *p2);
t_point     cross_product(t_point *p1, t_point *p2);
t_point     normalize(t_point p);
t_point     vec_sub(t_point p1, t_point p2);
void        perspective(t_matrix *dest, t_perspective perspective);
void        look_at(t_point pos, t_point look, t_point up, t_matrix *dest);
void        matrix_matrix(t_matrix m1, t_matrix m2, t_matrix *dest);
void        init_mat_identity(t_matrix *mat);

#endif //SCOPE_SCOPE_H_H
