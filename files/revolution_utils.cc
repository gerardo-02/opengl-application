#include <revolution_utils.h>

void CreateRevolutionObject(vector<_vertex3f> &V, vector<_vertex3ui> &T, vector<_vertex3f> P, int n){
    float angle = (2 * M_PI) / n;
    V.resize(P.size() * n);
    int Pos = 0;
    _vertex3f actual;
    float R;
    float actual_angle;

    for (int i=0; i<n; i++){
        actual_angle = angle * i;
        for (int j=0; j<P.size(); j++){

            R = P[j][0];
            actual[0] = R * cos(actual_angle);
            actual[1] = P[j][1];
            actual[2] = -R * sin(actual_angle);

            V[Pos] = actual;

            Pos++;
        }
    }

    int t_por_revolucion = ((P.size() - 3) * 2 + 2);
    T.resize(t_por_revolucion * n);

    Pos=0;
    int aux = 0;

    for (int i=0; i < n; i++){
        aux = 0;
        for (int j=0; j < t_por_revolucion; j++){
            if (j % 2 == 0){
                T[Pos] = _vertex3ui(((i * P.size() ) + (aux + 1)) % V.size(), ((i + 1) * P.size() + aux) % V.size(), (((i + 1) * P.size() ) + (aux + 1)) % V.size());
                Pos++;
            }
            else {
                T[Pos] = _vertex3ui(((i * P.size() ) + (aux + 1)) % V.size(), ((i * P.size() ) + (aux + 2)) % V.size(), (((i + 1) * P.size() ) + (aux + 1)) % V.size());
                Pos++;
                aux++;
            }

         }
    }
}
