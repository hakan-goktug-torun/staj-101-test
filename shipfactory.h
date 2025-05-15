#ifndef SPACEGAMES_SHIPFACTORY_H
#define SPACEGAMES_SHIPFACTORY_H

#include <memory>
#include <string>
#include "ship.h"
#include "fastship.h"
#include "strongship.h"
#include "normalship.h"

class ShipFactory {
public:
    static std::shared_ptr<Ship> createShip(const std::string& type);
};

#endif // SPACEGAMES_SHIPFACTORY_H
