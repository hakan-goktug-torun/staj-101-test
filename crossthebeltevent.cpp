//
// Created by ChatCPP on 02.03.2024
//

#include "crossthebeltevent.h"

void crossTheBeltEvent::manageEvents(std::shared_ptr<Ship> ship) {
    std::cout << " Asteroid field detected!\n";
    int chance = rand() % 101;
    if (ship->getPercEscape() >= chance) {
        std::cout << "You escaped the asteroid belt!\n";
    } else {
        std::cout << "You took damage from asteroids!\n";
        ship->takeDamage(ship->getAsDamage());
        std::cout << "Health: " << ship->getHealth() << "\n";
    }
}

//gereksiz fonksiyonlar silindi