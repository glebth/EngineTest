#ifndef TESTSTAND_H
#define TESTSTAND_H

#include "stdio.h"

template<class NG>
class TestStand {
public:
    TestStand(NG &engine, const float tAmbient);
    float StartEngineTest();
private:
    NG *_engine;
    float _tAmbient;
    float _tEngine;
    float _time;
};

template<class NG>
TestStand<NG>::TestStand(NG &engine, const float tAmbient) {
    _engine = &engine;
    _tAmbient = tAmbient;
    _tEngine = _tAmbient;
    _time = 0;
}

template<class NG>
float TestStand<NG>::StartEngineTest() {

    float a = _engine->_M / _engine->_I;

    float overheat = _engine->_Toh - _tEngine;

    int vmIndex = 0;
    
    while (_time < 100 || overheat > 0.1f) {

        ++_time;

        _engine->_V += a * _time;

        if (_engine->_V < _engine->_VMtable.back().x) {

            printf("_V == %f \n", _engine->_V);

            if (vmIndex + 2 < _engine->_VMtable.size() && _engine->_V > _engine->_VMtable[vmIndex+1].x) {
                vmIndex += 1;
            }

            // Линейная функция : M = slope * V + b
            float slope = _engine->_VMtable[vmIndex].Slope(_engine->_VMtable[vmIndex + 1]);
            float b = _engine->_VMtable[vmIndex].y - slope * _engine->_VMtable[vmIndex].x;
            _engine->_M = slope * _engine->_V + b;
        }

        _tEngine += ( _engine->Vc(_tAmbient, _tEngine) + _engine->Vh() ) * _time;

        a = _engine->_M / _engine->_I;
        overheat = _engine->_Toh - _tEngine;
    }


    return _time;
}

#endif