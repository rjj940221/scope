/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:58:48 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 15:00:50 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

void	apply_rotate_x(t_point *apply, t_point center, float angle)
{
	t_point	tmp;
	t_point	delta;
	t_point	origin;
	double	cosv;
	double	sinv;

	angle = angle * (M_PI / 180);
	cosv = cos(angle);
	sinv = sin(angle);
	origin = (t_point){0, 0, 0, 0};
	tmp = *apply;
	delta = point_delta(&center, &origin);
	negate_point(&delta);
	tranclation(&tmp, delta);
	apply->x = tmp.x;
	apply->y = (tmp.y * cosv) + (tmp.z * (-sinv));
	apply->z = (tmp.y * sinv) + (tmp.z * cosv);
	negate_point(&delta);
	tranclation(apply, delta);
}

void	apply_rotate_y(t_point *apply, t_point center, float angle)
{
	t_point	tmp;
	t_point	delta;
	t_point	origin;
	double	cosv;
	double	sinv;

	angle = angle * (M_PI / 180);
	cosv = cos(angle);
	sinv = sin(angle);
	origin = (t_point){0, 0, 0, 0};
	tmp = *apply;
	delta = point_delta(&center, &origin);
	negate_point(&delta);
	tranclation(&tmp, delta);
	apply->x = (tmp.x * cosv) + (tmp.z * sinv);
	apply->y = tmp.y;
	apply->z = (tmp.x * (-sinv)) + (tmp.z * cosv);
	negate_point(&delta);
	tranclation(apply, delta);
}

void	apply_rotate_z(t_point *apply, t_point center, float angle)
{
	t_point	tmp;
	t_point	delta;
	t_point	origin;
	double	cosv;
	double	sinv;

	angle = angle * (M_PI / 180);
	cosv = cos(angle);
	sinv = sin(angle);
	origin = (t_point){0, 0, 0, 0};
	tmp = *apply;
	delta = point_delta(&center, &origin);
	negate_point(&delta);
	tranclation(&tmp, delta);
	apply->x = (tmp.x * cosv) + (tmp.y * (-sinv));
	apply->y = (tmp.x * sinv) + (tmp.y * (cosv));
	apply->z = tmp.z;
	negate_point(&delta);
	tranclation(apply, delta);
}
