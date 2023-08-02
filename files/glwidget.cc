/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include<QImage>
#include<QImageReader>
#include<QMessageBox>
#include<QGuiApplication>
#include<QDir>
#include<QPushButton>

#include "glwidget.h"
#include "window.h"
#include "common.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONE;break;
  case Qt::Key_4:Object=OBJECT_CYLINDER;break;
  case Qt::Key_5:Object=OBJECT_SPHERE;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_7:Object=HIERARCHICAL_OBJECT;break;
  case Qt::Key_8:Object=CHESS_BOARD;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;Draw_chess=false;break;
  case Qt::Key_F2:Draw_chess=!Draw_chess;Draw_fill=false;break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_Minus:Observer_distance*=1.2;break;
  case Qt::Key_Plus:Observer_distance/=1.2;break;

  case Qt::Key_C:orthographic_projection=false;break;
  case Qt::Key_V:orthographic_projection=true;break;

  case Qt::Key_A:animation=!animation;break;

  case Qt::Key_F1:light_mode=false;
                  texture_mode=false;break;
  case Qt::Key_F3:light_mode=true;
                  smooth_shading=false;
                  texture_mode=false;break;
  case Qt::Key_F4:light_mode=true;
                  smooth_shading=true;
                  texture_mode=false;break;
  case Qt::Key_F5:light_mode=false;
                  texture_mode=true;break;
  case Qt::Key_F6:light_mode=true;
                  smooth_shading=false;
                  texture_mode=true;break;
  case Qt::Key_F7:light_mode=true;
                  smooth_shading=true;
                  texture_mode=true;break;
  case Qt::Key_J:first_light=!first_light;break;
  case Qt::Key_K:second_light=!second_light;break;
  case Qt::Key_M:material=(material+1)%3;break;

  case Qt::Key_Q:propeller_freedom+=180.0;break;
  case Qt::Key_W:propeller_freedom-=180.0;break;
  case Qt::Key_S:tail_freedom+=180.0;break;
  case Qt::Key_D:tail_freedom-=180.0;break;
  case Qt::Key_Z:tail_size_freedom+=0.1;break;
  case Qt::Key_X:tail_size_freedom-=0.1;break;
  case Qt::Key_E:if (propeller_step > 0)
          propeller_step+=0.1;
        else
          propeller_step-=0.1;
        break;
  case Qt::Key_R:if (propeller_step > 0)
          propeller_step-=0.1;
        else
          propeller_step+=0.1;
        break;
  case Qt::Key_T:if (tail_step > 0)
          tail_step+=0.1;
        else
          tail_step-=0.1;
        break;
  case Qt::Key_Y:if (tail_step > 0)
          tail_step-=0.1;
        else
          tail_step+=0.1;
        break;
  case Qt::Key_U:if (tail_size_step > 0)
          tail_size_step+=0.001;
        else
          tail_size_step-=0.001;
        break;
  case Qt::Key_I:if (tail_size_step > 0)
          tail_size_step-=0.001;
        else
          tail_size_step+=0.001;
        break;
  }

  update();
}

void _gl_widget::mouseMoveEvent(QMouseEvent *Mouseevent){

    if (Mouseevent->pos().x() > position[0])
        Observer_angle_y+=ANGLE_STEP;
    else if (Mouseevent->pos().x() < position[0])
        Observer_angle_y-=ANGLE_STEP;

    if (Mouseevent->pos().y() > position[1])
        Observer_angle_x+=ANGLE_STEP;
    else if (Mouseevent->pos().y() < position[1])
        Observer_angle_x-=ANGLE_STEP;

    position[0] = Mouseevent->pos().x();
    position[1] = Mouseevent->pos().y();
}

void _gl_widget::wheelEvent(QWheelEvent *Wheelevent){
    if (Wheelevent->angleDelta().y() > 0)
        Observer_distance*=1.2;
    else if (Wheelevent->angleDelta().y() < 0)
        Observer_distance/=1.2;
}

