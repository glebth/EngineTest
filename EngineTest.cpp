#include <iostream>

#include "Engine/ICEngine.h"
#include "TestStand.h"

int main() {
    std::cout << "Hello engine!" << std::endl;

    float tAmbient = -10.0f;

    std::cin >> tAmbient;

    ICEngine testingEngine(
        10,
        {20, 75, 100, 105, 75, 0},
        {0, 75, 150, 200, 250, 300},
        110,
        0.01,
        0.0001,
        0.1,
        tAmbient
    );

    TestStand<ICEngine> stand(testingEngine, tAmbient);
    printf("Vremya == %f \n", stand.StartEngineTest());
    
    return 0;
}