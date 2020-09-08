#include "ICEngine.h"

ICEngine::ICEngine(float I, std::vector<float> Mtable, std::vector<float> Vtable,
        float Toh, float Hm, float Hv, float C, float tAmbient)
{
    _I = I;

    for (int i = 0; i < Mtable.size(); ++i) {
        _VMtable.push_back(Point(Vtable[i], Mtable[i]));
    }

    _Toh = Toh;
    _Hm = Hm;
    _Hv = Hv;
    _C = C;

    _V = Vtable[0];
    _M = Mtable[0];

    _Teng = tAmbient;
}

float ICEngine::Vh() {
    return ( _M * _Hm + _V * _V * _Hv );
}

float ICEngine::Vc(float tAmbient, float tEngine) {
    return ( _C * (tAmbient - tEngine) );
}