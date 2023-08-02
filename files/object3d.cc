/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include "object3d.h"
#include "math.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{


    for (int i=0; i<Triangles.size(); i++){
        glBegin(GL_LINE_LOOP);
            for (int j=0; j< 3; j++){
                 glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);
            }
        glEnd();
    }

}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill(bool light_mode, bool first_light, bool second_light, bool smooth_shading)
{
    bool light = glIsEnabled(GL_LIGHTING);
    bool light1 = glIsEnabled(GL_LIGHT0);
    bool textures = glIsEnabled(GL_TEXTURE_2D);

    if (light_mode){
        draw_light(smooth_shading, first_light, second_light);
    }
    else{
        glDisable(GL_LIGHTING);
        glBegin(GL_TRIANGLES);
            for (int i=0; i<Triangles.size(); i++){
                if (i != selected_triangle){
                    for (int j=0; j< 3; j++){
                         glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);
                    }
                }
            }

        glEnd();
    }

    if (selected_triangle > -1){
        glColor3fv((GLfloat *) &YEllOW);
        glBegin(GL_TRIANGLES);
            for (int j=0; j< 3; j++){
                 glVertex3fv((GLfloat *) &Vertices[Triangles[selected_triangle][j]]);
            }

        glEnd();
    }

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill(bool light_mode, bool first_light, bool second_light, bool smooth_shading, QImage Image)
{

    glEnable(GL_TEXTURE_2D);
    // Code to pass the image to OpenGL to form a texture 2D
    glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());

    glBegin(GL_TRIANGLES);
        glDisable(GL_DEPTH_TEST);
        glNormal3f(0.0, 0.0, 1.0);
        glTexCoord2f(0.0,0.0);
        glVertex3fv((GLfloat *) &Vertices[0]);
        glTexCoord2f(1.0,0.0);
        glVertex3fv((GLfloat *) &Vertices[1]);
        glTexCoord2f(0.0,1.0);
        glVertex3fv((GLfloat *) &Vertices[2]);
        glTexCoord2f(1.0,0.0);
        glVertex3fv((GLfloat *) &Vertices[1]);
        glTexCoord2f(0.0,1.0);
        glVertex3fv((GLfloat *) &Vertices[2]);
        glTexCoord2f(1.0,1.0);
        glVertex3fv((GLfloat *) &Vertices[3]);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

    if (light_mode){
        draw_light(smooth_shading, first_light, second_light);
    }

    if (selected_triangle > -1){
        glColor3fv((GLfloat *) &YEllOW);
        glBegin(GL_TRIANGLES);
            for (int j=0; j< 3; j++){
                 glVertex3fv((GLfloat *) &Vertices[Triangles[selected_triangle][j]]);
            }

        glEnd();
    }

}

