/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readobj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:01:15 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 15:07:30 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

void	save_vert(t_env *env, char **split)
{
	static unsigned int	vcount;
	int					i;

	if (vcount < env->num_vertex)
	{
		i = 0;
		while (split[++i] && i < 6)
			env->ogl.vertices[vcount++] = atof(split[i]);
		if (i < 5)
			env->ogl.vertices[vcount++] = 1.0;
		if (i < 4 || i > 5)
			ft_exit("insufficient data to make point \n", EXIT_FAILURE, env);
	}
}

void	save_face(t_env *env, char **split)
{
	int					i;
	static unsigned int	face_count;

	if (face_count < env->num_faces)
	{
		if (split[4])
		{
			i = 0;
			while (++i < 4)
				env->ogl.indices[face_count++] = (ft_atoi(split[i]) - 1);
			i = 2;
			while (++i < 5)
				env->ogl.indices[face_count++] = (ft_atoi(split[i]) - 1);
			env->ogl.indices[face_count++] = (ft_atoi(split[1]) - 1);
		}
		else
		{
			i = 0;
			while (++i < 4)
				env->ogl.indices[face_count++] = (ft_atoi(split[i]) - 1);
		}
	}
}

void	save_content(char *file, t_env *env)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &line))
		{
			split = ft_strsplit(line, ' ');
			if (split[0][0] != '#')
			{
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

void	read_obj(char *file, t_env *env)
{
	if (!check_file(file))
		exit(EXIT_FAILURE);
	count_components(file, env);
	assing_mem(env);
	save_content(file, env);
}
