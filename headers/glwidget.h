/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "ply_object.h"
#include "hierarchical_object.h"
#include "chess_board.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float FRONT_PLANE_ORTHOGRAPHIC=0;
  const float BACK_PLANE_ORTHOGRAPHIC=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_PLY, OBJECT_CONE, OBJECT_CYLINDER, OBJECT_SPHERE, HIERARCHICAL_OBJECT, CHESS_BOARD} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();
  void idle_event();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
  void mouseMoveEvent(QMouseEvent *Mouseevent) Q_DECL_OVERRIDE;
  void wheelEvent(QWheelEvent *Wheelevent) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QMouseEvent *Mouseevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _cone Cone;
  _cylinder Cylinder;
  _sphere Sphere;
  _ply_object ply_object;
  _hierarchical_object hierarchical_object;
  _chess_board chess_board;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;
  bool Draw_selection;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  bool animation;
  float propeller_step;
  float tail_step;
  float tail_size_step;

  float propeller_freedom;
  float tail_freedom;
  float tail_size_freedom;

  bool light_mode;
  bool texture_mode;
  bool smooth_shading;
  bool first_light;
  bool second_light;
  float second_light_angle;
  float second_light_angle_step;
  int material;

  QImage Image;
  int position[2];
  bool orthographic_projection;
};

#endif
