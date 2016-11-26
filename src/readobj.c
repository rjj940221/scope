/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readobj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:01:15 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 18:47:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

void	extrams(t_point test, t_obj *obj)
{
	if (test.x > obj->max.x)
		obj->max.x = test.x;
	if (test.y > obj->max.y)
		obj->max.y = test.y;
	if (test.z > obj->max.z)
		obj->max.z = test.z;
	if (test.x < obj->min.x)
		obj->min.x = test.x;
	if (test.y < obj->min.y)
		obj->min.y = test.y;
	if (test.z < obj->min.z)
		obj->min.z = test.z;
}

void	save_vert(t_env *env, int ocount, char **split)
{
	static unsigned int	vcount;
	int					i;

	if (vcount < env->obj[ocount].num_vertex)
	{
		i = 0;
		while (split[++i] && i < 6)
			env->obj[ocount].vertices[vcount++] = atof(split[i]);
		if (i < 5)
			env->obj[ocount].vertices[vcount++] = 1.0;
		if (i < 4 || i > 5)
			ft_exit("insufficient data to make point \n", EXIT_FAILURE, env);
		extrams((t_point){env->obj[ocount].vertices[vcount - 4],
				env->obj[ocount].vertices[vcount - 3],
				env->obj[ocount].vertices[vcount - 2],
				env->obj[ocount].vertices[vcount - 1]}, &env->obj[ocount]);
	}
}

void	save_face(t_env *env, int ocount, char **split)
{
	int					i;
	static unsigned int	face_count;

	if (face_count < env->obj[ocount].num_faces)
	{
		if (split[4])
		{
			i = 0;
			while (++i < 4)
				env->obj[ocount].indices[face_count++] =
					(ft_atoi(split[i]) - 1);
			i = 2;
			while (++i < 5)
				env->obj[ocount].indices[face_count++] =
					(ft_atoi(split[i]) - 1);
			env->obj[ocount].indices[face_count++] = (ft_atoi(split[1]) - 1);
		}
		else
		{
			i = 0;
			while (++i < 4)
				env->obj[ocount].indices[face_count++] =
					(ft_atoi(split[i]) - 1);
		}
	}
}

void	save_content(char *file, t_env *env)
{
	static int	ocount = -1;
	int			fd;
	char		*line;
	char		**split;

	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &line))
		{
			split = ft_strsplit(line, ' ');
			if (ft_strcmp(split[0], "o") == 0)
				++ocount;
			else if (ft_strcmp(split[0], "v") == 0)
				save_vert(env, ocount, split);
			else if (ft_strcmp(split[0], "f") == 0)
				save_face(env, ocount, split);
			else if (ft_strcmp(split[0], "mtllib") == 0)
				save_materials(split[1], env);
			ft_strdel(&line);
			ft_strarrdel(split);
		}
		close(fd);
	}
}

void	read_obj(char *file, t_env *env)
{
	int ocount;

	ocount = -1;
	if (!check_file(file))
		exit(EXIT_FAILURE);
	count_components(file, env);
	assing_mem(env);
	save_content(file, env);
	while (++ocount < env->num_obj)
		env->obj[ocount].mid = (t_point){
			(env->obj[ocount].min.x - env->obj[ocount].max.x) / 2,
				(env->obj[ocount].min.y - env->obj[ocount].max.y) / 2,
				(env->obj[ocount].min.z - env->obj[ocount].max.z) / 2,
				0
		};
}
