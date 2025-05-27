#ifndef SPACEGAMES_SHIPFACTORY_H
#define SPACEGAMES_SHIPFACTORY_H

#include <memory>
#include "ship.h"
#include "fastship.h"
#include "strongship.h"
#include "normalship.h"

enum class ShipType { Strong, Fast, Normal, Invalid };

class ShipFactory {
public:
    static std::shared_ptr<Ship> createShip(ShipType type);
    static ShipType getShipTypeFromString(const std::string& typeStr);
    static std::shared_ptr<Ship> createShipFromSave(const std::string& typeStr, int fuel, int health, int balance);
};

#endif // SPACEGAMES_SHIPFACTORY_H

