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
        ship->takeDamage(ship->getAsDamage()); //getAsDamage() fonksiyonu ne kadar hasar alacağını belirliyor- takeDamage() fonksiyonu hasarı uyguluyor
        // takeDamage fonksiyonu ile mesela ship->takeDamage(25); ile de 25 hasar uygulanabilir
        std::cout << "Health: " << ship->getHealth() << "\n";
    }
}

//gereksiz fonksiyonlar silindi