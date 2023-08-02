#include"chess_board.h"

_chess_board::_chess_board(float SizeX, float SizeY){
    Vertices.resize(4);

    Vertices[0]=_vertex3f(-SizeX/2,-SizeY/2,0.0);
    Vertices[1]=_vertex3f(SizeX/2,-SizeY/2,0.0);
    Vertices[2]=_vertex3f(-SizeX/2,SizeY/2,0.0);
    Vertices[3]=_vertex3f(SizeX/2,SizeY/2,0.0);

    Triangles.resize(2);

    Triangles[0]=_vertex3ui(0,1,2);
    Triangles[1]=_vertex3ui(1,2,3);

   CalculateNormals();
   selected_triangle=-1;
}
