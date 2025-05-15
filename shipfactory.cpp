#include "shipfactory.h"

std::shared_ptr<Ship> ShipFactory::createShip(const std::string& type) {
    int fuel = 100, health = 100, balance = 0;
    if (type == "s") return std::make_shared<strongShip>(fuel, health, balance);
    if (type == "f") return std::make_shared<fastShip>(fuel, health, balance);
    if (type == "n") return std::make_shared<normalShip>(fuel, health, balance);
    return nullptr;
}
