//
// Created by Robert JONES on 2016/11/24.
//

#include "scope.h"

t_point matrix_vector(t_matrix mat , t_point p)
{
    t_point re;

    re.x = (mat[0][0] * p.x)+(mat[0][1] * p.y)+(mat[0][2] * p.z)+(mat[0][3] * p.z);
    re.y = (mat[1][0] * p.x)+(mat[1][1] * p.y)+(mat[1][2] * p.z)+(mat[1][3] * p.z);
    re.z = (mat[2][0] * p.x)+(mat[2][1] * p.y)+(mat[2][2] * p.z)+(mat[2][3] * p.z);
    re.w = (mat[3][0] * p.x)+(mat[3][1] * p.y)+(mat[3][2] * p.z)+(mat[3][3] * p.z);

    return (re);
}

void matrix_matrix(t_matrix m1, t_matrix m2, t_matrix *dest)
{
    int i;
    int j;

    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
        {
            (*dest)[i][j] = (m1[i][0] * m2 [0][j]) + (m1[i][1] * m2 [1][j]) + (m1[i][2] * m2 [2][j]) + (m1[i][3] * m2 [3][j]);
        }
    }
}

void rotat_x(float angle, t_matrix *dest)
{
    float sinv;
    float cosv;
   
    angle = angle * (M_PI / 180);
    sinv = sin(angle);
    cosv = cos(angle);
    init_matrix(dest);
    (*dest)[0][0] = 1;
    (*dest)[1][1] = cosv;
    (*dest)[2][1] = (-sinv);
    (*dest)[1][2] = sinv;
    (*dest)[2][2] = cosv;
    (*dest)[3][3] = 1;
  
}

void rotat_y(float angle, t_matrix *dest)
{
    float sinv;
    float cosv;
   
    angle = angle * (M_PI / 180);
    sinv = sin(angle);
    cosv = cos(angle);
    init_matrix(dest);
    (*dest)[0][0] = cosv;
    (*dest)[2][0] = sinv;
    (*dest)[1][1] = 1;
    (*dest)[0][2] = (-sinv);
    (*dest)[2][2] = cosv;
    (*dest)[3][3] = 1;
}

void rotat_z(float angle, t_matrix *dest)
{
    float sinv;
    float cosv;

    angle = angle * (M_PI / 180);
    sinv = sin(angle);
    cosv = cos(angle);
    init_matrix (dest);
    (*dest)[0][0] = cosv;
    (*dest)[1][0] = -sinv;
    (*dest)[0][1] = sinv;
    (*dest)[1][1] = cosv;
    (*dest)[2][2] = 1;
    (*dest)[3][3] = 1;
}