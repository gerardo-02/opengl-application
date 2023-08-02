HEADERS += \
  blade.h \
  body.h \
  chess_board.h \
  colors.h \
  basic_object3d.h \
  common.h \
  cone.h \
  cylinder.h \
  hierarchical_object.h \
  main_propeller.h \
  object3d.h \
  axis.h \
  ply_object.h \
  propeller.h \
  revolution_object.h \
  revolution_ply_object.h \
  revolution_utils.h \
  skid.h \
  sphere.h \
  tail_rotor.h \
  tetrahedron.h \
  cube.h \
  glwidget.h \
  window.h \
  file_ply_stl.h \
  ply_object.h \
  revolution_object.h \
  cone.h \
  cylinder.h \
  sphere.h \
  revolution_ply_object.h

SOURCES += \
  basic_object3d.cc \
    blade.cc \
    body.cc \
    chess_board.cc \
    common.cc \
    hierarchical_object.cc \
    main_propeller.cc \
  object3d.cc \
  axis.cc \
    propeller.cc \
    revolution_utils.cc \
    skid.cc \
    tail_rotor.cc \
  tetrahedron.cc \
  cube.cc \
  main.cc \
  glwidget.cc \
  window.cc \
  file_ply_stl.cc \
  ply_object.cc \
  revolution_object.cc \
  cone.cc \
  cylinder.cc \
  sphere.cc \
  revolution_ply_object.cc

# LIBS += -lopengl32
LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
# QT += core gui opengl
QT += openglwidgets
# QT += widgets opengl
