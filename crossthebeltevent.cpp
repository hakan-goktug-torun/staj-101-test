//
// Created by ChatCPP on 02.03.2024
//

#include "crossthebeltevent.h"
void crossTheBeltEvent::crossTheBelt(std::shared_ptr<Ship> ship) {
    std::cout << "You've seen asteroids traveling through space and they are very close to your ship! Watch out!\n";
    ship->possEscape(1);
    std::cout << "\nNew Health: " << ship->getHealth() << "\n";
}

void crossTheBeltEvent::abandonedPlanet(std::shared_ptr<Ship> ship) {}
void crossTheBeltEvent::spacePirates(std::shared_ptr<Ship> ship) {}