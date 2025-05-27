#include "shipfactory.h"
#include "../ships/fastship.h"
#include "../ships/strongship.h"
#include "../ships/normalship.h"
#include <algorithm>

std::shared_ptr<Ship> ShipFactory::createShip(ShipType type) {
    int fuel = 100, health = 100, balance = 0;

    switch (type) {
        case ShipType::Strong:
            return std::make_shared<strongShip>(fuel, health, balance);
        case ShipType::Fast:
            return std::make_shared<fastShip>(fuel, health, balance);
        case ShipType::Normal:
            return std::make_shared<normalShip>(fuel, health, balance);
        default:
            return nullptr;
    }
}

ShipType ShipFactory::getShipTypeFromString(const std::string& typeStr) {
    std::string lowerType = typeStr;
    std::transform(lowerType.begin(), lowerType.end(), lowerType.begin(), ::tolower);
    if (typeStr == "s") return ShipType::Strong;
    if (typeStr == "f") return ShipType::Fast;
    if (typeStr == "n") return ShipType::Normal;
    return ShipType::Invalid;
}

std::shared_ptr<Ship> ShipFactory::createShipFromSave(const std::string& typeStr, int fuel, int health, int balance) {
    if (typeStr == "Strong") return std::make_shared<strongShip>(fuel, health, balance);
    if (typeStr == "Fast") return std::make_shared<fastShip>(fuel, health, balance);
    if (typeStr == "Normal") return std::make_shared<normalShip>(fuel, health, balance);
    return nullptr;
}
