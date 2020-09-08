#ifndef ENGINE_H
#define ENGINE_H

#include <vector>

#include "TestStand.h"
#include "Utils.h"

class Engine {
public:
    Engine(){};
    virtual float Vh() = 0;
    virtual float Vc(double tAmbient, double tEngine) = 0;
protected:
    float _I; // Момент инерции.
    float _Toh; // Температура перегрева.
    float _Teng; // Температура двигателя.
    float _Hm;
    float _Hv;
    float _C;

    float _M;
    float _V;

    std::vector<Point> _VMtable; // Зависимость M от V.

    template<class NG>
    friend class TestStand; // Тестовый стэнд получает доступ к полям двигателя
};

#endif