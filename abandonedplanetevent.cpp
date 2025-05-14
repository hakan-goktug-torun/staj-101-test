//
// Created by ChatCPP on 02.03.2024
//

#include "abandonedplanetevent.h"

void abandonedPlanetEvent::abandonedPlanet(std::shared_ptr<Ship> ship) {
    int value {0};
    int random = rand() % 101;
    std::cout << "While traveling through space, you saw an abandoned planet and decided to go! Maybe there are surprises waiting for you.\n";
    if (random >= 50) {
        value = 10 + ship->getBalance();
        ship->setBalance(value);
        std::cout << "Congratulations! You get 10 coins! Your new balance: " << ship->getBalance() << "\n";
    }
    else {
        std::cout << "Space pirates caught you collecting coins and you couldn't collect any! \n";
        spacePirates(ship);
    }
}

void abandonedPlanetEvent::crossTheBelt(std::shared_ptr<Ship> ship) {}

void abandonedPlanetEvent::spacePirates(std::shared_ptr<Ship> ship) {

}
