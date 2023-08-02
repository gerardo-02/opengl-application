#ifndef SPHERE_H
#define SPHERE_H

#include "object3d.h"

class _sphere:public _object3D
{
public:
  _sphere(float Size=1.0, int n = 100, int redondez = 30);
};

#endif // SPHERE_H
