#ifndef TESTSTAND_H
#define TESTSTAND_H

#include "stdio.h"

const int WAIT_TIME = 3600;
const float ERROR_COEF = 1.5f;

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
    
    while (time < WAIT_TIME && overheat > ERROR_COEF) {

        ++time;

        engine->_V += a; // * dtime = 1 sec.

        if (engine->_V < engine->_VMtable.back().v) {

            while (vmIndex + 2 < engine->_VMtable.size() && engine->_V > engine->_VMtable[vmIndex+1].v) {
                vmIndex += 1;
            }

            // Линейная функция : M = slope * V + b.
            float slope = engine->_VMtable[vmIndex].Slope(engine->_VMtable[vmIndex + 1]);
            float b = engine->_VMtable[vmIndex].m - slope * engine->_VMtable[vmIndex].v;
            engine->_M = slope * engine->_V + b;
        }
        else {
            engine->_V = engine->_VMtable.back().v;
            engine->_M = engine->_VMtable.back().m;
        }

        tEngine += (engine->Vc(tAmbient, tEngine) + engine->Vh());

        a = engine->_M / engine->_I;
        overheat = engine->_Toh - tEngine;
    }

    return time;
}

#endif