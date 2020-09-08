#ifndef ICENGINE_H
#define ICENGINE_H

#include "Engine.h"

class ICEngine : public Engine {
public:
    ICEngine(
        float I, 
        std::vector<float> M, 
        std::vector<float> V,
        float Toh,
        float Hm,
        float Hv,
        float C,
        float tAmbient);
        
    float Vh() override;
    float Vc(double tAmbient, double tEngine) override;

    // inline float GetToh() { return _Toh; }
    // inline float GetM() { return _M; }
    // inline float GetV() { return _V; }
    // inline float GetI() { return _I; }
    // inline std::vector<float> &GetMtable() { return _Mtable; }
    // inline std::vector<float> &GetVtable() { return _Vtable; }
};

#endif