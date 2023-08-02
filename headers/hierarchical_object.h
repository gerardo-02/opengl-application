#ifndef HIERARCHICAL_OBJECT_H
#define HIERARCHICAL_OBJECT_H

#include "body.h"
#include "tail_rotor.h"
#include "main_propeller.h"
#include "skid.h"

class _hierarchical_object
{
public:

  void draw_point();

  void draw_line();

  void draw_fill();

  void draw_chess();

private:
  _body Body;
  _tail_rotor TailRotor;
  _main_propeller MainPropeller;
  _skid Skid;

};

#endif // HIERARCHICAL_OBJECT_H
