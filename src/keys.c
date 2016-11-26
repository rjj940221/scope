/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:48:07 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 15:33:26 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

void	keys(t_env *env)
{
	t_matrix	trans;
	t_matrix	rot;
	t_matrix	tmp;

	test_key(env);
	move_keys(env);
	rot_keys(env);
	translation_mat(env->trans.x, env->trans.y, env->trans.z, &trans);
	init_mat_identity(&env->m);
	matrix_matrix(trans, env->m, &tmp);
	cpy_matrix(&tmp, &env->m);
	rotat_x(env->rot.x, &rot);
	matrix_matrix(rot, env->m, &tmp);
	cpy_matrix(&tmp, &env->m);
	rotat_y(env->rot.y, &rot);
	matrix_matrix(rot, env->m, &tmp);
	cpy_matrix(&tmp, &env->m);
	rotat_z(env->rot.z, &rot);
	matrix_matrix(rot, env->m, &tmp);
	cpy_matrix(&tmp, &env->m);
	matrix_matrix(env->m, env->v, &tmp);
	matrix_matrix(tmp, env->p, &env->mvp);
}

void	move_keys(t_env *env)
{
	if (glfwGetKey(env->ogl.window, GLFW_KEY_Q) == GLFW_PRESS)
		env->trans.x += 0.2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_A) == GLFW_PRESS)
		env->trans.x -= 0.2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_W) == GLFW_PRESS)
		env->trans.y += 0.2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_S) == GLFW_PRESS)
		env->trans.y -= 0.2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_E) == GLFW_PRESS)
		env->trans.z += 0.2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_D) == GLFW_PRESS)
		env->trans.z -= 0.2;
}

void	rot_keys(t_env *env)
{
	if (glfwGetKey(env->ogl.window, GLFW_KEY_I) == GLFW_PRESS)
		env->rot.x += 2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_J) == GLFW_PRESS)
		env->rot.x -= 2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_O) == GLFW_PRESS)
		env->rot.y += 2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_K) == GLFW_PRESS)
		env->rot.y -= 2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_P) == GLFW_PRESS)
		env->rot.z += 2;
	if (glfwGetKey(env->ogl.window, GLFW_KEY_L) == GLFW_PRESS)
		env->rot.z -= 2;
}

void	test_key(t_env *env)
{
	if (glfwGetKey(env->ogl.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(env->ogl.window, GL_TRUE);
}
