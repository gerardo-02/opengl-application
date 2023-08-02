#ifndef TAIL_ROTOR_H
#define TAIL_ROTOR_H

#include "propeller.h"
#include "cylinder.h"

class _tail_rotor
{
public:

  void draw_point();

  void draw_line();

  void draw_fill();

  void draw_chess();

private:
  _propeller TailRotorPropeller;
  _cylinder TailRotorCylinder;
};

#endif // TAIL_ROTOR_H
