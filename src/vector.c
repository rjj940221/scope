/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:07:56 by rojones           #+#    #+#             */
/*   Updated: 2016/11/26 15:09:30 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/scope.h"

float	dot_product(t_point *p1, t_point *p2)
{
	float	re;

	re = (p1->x * p2->x) + (p1->y * p2->y) + (p1->z * p2->z);
	return (re);
}

t_point	cross_product(t_point *p1, t_point *p2)
{
	t_point	re;

	re.x = (p1->y * p2->z) - (p1->z * p2->y);
	re.y = (p1->z * p2->x) - (p1->x * p2->z);
	re.z = (p1->x * p2->y) - (p1->y * p2->x);
	re.w = 1;
	return (re);
}

t_point	normalize(t_point p)
{
	float	mag;
	t_point	re;

	mag = sqrt((p.x * p.x) + (p.y * p.y) + (p.z * p.z));
	re.x = p.x / mag;
	re.y = p.y / mag;
	re.z = p.z / mag;
	re.w = 1;
	return (re);
}

t_point	vec_sub(t_point p1, t_point p2)
{
	t_point re;

	re.x = p1.x - p2.x;
	re.y = p1.y - p2.y;
	re.z = p1.z - p2.z;
	re.w = 1;
	return (re);
}
