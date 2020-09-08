#include <stdio.h>

#include "Engine/ICEngine.h"
#include "TestStand.h"

int main() {
    printf("Hello engine! \n");

    float tAmbient = 0.0f;

    scanf("%f", tAmbient);

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

    TestStand<ICEngine> stand(testingEngine, 20);
    printf("Vremya == %f \n", stand.StartEngineTest());
    
    return 0;
}