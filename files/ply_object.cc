#include "ply_object.h"
#include "file_ply_stl.h"

using namespace _colors_ne;



_ply_object::_ply_object(const string &file_name)
{

  vector<float> Coordinates(0);
  vector<unsigned int> Positions(0);


  _file_ply reader;
  reader.open(file_name);
  //reader.open("E:\IG\P2\ply_models\beethoven.ply");

  reader.read(Coordinates, Positions);

  Vertices.resize(Coordinates.size() / 3);

  int Pos = 0;
  for (int i=0; i<Vertices.size(); i++){
      Vertices[i]=_vertex3f(Coordinates[Pos], Coordinates[Pos + 1], Coordinates[Pos + 2]);
      Pos += 3;
  }

  Triangles.resize(Positions.size() / 3);

  Pos = 0;
    for (int i=0; i<Triangles.size(); i++){
        Triangles[i]=_vertex3ui(Positions[Pos], Positions[Pos + 1], Positions[Pos + 2]);
        Pos += 3;
    }

    reader.close();

    CalculateNormals();
    selected_triangle = -1;
}
