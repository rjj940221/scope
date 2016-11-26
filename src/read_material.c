/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:48:15 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 15:24:39 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

void	count_materials(char *file, t_env *env)
{
	char	*line;
	char	**split;
	int		fd;

	if (check_file(file) == TRUE)
	{
		fd = open(file, O_RDONLY);
		if (fd != -1)
		{
			while (get_next_line(fd, &line))
			{
				split = ft_strsplit(line, ' ');
				if (split[0] != NULL && ft_strcmp(split[0], "newmtl") == 0)
					(env->num_materials)++;
			}
		}
	}
}

void	save_materials(char *file, t_env *env)
{
	printf("saving flie %s for material %d\n", file, env->num_materials);
}
