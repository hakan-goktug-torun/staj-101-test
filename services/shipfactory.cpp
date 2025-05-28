#include "shipfactory.h"
#include "../ships/fastship.h"
#include "../ships/strongship.h"
#include "../ships/normalship.h"
#include <algorithm>
#include <unordered_map>

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

std::shared_ptr<Ship> ShipFactory::createShipFromSave(const std::string& typeStr, int fuel, int health, int balance) {
    ShipType type = StringToShipType(typeStr);
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

std::string ShipFactory::ShipTypeToString(ShipType type) {
    switch (type) {
        case ShipType::Strong: return "Strong";
        case ShipType::Fast:   return "Fast";
        case ShipType::Normal: return "Normal";
        default:               return "Invalid";
    }
}

ShipType ShipFactory::StringToShipType(const std::string& typeStr) {
    static const std::unordered_map<std::string, ShipType> map = {
        {"strong", ShipType::Strong}, {"s", ShipType::Strong}, {"g", ShipType::Strong},
        {"fast", ShipType::Fast},     {"f", ShipType::Fast},   {"h", ShipType::Fast},
        {"normal", ShipType::Normal}, {"n", ShipType::Normal}
    };

    std::string lower = typeStr;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    auto it = map.find(lower);
    return it != map.end() ? it->second : ShipType::Invalid;
}
