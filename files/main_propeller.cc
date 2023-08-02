#include "main_propeller.h"

void _main_propeller::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.0);
    MainPropellerPropeller.draw_point();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.15, 0.15, 0.15);
    glTranslatef(0.0, 2.5, 0.0);
    MainPropellerCylinder.draw_point();
    glPopMatrix();
}

void _main_propeller::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.0);
    MainPropellerPropeller.draw_line();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.15, 0.15, 0.15);
    glTranslatef(0.0, 2.5, 0.0);
    MainPropellerCylinder.draw_line();
    glPopMatrix();
}

void _main_propeller::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.0);
    MainPropellerPropeller.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.15, 0.15, 0.15);
    glTranslatef(0.0, 2.5, 0.0);
    MainPropellerCylinder.draw_fill(false, false, false, false);
    glPopMatrix();

}

void _main_propeller::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.0);
    MainPropellerPropeller.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.15, 0.15, 0.15);
    glTranslatef(0.0, 2.5, 0.0);
    MainPropellerCylinder.draw_chess();
    glPopMatrix();

}
