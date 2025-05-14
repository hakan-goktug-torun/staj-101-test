//
// Created by ChatCPP on 02.03.2024
//

#include "ship.h"


void Ship::takenDamage(int eventNum) {
    int newHealth{0 };
    if (eventNum == 1) { // event number 1 olursa astreoid kuşağının hasarını alıyor.
        newHealth = getHealth() - getAsDamage();
        setHealth(newHealth);
    }
    else if (eventNum == 2) { // event number 2 olursa uzay korsanlarının hasarını alıyor.
        newHealth = getHealth() - getDamage();
        setHealth(newHealth);
    }
}

void Ship::possEscape(int eventNum) {
    int random{ 0 };
    random = rand() % 101;
    if (percEscape >= random){
        std::cout << "You've escaped!";
    }
    else {
        std::cout << "You couldn't escape!";
        takenDamage(eventNum);
    }

}
