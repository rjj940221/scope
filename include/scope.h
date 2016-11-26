/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:17:17 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 15:27:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOPE_SCOPE_H
# define SCOPE_SCOPE_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <glew.h>
# include <glfw3.h>
# include <assert.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define TRUE 1
# define FALSE 0

typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_point;

typedef float	t_matrix[4][4];

typedef struct	s_kval
{
	float	r;
	float	g;
	float	b;
}				t_kval;

typedef struct	s_perspective
{
	float	fov;
	float	ratio;
	float	near;
	float	far;
}				t_perspective;

typedef struct	s_material
{
	char	*name;
	t_kval	ka;
	t_kval	ks;
	t_kval	kd;
	float	specular_exponent;
	float	transparency;
	int		illum;
}				t_material;

typedef struct	s_obj
{
	unsigned int	num_vertex;
	unsigned int	num_faces;
	GLfloat		*vertices;
	GLuint		*indices;
	GLuint		vbo;
	GLuint		vao;
	GLuint		ebo;
    t_point     max;
    t_point     min;
    t_point     mid;
}				t_obj;

typedef struct	s_open_gl
{
	GLFWwindow	*window;
	GLuint		shader_program;
	GLuint		matrix_pass;
    GLuint      center_pass;
}				t_open_gl;

typedef struct	s_env
{
	int	num_obj;
	unsigned int	num_materials;
	t_obj			*obj;
	t_open_gl		ogl;
	t_material		*material;
	t_matrix		mvp;
	t_matrix		m;
	t_matrix		v;
	t_matrix		p;
	t_point			trans;
	t_point			rot;
}				t_env;

void			read_obj(char *file, t_env *env);
int				check_file(char *file);
void			count_materials(char *file, t_env *env);
void			init_env(t_env *env);
void			assing_mem(t_env *env);
void			ft_exit(char *msg, int exit_code, t_env *env);
void			save_materials(char *filename, t_env *env);
void			tranclation(t_point *apply, t_point move_by);
t_point			point_delta(t_point *p1, t_point *p2);
void			negate_point(t_point *p);
void			apply_rotate_x(t_point *apply, t_point center, float angle);
void			apply_rotate_y(t_point *apply, t_point center, float angle);
void			apply_rotate_z(t_point *apply, t_point center, float angle);
GLuint			load_program(char *vertex_shader, char *fragment_shader);
char			*shader_load_source(char *file);
void			count_fae_points(char **split, t_env *env);
void			count_components(char *file, t_env *env);
void			init_ogl(t_env *env);
void			loop_ogl(t_env *env);
void			bind_buffers(t_env *env);
void			key_callback(GLFWwindow *window, int key, int scancode,
					int action, int mode);
float			dot_product(t_point *p1, t_point *p2);
t_point			cross_product(t_point *p1, t_point *p2);
t_point			normalize(t_point p);
t_point			vec_sub(t_point p1, t_point p2);
void			perspective(t_matrix *dest, t_perspective perspective);
void			look_at(t_point pos, t_point look, t_point up, t_matrix *dest);
void			matrix_matrix(t_matrix m1, t_matrix m2, t_matrix *dest);
void			init_mat_identity(t_matrix *mat);
void			init_matrix(t_matrix *mat);
void			cpy_matrix(t_matrix *src, t_matrix *dest);
void			rotat_x(float angle, t_matrix *dest);
void			rotat_y(float angle, t_matrix *dest);
void			rotat_z(float angle, t_matrix *dest);
void			translation_mat(float x, float y, float z, t_matrix *dest);
void			ft_strarrdel(char **del);
void			move_keys(t_env *env);
void			rot_keys(t_env *env);
void			test_key(t_env *env);
void			keys(t_env *env);
void            init_obj(t_obj *obj);

#endif
