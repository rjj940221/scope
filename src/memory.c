/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:43:24 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 15:21:58 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

void	init_env(t_env *env)
{
	t_matrix tmp;

	init_mat_identity(&tmp);
	env->num_vertex = 0;
	env->num_materials = 0;
	env->num_faces = 0;
	init_mat_identity(&env->m);
	look_at((t_point){4, 3, -3, 0}, (t_point)
			{0, 0, 0, 0}, (t_point){0, 1, 0, 0}, &env->v);
	perspective(&env->p, (t_perspective){60, 800 / 600, 1.0, 100});
	matrix_matrix(env->m, env->v, &tmp);
	matrix_matrix(tmp, env->p, &env->mvp);
	env->trans = (t_point){0, 0, 0, 0};
	env->rot = (t_point){0, 0, 0, 0};
}

void	assing_mem(t_env *env)
{
	if (!(env->ogl.indices = (GLuint *)
				malloc(sizeof(GLuint) * env->num_faces)))
		ft_exit("failed to assigne memory for faces\n", EXIT_FAILURE, env);
	if (!(env->ogl.vertices = (GLfloat *)
				malloc(sizeof(GLfloat) * env->num_vertex)))
		ft_exit("failed to assigne memory for verticy\n", EXIT_FAILURE, env);
	if (!(env->material = (t_material *)
				malloc(sizeof(t_material) * env->num_materials)))
		ft_exit("failed to asingen memory for materials\n", EXIT_FAILURE, env);
}

void	ft_exit(char *msg, int exit_code, t_env *env)
{
	ft_putstr(msg);
	if (env->ogl.vertices)
		ft_memdel((void **)&env->ogl.vertices);
	if (env->ogl.indices)
		ft_memdel((void **)&env->ogl.indices);
	if (env->material)
		ft_memdel((void **)&env->material);
	glfwTerminate();
	exit(exit_code);
}

void	ft_strarrdel(char **del)
{
	int	i;

	i = -1;
	if (del)
	{
		while (del[++i])
		{
			free(del[i]);
			del[i] = NULL;
		}
		free(del);
		del = NULL;
	}
}

int		check_file(char *file)
{
	if (access(file, R_OK) == -1)
	{
		ft_printf("The file '%s' cannot be read\n", file);
		return (FALSE);
	}
	return (TRUE);
}
