#include "skid.h"

void _skid::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.15, 0.05, 0.05);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(8.0, 0.0, 8.0);
    SkidCylinder.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_point();
    glPopMatrix();

}

void _skid::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.15, 0.05, 0.05);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(8.0, 0.0, 8.0);
    SkidCylinder.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_line();
    glPopMatrix();
}

void _skid::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.15, 0.05, 0.05);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(8.0, 0.0, 8.0);
    SkidCylinder.draw_fill(false, false, false, false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_fill(false, false, false, false);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_fill(false, false, false, false);
    glPopMatrix();
}

void _skid::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(1.15, 0.05, 0.05);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(8.0, 0.0, 8.0);
    SkidCylinder.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, -0.25, 0.25);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    glScalef(0.05, 0.4, 0.05);
    SkidCylinder.draw_chess();
    glPopMatrix();
}
