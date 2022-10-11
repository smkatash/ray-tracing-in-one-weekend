#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <stdio.h>

// 3D vector library with support for basic vector math and 
// user-created vector operations.

typedef struct s_vec3 {
    double x;
    double y;
    double z;
} t_vec3;

// Sets each element of res to op(corresponding elements of a and b).
// Returns NULL if err(corresponding elements of a and b) returns 1.
// Otherwise, returns res.
inline t_vec3* Vec3_opErr(t_vec3* res, const t_vec3* a, const t_vec3* b, 
                      double(*op)(double, double), int(*err)(double, double))
{
    if (err(a->x, b->x) || err(a->y, b->y) || err(a->z, b->z)) return NULL;
    res->x = op(a->x, b->x);
    res->y = op(a->y, b->y);
    res->z = op(a->z, b->z);
    return res;
}

// Sets each element of res to op(corresponding element of vec, s).
// Returns NULL if err(corresponding element of vec, s) returns 1.
// Otherwise, returns res;
inline t_vec3* Vec3_opErrS(t_vec3* res, const t_vec3* vec, double s,
                       double(*op)(double, double), int(*err)(double, double))
{
    if (err(vec->x, s) || err(vec->y, s) || err(vec->z, s)) return NULL;
    res->x = op(vec->x, s);
    res->y = op(vec->y, s);
    res->z = op(vec->z, s);
    return res;
}

// Sets each element of res to op(corresponding elements of a and b).
inline t_vec3* Vec3_op(t_vec3* res, const t_vec3* a, const t_vec3* b, 
                   double(*op)(double, double)) 
{
    res->x = op(a->x, b->x);
    res->y = op(a->y, b->y);
    res->z = op(a->z, b->z);
    return res;
}

// Sets each element of res to op(corresponding element of vec, s).
inline t_vec3* Vec3_opS(t_vec3* res, const t_vec3* vec, double s, 
                    double(*op)(double, double))
{
    res->x = op(vec->x, s);
    res->y = op(vec->y, s);
    res->z = op(vec->z, s);
    return res;
}

// Sets res to a + b.
t_vec3* Vec3_add(t_vec3* res, const t_vec3* a, const t_vec3* b);

// Sets res to vec + s.
t_vec3* Vec3_addS(t_vec3* res, const t_vec3* vec, double s);

// Sets res to a - b.
t_vec3* Vec3_sub(t_vec3* res, const t_vec3* a, const t_vec3* b);

// Sets res to vec - s.
t_vec3* Vec3_subS(t_vec3* res, const t_vec3* vec, double s);

// Sets res to a * b.
t_vec3* Vec3_mult(t_vec3* res, const t_vec3* a, const t_vec3* b);

// Sets res to vec * s.
t_vec3* Vec3_multS(t_vec3* res, const t_vec3* vec, double s);

// Sets res to a / b.
t_vec3* Vec3_div(t_vec3* res, const t_vec3* a, const t_vec3* b);

// Sets res to vec / s.
t_vec3* Vec3_divS(t_vec3* res, const t_vec3* vec, double s);

// Returns the sum of all elements in the vector.
double Vec3_sum(const t_vec3* vec);

// Returns the dot product of A and B.
double Vec3_dot(const t_vec3* a, const t_vec3* b);

// Returns the magnitude squared of a vector.
double Vec3_magSqr(const t_vec3* vec);

// Returns the magnitude of a vector.
double Vec3_mag(const t_vec3* vec);

// Sets res to the vector normalized.
t_vec3* Vec3_norm(t_vec3* res, const t_vec3* vec);

// Sets res to the cross product;
t_vec3* Vec3_cross(t_vec3* res, const t_vec3* a, const t_vec3* b);

// Prints the vector to the given stream.
int Vec3_fprintln(const t_vec3* vec, FILE* stream);

#endif
