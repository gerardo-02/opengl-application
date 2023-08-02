#include "sphere.h"
#include "revolution_utils.h"

_sphere::_sphere(float Size, int n, int redondez){
    vector<_vertex3f> Profile;

    float angle = M_PI / redondez;
    int Pos = 0;
    _vertex3f actual;
    float R = Size/2;

    for (int i=0; i<=redondez; i++){

        actual[0] = -R * sin(angle * i);
        actual[1] = R * cos(angle*i);
        actual[2] = 0;

        Profile.push_back(actual);

    }

    CreateRevolutionObject(Vertices, Triangles, Profile, n);
    CalculateNormals();
    selected_triangle=-1;
}
