//
// Created by Robert JONES on 2016/11/24.
//

#include "scope.h"

void init_matrix(t_matrix *mat){
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            (*mat)[i][j] = 0.0;
    }
}

void init_mat_identity(t_matrix *mat)
{

    init_matrix(mat);
    (*mat)[0][0] = 1;
    (*mat)[1][1] = 1;
    (*mat)[2][2] = 1;
    (*mat)[3][3] = 1;
}

void perspective(t_matrix *mat, t_perspective per)
{
    assert(per.ratio != 0);
    assert(per.far != per.near);
    per.fov = per.fov * (M_PI / 180);
    float half_fov = tan(per.fov /2);
    init_matrix(mat);
    (*mat)[0][0] = 1 / (per.ratio * half_fov);
    (*mat)[1][1] = 1 / (half_fov);
    (*mat)[2][2] = -(per.far + per.near) / (per.far - per.near);
    (*mat)[2][3] = -1;
    (*mat)[3][2] = -(2 * per.far * per.near) / (per.far - per.near);
    (*mat)[3][3] = 0;
}

void look_at(t_point pos, t_point look, t_point up, t_matrix *mat)
{
    t_point     f;
    t_point     s;
    t_point     u;

    f = normalize(vec_sub(look, pos));
    s = normalize(cross_product(&f, &up));
    u = cross_product(&s,&f);
    init_matrix(mat);
    (*mat)[0][0] = s.x;
    (*mat)[1][0] = s.y;
    (*mat)[2][0] = s.z;
    (*mat)[0][1] = u.x;
    (*mat)[1][1] = u.y;
    (*mat)[2][1] = u.z;
    (*mat)[0][2] = -f.x;
    (*mat)[1][2] = -f.y;
    (*mat)[2][2] = -f.z;
    (*mat)[3][0] = -dot_product(&s, &pos);
    (*mat)[3][1] = -dot_product(&u, &pos);
    (*mat)[3][2] = dot_product(&f, &pos);
    (*mat)[3][3] = 1.0f;
}
