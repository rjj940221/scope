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
	env->num_obj = 0;
	init_mat_identity(&env->m);
	look_at((t_point){8, 6, -6, 0}, (t_point)
			{0, 0, 0, 0}, (t_point){0, 1, 0, 0}, &env->v);
	perspective(&env->p, (t_perspective){60, 800 / 600, 1.0, 100});
	matrix_matrix(env->m, env->v, &tmp);
	matrix_matrix(tmp, env->p, &env->mvp);
	env->trans = (t_point){0, 0, 0, 0};
	env->rot = (t_point){0, 0, 0, 0};
}

void	assing_mem(t_env *env)
{
	int ocount;

	if (!(env->material = (t_material *)
			malloc(sizeof(t_material) * env->num_materials)))
		ft_exit("failed to asingen memory for materials\n", EXIT_FAILURE, env);
	ocount = -1;
	while (++ocount < env->num_obj)
	{
		if (!(env->obj[ocount].indices = (GLuint *)
				malloc(sizeof(GLuint) * env->obj[ocount].num_faces)))
			ft_exit("failed to assigne memory for faces\n", EXIT_FAILURE, env);
		if (!(env->obj[ocount].vertices = (GLfloat *)
				malloc(sizeof(GLfloat) * env->obj[ocount].num_vertex)))
			ft_exit("failed to assigne memory for verticy\n", EXIT_FAILURE, env);
	}
}

void	ft_exit(char *msg, int exit_code, t_env *env)
{
   int ocount;

	ft_putstr(msg);
    ocount = -1;
    while (++ocount < env->num_obj)
    {
        if (env->obj[ocount].vertices)
            ft_memdel((void **) &env->obj[ocount].vertices);
        if (env->obj[ocount].indices)
            ft_memdel((void **) &env->obj[ocount].indices);
    }
    if (env->obj)
        ft_memdel((void **)&env->obj);
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
