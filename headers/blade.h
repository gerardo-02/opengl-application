#ifndef BLADE_H
#define BLADE_H

#include "cube.h"

class _blade
{
public:

  void draw_point();

  void draw_line();

  void draw_fill();

  void draw_chess();

private:
  _cube BladeCube;
};

#endif // BLADE_H
