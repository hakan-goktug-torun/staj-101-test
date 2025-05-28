#ifndef SPACEGAMES_SHIPFACTORY_H
#define SPACEGAMES_SHIPFACTORY_H

#pragma once
#include <memory>
#include <string>
#include "../ships/ship.h"

enum class ShipType { Strong, Fast, Normal, Invalid };

class ShipFactory {
public:
    static std::shared_ptr<Ship> createShip(ShipType type);
    static std::shared_ptr<Ship> createShipFromSave(const std::string& typeStr, int fuel, int health, int balance);
    static std::string ShipTypeToString(ShipType type);
    static ShipType StringToShipType(const std::string& typeStr);
};

#endif // SPACEGAMES_SHIPFACTORY_H


