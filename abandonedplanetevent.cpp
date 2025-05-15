//
// Created by ChatCPP on 02.03.2024
//

#include "abandonedplanetevent.h"
#include "spacepiratesevent.h" // spacePiratesı çağırmak için ekledim

const int kCoinReward = 10; //magic number ihtimalini yok etmek için const ile ekledim

void abandonedPlanetEvent::manageEvents(std::shared_ptr<Ship> ship) {
    std::cout << "You discovered an abandoned planet!\n";
    int random = rand() % 101;
    if (random >= 50) {
        ship->setBalance(ship->getBalance() + kCoinReward);
        std::cout << " You found 10 coins. Balance: " << ship->getBalance() << "\n";
    } else {
        std::cout << " Space pirates ambushed you!\n";
        spacePiratesEvent pirates;
        pirates.manageEvents(ship);  // doğrudan spacepirates olayını çağırır
    }
}


// fazlalık fonksiyonlar silindi