//
// PICK FUNCTION
//
void _gl_widget::mouseReleaseEvent(QMouseEvent *Mouseevent){
    if (Mouseevent->button() == Qt::RightButton){
        GLfloat color[3];
        int x = Mouseevent->x() + 10;
        int y = this->size().height() - Mouseevent->y();

        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);

        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.SetSelectedTriangle(color);break;
        case OBJECT_CUBE:Cube.SetSelectedTriangle(color);break;
        case OBJECT_CONE:Cone.SetSelectedTriangle(color);break;
        case OBJECT_CYLINDER:Cylinder.SetSelectedTriangle(color);break;
        case OBJECT_SPHERE:Sphere.SetSelectedTriangle(color);break;
        case OBJECT_PLY:ply_object.SetSelectedTriangle(color);break;
        case CHESS_BOARD:chess_board.SetSelectedTriangle(color);break;
        default:break;
        }
    }
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (orthographic_projection){

      glOrtho(-0.6*Observer_distance, 0.6*Observer_distance, -0.6*Observer_distance, 0.6*Observer_distance,FRONT_PLANE_ORTHOGRAPHIC,BACK_PLANE_ORTHOGRAPHIC);
  }
  else{
      // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
      // Front_plane>0  Back_plane>PlanoDelantero)
      glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
  }

}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (material == 0){
      GLfloat first_material_diffuse[] = {0.0, 0.0, 1.0, 0.8};
      GLfloat first_material_specular[] {0.0, 0.0, 0.0, 0.5};
      GLfloat first_material_ambient[] = {0.0, 0.0, 1.0, 0.25};

      glMaterialfv(GL_FRONT, GL_DIFFUSE, first_material_diffuse);
      glMaterialfv(GL_FRONT, GL_SPECULAR, first_material_specular);
      glMaterialfv(GL_FRONT, GL_AMBIENT, first_material_ambient);
  }
  else if (material == 1){
      GLfloat second_material_diffuse[] = {0.0, 1.0, 1.0, 0.8};
      GLfloat second_material_specular[] {0.0, 0.0, 0.0, 0.7};
      GLfloat second_material_ambient[] = {0.0, 1.0, 1.0, 0.2};

      glMaterialfv(GL_FRONT, GL_DIFFUSE, second_material_diffuse);
      glMaterialfv(GL_FRONT, GL_SPECULAR, second_material_specular);
      glMaterialfv(GL_FRONT, GL_AMBIENT, second_material_ambient);
  }
  else if (material == 2){
      GLfloat third_material_diffuse[] = {1.0, 0.84, 0.0, 0.8};
      GLfloat third_material_specular[] {0.0, 0.0, 0.0, 0.15};
      GLfloat third_material_ambient[] = {1.0, 0.84, 0.0, 0.6};

      glMaterialfv(GL_FRONT, GL_DIFFUSE, third_material_diffuse);
      glMaterialfv(GL_FRONT, GL_SPECULAR, third_material_specular);
      glMaterialfv(GL_FRONT, GL_AMBIENT, third_material_ambient);
  }

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_PLY:ply_object.draw_point();break;
    case HIERARCHICAL_OBJECT:hierarchical_object.draw_point();break;
    case CHESS_BOARD:chess_board.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_PLY:ply_object.draw_line();break;
    case HIERARCHICAL_OBJECT:hierarchical_object.draw_line();break;
    case CHESS_BOARD:chess_board.draw_line();break;
    default:break;
    }
  }

  if (Draw_fill){
      if (!texture_mode){
          glColor3fv((GLfloat *) &BLUE);
          switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill(light_mode, first_light, second_light, smooth_shading);break;
          case OBJECT_CUBE:Cube.draw_fill(light_mode, first_light, second_light, smooth_shading);break;
          case OBJECT_CONE:Cone.draw_fill(light_mode, first_light, second_light,  smooth_shading);break;
          case OBJECT_CYLINDER:Cylinder.draw_fill(light_mode, first_light, second_light,  smooth_shading);break;
          case OBJECT_SPHERE:Sphere.draw_fill(light_mode, first_light, second_light,  smooth_shading);break;
          case OBJECT_PLY:ply_object.draw_fill(light_mode, first_light, second_light,  smooth_shading);break;
          case HIERARCHICAL_OBJECT:hierarchical_object.draw_fill();break;
          case CHESS_BOARD:chess_board.draw_fill(light_mode, first_light, second_light,  smooth_shading);break;
          default:break;
          }
      }
      else{
          switch (Object){
          case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill(light_mode, first_light,second_light,  smooth_shading, Image);break;
          case OBJECT_CUBE:Cube.draw_fill(light_mode, first_light, second_light, smooth_shading, Image);break;
          case OBJECT_CONE:Cone.draw_fill(light_mode, first_light, second_light, smooth_shading, Image);break;
          case OBJECT_CYLINDER:Cylinder.draw_fill(light_mode, first_light, second_light,  smooth_shading, Image);break;
          case OBJECT_SPHERE:Sphere.draw_fill(light_mode, first_light, second_light, smooth_shading, Image);break;
          case OBJECT_PLY:ply_object.draw_fill(light_mode, first_light, second_light, smooth_shading, Image);break;
          case HIERARCHICAL_OBJECT:hierarchical_object.draw_fill();break;
          case CHESS_BOARD:chess_board.draw_fill(light_mode, first_light, second_light, smooth_shading, Image);break;
          default:break;
          }
      }

  }

  if (Draw_chess){
    switch (Object){
    glColor3fv((GLfloat *) &RED);
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_CONE:Cone.draw_chess();break;
    case OBJECT_CYLINDER:Cylinder.draw_chess();break;
    case OBJECT_SPHERE:Sphere.draw_chess();break;
    case OBJECT_PLY:ply_object.draw_chess();break;
    case HIERARCHICAL_OBJECT:hierarchical_object.draw_chess();break;
    case CHESS_BOARD:chess_board.draw_chess();break;
    default:break;
    }
  }

  if (Draw_selection){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_selection();break;
    case OBJECT_CUBE:Cube.draw_selection();break;
    case OBJECT_CONE:Cone.draw_selection();break;
    case OBJECT_CYLINDER:Cylinder.draw_selection();break;
    case OBJECT_SPHERE:Sphere.draw_selection();break;
    case OBJECT_PLY:ply_object.draw_selection();break;
    //case HIERARCHICAL_OBJECT:hierarchical_object.draw_selection();break;
    case CHESS_BOARD:chess_board.draw_selection();break;
    default:break;
    }
  }
}

