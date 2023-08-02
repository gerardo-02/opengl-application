#ifndef PROPELLER_H
#define PROPELLER_H

#include "blade.h"

class _propeller
{
public:

  void draw_point();

  void draw_line();

  void draw_fill();

  void draw_chess();

private:
  _blade PropellerBlade;
};

#endif // PROPELLER_H
