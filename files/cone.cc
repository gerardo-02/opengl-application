#include "cone.h"
#include "revolution_utils.h"

_cone::_cone(float Size, int n){
    vector<_vertex3f> Profile;
    Profile.push_back(_vertex3f(0, -Size/2, 0));
    Profile.push_back(_vertex3f(Size/2, -Size/2, 0));
    Profile.push_back(_vertex3f(0, Size/2, 0));

    CreateRevolutionObject(Vertices, Triangles, Profile, n);
    CalculateNormals();
    selected_triangle=-1;
}
