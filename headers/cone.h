#ifndef CONE_H
#define CONE_H

#include "object3d.h"

class _cone:public _object3D
{
public:
  _cone(float Size=1.0, int n = 100);
};

#endif // CONE_H
