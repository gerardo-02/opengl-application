#include "tail_rotor.h"
#include "common.h"

void _tail_rotor::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.15);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.25, 0.25, 0.25);

    glRotatef(tail_angle, 0, 1, 0);
    glScalef(tail_size, tail_size, tail_size);
    TailRotorPropeller.draw_point();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.05);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.05, 0.25, 0.05);
    TailRotorCylinder.draw_point();
    glPopMatrix();
}

void _tail_rotor::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.15);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.25, 0.25, 0.25);

    glRotatef(tail_angle, 0, 1, 0);
    glScalef(tail_size, tail_size, tail_size);
    TailRotorPropeller.draw_line();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.05);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.05, 0.25, 0.05);
    TailRotorCylinder.draw_line();
    glPopMatrix();
}

void _tail_rotor::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.15);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.25, 0.25, 0.25);

    glRotatef(tail_angle, 0, 1, 0);
    glScalef(tail_size, tail_size, tail_size);
    TailRotorPropeller.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.05);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.05, 0.25, 0.05);
    TailRotorCylinder.draw_fill(false, false, false, false);
    glPopMatrix();

}

void _tail_rotor::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.15);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.25, 0.25, 0.25);

    glRotatef(tail_angle, 0, 1, 0);
    glScalef(tail_size, tail_size, tail_size);
    TailRotorPropeller.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.4, 0.0, 0.05);
    glRotatef(90.0, 1, 0, 0);
    glScalef(0.05, 0.25, 0.05);
    TailRotorCylinder.draw_chess();
    glPopMatrix();

}