void _gl_widget::idle_event(){

    if (animation){

        if (propeller_angle > propeller_freedom || propeller_angle < -propeller_freedom)
            propeller_step = propeller_step * -1.0;

        change_propeller_angle(propeller_step);

        if (tail_angle > tail_freedom || tail_angle < -tail_freedom)
            tail_step = tail_step * -1.0;

        change_tail_angle(tail_step);

        if (tail_size > tail_size_freedom || tail_size < -tail_size_freedom)
            tail_size_step = tail_size_step * -1.0;
        change_tail_size(tail_size_step);

        if (second_light){
            GLfloat second_light_position[4] = {0.0, 3.0, 3.0, 1.0};
            //glGetLightfv(GL_LIGHT1, GL_POSITION, second_light_position);

            second_light_position[0] = 3.0 * cos(second_light_angle);
            second_light_position[2] = -3.0 * sin(second_light_angle);
            glLightfv(GL_LIGHT1, GL_POSITION, second_light_position);

            second_light_angle += second_light_angle_step;
        }
    }

    update();
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);

  glEnable(GL_DEPTH_TEST);

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=true;
  Draw_line=false;
  Draw_fill=false;
  Draw_chess=false;
  Draw_selection=false;

  animation = true;
  propeller_step = 2.0;
  tail_step = 2.0;
  tail_size_step = 0.02;

  propeller_freedom = 720.0;
  tail_freedom = 720.0;
  tail_size_freedom = 2.0;

  light_mode = false;
  texture_mode = false;
  smooth_shading = true;
  first_light = true;
  second_light = false;
  second_light_angle = 0;
  second_light_angle_step = 0.0628;
  position[0] = 0;
  position[1] = 0;

  orthographic_projection = false;

  material = 0;

  GLfloat first_light_position[] = {1.0, 1.0, 1.0, 0.0};
  glLightfv(GL_LIGHT0, GL_POSITION, first_light_position);

  GLfloat second_light_position[] = {0.0, 3.0, 3.0, 1.0};
  GLfloat second_light_diffuse[] = {1.0, 0.0, 1.0, 1.0};
  GLfloat second_light_specular[] = {1.0, 0.0, 1.0, 1.0};
  GLfloat second_light_ambient[] = {1.0, 0.0, 1.0, 0.2};
  glLightfv(GL_LIGHT1, GL_POSITION, second_light_position);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, second_light_diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, second_light_specular);
  glLightfv(GL_LIGHT1, GL_AMBIENT, second_light_ambient);

  GLfloat first_material_diffuse[] = {0.0, 0.0, 1.0, 0.8};
  GLfloat first_material_specular[] {0.5, 0.5, 0.5, 1.0};
  GLfloat first_material_ambient[] = {0.0, 0.0, 1.0, 0.25};

  glMaterialfv(GL_FRONT, GL_DIFFUSE, first_material_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, first_material_specular);
  glMaterialfv(GL_FRONT, GL_AMBIENT, first_material_ambient);


  // Code for reading an image
  QString File_name("./texturas/dia_8192.jpg");
  QImageReader Reader(File_name);
  Reader.setAutoTransform(true);
  Image = Reader.read();
  if (Image.isNull()) {
    QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
    exit(-1);
  }
  Image=Image.mirrored();
  Image=Image.convertToFormat(QImage::Format_RGB888);

  // Code to control the application of the texture
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}
