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
    float Vc(float tAmbient, float tEngine) override;
};

#endif