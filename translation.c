//
// Created by Robert JONES on 2016/11/23.
//

#include "scope.h"

void tranclation(t_point *apply, t_point move_by)
{
    apply->x = move_by.x + apply->x;
    apply->y = move_by.y + apply->y;
    apply->z = move_by.z + apply->z;
}

t_point point_delta(t_point *p1, t_point *p2)
{
    t_point re;

    re.x = p1->x - p2->x;
    re.y = p1->y - p2->y;
    re.z = p1->x - p2->x;
    return (re);
}

void negate_point(t_point *p)
{
    p->x = 0 - p->x;
    p->y = 0 - p->y;
    p->z = 0 - p->z;
}

/*void translate_x(t_point *apply, double factor)
{
    apply->x += factor;
}

void translate_y(t_point *apply, double factor)
{
    apply->y += factor;
}

void translate_z(t_point *apply, double factor)
{
    apply->z += factor;
}*/