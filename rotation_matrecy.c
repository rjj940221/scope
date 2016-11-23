//
// Created by Robert JONES on 2016/11/23.
//

#include "scope.h"

void rotate_x(t_point *apply, t_point center, double angle){
    t_point tmp;
    t_pont  delta;
    double cos;
    double sin;

    cos = cos(angle);
    sin = sin(angle);
    tmp = *apply;
    delta = point_delta(&center, &{0,0,0,0});
    negate_point(delta);
    translate(&tmp, delta);
    apply->x = tmp->x;
    apply->y = (tmp->y * cos) + (tmp->z * (-sin));
    apply->z = (tmp->y * sin) + (tmp->z * cos);
    negate_point(delta);
    translate(apply, delta);
}

void rotate_y(t_point *apply, t_point center, double angle){
    t_point tmp;
    t_pont  delta;
    double cos;
    double sin;

    cos = cos(angle);
    sin = sin(angle);
    tmp = *apply;
    delta = point_delta(&center, &{0,0,0,0});
    negate_point(delta);
    translate(&tmp, delta);
    apply->x = (tmp->x * cos) + (tmp->z * sin);
    apply->y = tmp->y ;
    apply->z = (tmp->x * (-sin)) + (tmp->z * cos);
    negate_point(delta);
    translate(apply, delta);
}

void rotate_z(t_point *apply, t_point center, double angle){
    t_point tmp;
    t_pont  delta;
    double cos;
    double sin;

    cos = cos(angle);
    sin = sin(angle);
    tmp = *apply;
    delta = point_delta(&center, &{0,0,0,0});
    negate_point(delta);
    translate(&tmp, delta);
    apply->x = (tmp->x * cos) + (tmp->y * (-sin));
    apply->y = (tmp->x * sin) + (tmp->y * (cos));
    apply->z = tmp->z;
    negate_point(delta);
    translate(apply, delta);
}