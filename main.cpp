#include "events.h"
#include "shipgenerator.h"
#include <cstdlib>
#include <ctime>
int main() {
    srand(time(nullptr));
    shipGenerator shipGenerate;
    shipGenerate.addNewShip();
    return 0;
}



