//
// Created by Robert JONES on 2016/11/24.
//

#include "scope.h"

t_matrix *perspective(double fov, double ratio, double near, double far)
{
    t_matrix re;

    assert(ratio != 0);
    assert(far != near);
    fov = fov * (M_PI / 180);
    double half_fov = tan(fov /2);
    re[0][0] = 1 / (ratio * half_fov);
    re[1][1] = 1 / (half_fov);
    re[2][2] = -(far + near) / (far - near);
    re[2][3] = -1;
    re[3][2] = - (far * near) / (far - near);
    re[3][3] = 0;
    return re;
}

t_matrix *lookat()
{
    t_matrix re;

    return re;
}