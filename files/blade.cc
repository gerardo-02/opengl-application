#include "blade.h"

void _blade::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2.0, 0.025, 0.1);
    BladeCube.draw_point();
    glPopMatrix();
}

void _blade::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2.0, 0.025, 0.1);
    BladeCube.draw_line();
    glPopMatrix();
}

void _blade::draw_fill(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2.0, 0.025, 0.1);
    BladeCube.draw_fill(false, false, false, false);
    glPopMatrix();

}

void _blade::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(2.0, 0.025, 0.1);
    BladeCube.draw_chess();
    glPopMatrix();

}
