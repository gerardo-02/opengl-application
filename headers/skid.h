#ifndef SKID_H
#define SKID_H

#include "cylinder.h"

class _skid
{
public:

  void draw_point();

  void draw_line();

  void draw_fill();

  void draw_chess();

private:
  _cylinder SkidCylinder;
};

#endif // SKID_H
