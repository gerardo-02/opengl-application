#include "body.h"
using namespace _colors_ne;

void _body::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.0, 0.0);
    BodyCone.draw_point();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    BodyCylinder.draw_point();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glTranslatef(-0.5, 0.0, 0.0);
    BodySphere.draw_point();
    glPopMatrix();
}

void _body::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.0, 0.0);
    BodyCone.draw_line();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    BodyCylinder.draw_line();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glTranslatef(-0.5, 0.0, 0.0);
    BodySphere.draw_line();
    glPopMatrix();
}

void _body::draw_fill(){
    GLfloat const dark_green[] = {0.16, 0.55, 0.19, 1.0};
    GLfloat const light_blue[] = {0.57, 0.91, 0.94, 1.0};

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.0, 0.0);
    glColor3fv( dark_green);
    BodyCone.draw_fill(false, false, false, false);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    BodyCylinder.draw_fill(false, false, false, false);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glTranslatef(-0.5, 0.0, 0.0);
    glColor3fv(light_blue);
    BodySphere.draw_fill(false, false, false, false);
    glPopMatrix();
}

void _body::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 1.0, 0.0);
    BodyCone.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    BodyCylinder.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, 0.7, 0.5);
    glTranslatef(-0.5, 0.0, 0.0);
    BodySphere.draw_chess();
    glPopMatrix();
}
