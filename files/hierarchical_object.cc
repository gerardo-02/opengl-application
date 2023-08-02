#include "hierarchical_object.h"
#include "common.h"

using namespace _colors_ne;

void _hierarchical_object::draw_point(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body.draw_point();
    glPopMatrix();

    glPushMatrix();
    TailRotor.draw_point();
    glPopMatrix();

    glPushMatrix();
    glRotatef(propeller_angle, 0, 1, 0);
    MainPropeller.draw_point();
    glPopMatrix();

    glPushMatrix();
    Skid.draw_point();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180.0, 0, 1, 0);
    Skid.draw_point();
    glPopMatrix();

}

void _hierarchical_object::draw_line(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body.draw_line();
    glPopMatrix();

    glPushMatrix();
    TailRotor.draw_line();
    glPopMatrix();

    glPushMatrix();
    glRotatef(propeller_angle, 0, 1, 0);
    MainPropeller.draw_line();
    glPopMatrix();

    glPushMatrix();
    Skid.draw_line();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180.0, 0, 1, 0);
    Skid.draw_line();
    glPopMatrix();

}

void _hierarchical_object::draw_fill(){
    GLfloat const dark_grey[] = {0.3, 0.3, 0.3, 1.0};

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glColor3fv(dark_grey);
    TailRotor.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glRotatef(propeller_angle, 0, 1, 0);
    MainPropeller.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glColor3fv((float *) &BLACK);
    Skid.draw_fill();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180.0, 0, 1, 0);
    Skid.draw_fill();
    glPopMatrix();

}

void _hierarchical_object::draw_chess(){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    Body.draw_chess();
    glPopMatrix();

    glPushMatrix();
    TailRotor.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glRotatef(propeller_angle, 0, 1, 0);
    MainPropeller.draw_chess();
    glPopMatrix();

    glPushMatrix();
    Skid.draw_chess();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180.0, 0, 1, 0);
    Skid.draw_chess();
    glPopMatrix();

}

/*_hierarchical_object::_hierarchical_object(float Size=1.0){
    float scalation[4][4] = {{Size, 0, 0, 0}, {0, Size, 0, 0}, {0, 0, Size, 0}, {0, 0, 0, 1}};
    float traslation [4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    float rotationX[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    float rotationY[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    float rotationZ[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    float transformation[4][4] = {0};
    float aux[4][4] = {0};
    float vertex[4] = {0};
    float prime_vertex[4] = {0};

    //multiply_matrix(scalation, traslation, transformation);

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++){
                aux[i][j] += scalation[i][k] * traslation[k][j];
            }

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++){
                transformation[i][j] += aux[i][k] * rotationX[k][j];
            }

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            aux[i][j] = 0;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++){
                aux[i][j] += transformation[i][k] * rotationY[k][j];
            }

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            transformation[i][j] = 0;

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++){
                transformation[i][j] += aux[i][k] * rotationZ[k][j];
            }

    for (int i=0; i<Vertices.size(); i++){
        vertex[0] = Vertices[i][0];
        vertex[1] = Vertices[i][1];
        vertex[2] = Vertices[i][2];
        vertex[3] = 1;

        for (int j=0; j<4; j++)
            prime_vertex[j] = 0;

        for (int j=0; j < 4; j++){
            for (int k=0; k < 4; k++){
                prime_vertex[j] += vertex[k] * transformation[j][k];
            }
        }

        Vertices[i][0] = prime_vertex[0];
        Vertices[i][1] = prime_vertex[1];
        Vertices[i][2] = prime_vertex[2];

    }
}*/
