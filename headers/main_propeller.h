#ifndef MAIN_PROPELLER_H
#define MAIN_PROPELLER_H

#include "propeller.h"
#include "cylinder.h"

class _main_propeller
{
public:

  void draw_point();

  void draw_line();

  void draw_fill();

  void draw_chess();

private:
  _propeller MainPropellerPropeller;
  _cylinder MainPropellerCylinder;
};

#endif // MAIN_PROPELLER_H
