#include "revolution_object.h"
#include "revolution_utils.h"


_revolution_object::_revolution_object(vector<_vertex3f> Profile, int n)
{
    CreateRevolutionObject(Vertices, Triangles, Profile, n);
    CalculateNormals();
    selected_triangle=-1;
}
