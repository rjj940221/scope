/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:50:41 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 14:00:36 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

int	main(int ac, char **av)
{
	t_env env;

	if (ac != 2)
	{
		ft_putstr("please specify one and only one file.\n");
		return (0);
	}
	init_env(&env);
	init_ogl(&env);
	read_obj(av[1], &env);
	bind_buffers(&env);
	loop_ogl(&env);
	ft_exit("ran successfully\n", EXIT_SUCCESS, &env);
	return (1);
}
