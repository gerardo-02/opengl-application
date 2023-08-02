/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include<QImage>
#include "basic_object3d.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> TriangleNormals;
  vector<_vertex3f> VerticesNormals;

  void draw_line();
  void draw_fill(bool light_mode, bool first_light, bool second_light, bool smooth_shading);
  void draw_fill(bool light_mode, bool first_light, bool second_light, bool smooth_shading, QImage Image);
  void draw_chess();
  void draw_selection();
  int GetSelectedTriangle();
  void SetSelectedTriangle(const GLfloat *color);

  private:
  void NormalizeVector(_vertex3f &vec);
  float cosine(_vertex3f vec1, const GLfloat *vec2);
  float cosine(_vertex3f vec1, _vertex3f vec2);
  void draw_light(bool smooth_shading, bool first_light, bool second_light);
  void int_to_color(int n, GLfloat *color);
  void color_to_int(int &n, const GLfloat *color);
  protected:
  void CalculateNormals();
  int selected_triangle;

};

#endif // OBJECT3D_H
