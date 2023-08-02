#ifndef PLY_OBJECT_H
#define PLY_OBJECT_H

#include <string>
#include <vector>
#include "vertex.h"
#include "object3d.h"

class _ply_object:public _object3D
{
public:
  _ply_object(const string &file_name="./ply_models/beethoven.ply");
};

#endif // PLY_OBJECT_H
