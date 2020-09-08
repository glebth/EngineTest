#ifndef TESTSTAND_H
#define TESTSTAND_H

#include "stdio.h"

template<class NG>
class TestStand {
public:
    TestStand(NG &engine, const float tAmbient);
    float StartEngineTest();
private:
    NG *engine;
    float tAmbient;
    float tEngine;
    float time;
};

template<class NG>
TestStand<NG>::TestStand(NG &newEngine, const float newtAmbient) {
    engine = &newEngine;
    tAmbient = newtAmbient;
    tEngine = tAmbient;
    time = 0;
}

template<class NG>
float TestStand<NG>::StartEngineTest() {

    float a = engine->_M / engine->_I;

    float overheat = engine->_Toh - tEngine;

    int vmIndex = 0;
    
    while (time < 1000 && overheat > 0.1f) {

        ++time;

        engine->_V = engine->_VMtable[vmIndex].x + a * time;

        if (engine->_V < engine->_VMtable.back().x) {

            if (vmIndex + 2 < engine->_VMtable.size() && engine->_V > engine->_VMtable[vmIndex+1].x) {
                vmIndex += 1;
            }

            // Линейная функция : M = slope * V + b
            float slope = engine->_VMtable[vmIndex].Slope(engine->_VMtable[vmIndex + 1]);
            float b = engine->_VMtable[vmIndex].y - slope * engine->_VMtable[vmIndex].x;
            engine->_M = slope * engine->_V + b;
        }
        else {
            engine->_V = engine->_VMtable.back().x;
            engine->_M = engine->_VMtable.back().y;
        }
        
        tEngine += (engine->Vc(tAmbient, tEngine) + engine->Vh()) * time;

        a = engine->_M / engine->_I;
        overheat = engine->_Toh - tEngine;
    }


    return time;
}

#endif