void _object3D::draw_light(bool smooth_shading, bool first_light, bool second_light ){

    glEnable(GL_LIGHTING);

    if (first_light)
        glEnable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT0);

    if (second_light)
        glEnable(GL_LIGHT1);
    else
        glDisable(GL_LIGHT1);

    if (!smooth_shading){
        glBegin(GL_TRIANGLES);
            for (int i=0; i<Triangles.size(); i++){
                glNormal3f(TriangleNormals[i][0], TriangleNormals[i][1], TriangleNormals[i][2]);
                for (int j=0; j< 3; j++){
                     glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);
                }

            }

        glEnd();
    }
    else{
        glBegin(GL_TRIANGLES);
            for (int i=0; i<Triangles.size(); i++){
                for (int j=0; j< 3; j++){
                    glNormal3f(VerticesNormals[Triangles[i][j]][0], VerticesNormals[Triangles[i][j]][1], VerticesNormals[Triangles[i][j]][2]);
                    glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);
                }

            }

        glEnd();

    }
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glColor3fv((GLfloat *) &RED);
    bool x = true;
    glBegin(GL_TRIANGLES);

        for (int i=0; i<Triangles.size(); i++){
            for (int j=0; j< 3; j++){
                 glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);

            }
            if (x){

                glColor3fv((GLfloat *) &GREEN);
                x = false;
            }
            else{
                glColor3fv((GLfloat *) &RED);
                x = true;
            }
        }


    glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_selection()
{
    GLfloat color[3];
    glBegin(GL_TRIANGLES);
        for (int i=0; i<Triangles.size(); i++){
            if (i != selected_triangle){
                int_to_color(i, color);
                glColor3fv(color);
                for (int j=0; j< 3; j++){
                     glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);

                }
            }
        }
        if (selected_triangle > -1){
            glColor3fv((GLfloat *) &YEllOW);
                for (int j=0; j< 3; j++){
                     glVertex3fv((GLfloat *) &Vertices[Triangles[selected_triangle][j]]);
                }
        }

    glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::CalculateNormals()
{
    TriangleNormals.clear();

    _vertex3f center(0.0, 0.0, 0.0);
    for (int i=0; i<Vertices.size(); i++){
        center += Vertices[i];
    }
    center /= Vertices.size();

    _vertex3f vec1, vec2, normal, to_center;
    for (int i=0; i<Triangles.size(); i++){
        vec1 = Vertices [Triangles[i][1]] - Vertices [Triangles[i][0]];
        vec2 = Vertices [Triangles[i][2]] - Vertices [Triangles[i][0]];

        normal[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
        normal[1] = vec1[0]*vec2[2] - vec1[2]*vec2[0];
        normal[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];

        NormalizeVector(normal);

        to_center = center - Vertices [Triangles[i][1]];
        NormalizeVector(to_center);

        if (cosine (normal, to_center) > 0)
            normal *= -1;

        TriangleNormals.push_back(normal);
        //TriangleNormals[i] = normal;
    }

    VerticesNormals.clear();

    int triangulos_en_este_vertice = 0;
    for (int i=0; i<Vertices.size(); i++){
        triangulos_en_este_vertice = 0;
        normal[0] = 0.0;
        normal[1] = 0.0;
        normal[2] = 0.0;

        for (int j=0; j<Triangles.size(); j++){
            if (Triangles[j][0] == i || Triangles[j][1] == i || Triangles[j][2] == i){
                triangulos_en_este_vertice++;
                normal += TriangleNormals[j];

            }
        }

        normal /= triangulos_en_este_vertice;

        NormalizeVector(normal);
        //VerticesNormals[i] = normal;
        VerticesNormals.push_back(normal);

    }
}

void _object3D::NormalizeVector(_vertex3f &vec){
    float mod = sqrt( vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
    vec[0] = vec[0]/mod;
    vec[1] = vec[1]/mod;
    vec[2] = vec[2]/mod;
}

float _object3D::cosine(_vertex3f vec1, const GLfloat *vec2){
    float numerador = vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];
    float denominador = sqrt((vec1[0]*vec1[0]) + (vec1[1]*vec1[1]) + (vec1[2]*vec1[2])) *
            sqrt((vec2[0]*vec2[0]) + (vec2[1]*vec2[1]) + (vec2[2]*vec2[2]));
    return numerador / denominador;
}

float _object3D::cosine(_vertex3f vec1, _vertex3f vec2){
    float numerador = vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];
    float denominador = sqrt((vec1[0]*vec1[0]) + (vec1[1]*vec1[1]) + (vec1[2]*vec1[2])) *
            sqrt((vec2[0]*vec2[0]) + (vec2[1]*vec2[1]) + (vec2[2]*vec2[2]));
    return numerador / denominador;
}

int _object3D::GetSelectedTriangle(){
    return selected_triangle;
}

void _object3D::SetSelectedTriangle(const GLfloat *color){
    color_to_int(selected_triangle, color);
    if (selected_triangle >= Triangles.size())
        selected_triangle = -1;
}

void _object3D::int_to_color(int n, GLfloat *color){
    int r, g, b;
    float rf, gf, bf;
    r = (n & 0x00FF0000) >> 16;
    g = (n & 0x0000FF00) >> 8;
    b = (n & 0x000000FF);
    rf = (float) r;
    gf = (float) g;
    bf = (float) b;
    color[0] = rf/255.0;
    color[1] = gf/255.0;
    color[2] = bf/255.0;

}

void _object3D::color_to_int(int &n, const GLfloat *color){
    int r, g, b;
    n=0;
    r = color[0] * 255;
    g = color[1] * 255;
    b = color[2] * 255;

    n = (r << 16 | g << 8 | b);

}
