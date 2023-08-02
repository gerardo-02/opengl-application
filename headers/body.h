#ifndef BODY_H
#define BODY_H

#include "cylinder.h"
#include "cone.h"
#include "sphere.h"

class _body
{
public:
  //_body2(float Size=1.0, int n = 100);

  void draw_point();

  void draw_line();

  void draw_fill();

  void draw_chess();

private:
  _cone BodyCone;
  _cylinder BodyCylinder;
  _sphere BodySphere;
};

#endif // BODY_H
