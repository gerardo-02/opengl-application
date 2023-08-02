#include "propeller.h"

void _propeller::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    PropellerBlade.draw_point();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0, 1, 0);
    PropellerBlade.draw_point();
    glPopMatrix();

}

void _propeller::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    PropellerBlade.draw_line();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0, 1, 0);
    PropellerBlade.draw_line();
    glPopMatrix();

}

void _propeller::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    PropellerBlade.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0, 1, 0);
    PropellerBlade.draw_fill();
    glPopMatrix();

}

void _propeller::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    PropellerBlade.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0, 0, 1, 0);
    PropellerBlade.draw_chess();
    glPopMatrix();


}
