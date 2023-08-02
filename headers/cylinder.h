#ifndef CYLINDER_H
#define CYLINDER_H

#include "object3d.h"

class _cylinder:public _object3D
{
public:
  _cylinder(float Size=1.0, int n = 100);
};

#endif // CYLINDER_H
