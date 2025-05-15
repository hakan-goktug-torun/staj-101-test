#include "scoreservice.h"
#include <iostream>

int ScoreService::calculate(const std::shared_ptr<Ship>& ship) {
    return (ship->getFuel() * 5) + (ship->getHealth() * 10) + (ship->getBalance() * 10);
}

void ScoreService::display(int score) {
    std::cout << "Your game score: " << score << "\nCongratulations!\n";
}
