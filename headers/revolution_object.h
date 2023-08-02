#ifndef REVOLUTION_OBJECT_H
#define REVOLUTION_OBJECT_H

#include <vector>
#include "vertex.h"
#include "object3d.h"

class _revolution_object:public _object3D
{
public:
  _revolution_object(vector<_vertex3f> Profile, int n);

};


#endif // REVOLUTION_OBJECT_H
