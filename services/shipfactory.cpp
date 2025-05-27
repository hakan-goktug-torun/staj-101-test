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
    return StringToShipType(typeStr);
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
    std::string lower = typeStr;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    if (lower == "strong" || lower == "s" || lower == "g") return ShipType::Strong;
    if (lower == "fast"   || lower == "f" || lower == "h") return ShipType::Fast;
    if (lower == "normal" || lower == "n") return ShipType::Normal;
    return ShipType::Invalid;
}
