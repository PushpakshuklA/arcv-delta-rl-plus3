#ifndef VCQBF_H
#define VCQBF_H

#include "vec2.h"
#include "vec4.h"

// Voronoi-Centroid + Quad-Barrier Function
void    vcqbf_init(void);
vec4_t  vcqbf_project(const vec2_t *pos, const vec4_t *desired);

#endif // VCQBF_H
