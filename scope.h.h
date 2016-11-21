//
// Created by Robert JONES on 2016/11/21.
//

#ifndef SCOPE_SCOPE_H_H
#define SCOPE_SCOPE_H_H

#include "libft/libft.h"

typedef struct s_point
{
    float x;
    float y;
    float z;
    float w;
}               t_point;

typedef struct s_4face{
    t_point *p1;
    t_point *p2;
    t_point *p3;
    t_point *p4;
}               t_4face;

typedef struct s_3face{
    t_point *p1;
    t_point *p2;
    t_point *p3;
}               t_3face;

typedef struct s_env
{

}               t_env;

#endif //SCOPE_SCOPE_H_H
