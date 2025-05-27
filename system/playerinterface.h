#ifndef SPACEGAMES_PLAYERINTERFACE_H
#define SPACEGAMES_PLAYERINTERFACE_H

#pragma once
#include <memory>
#include <string>
#include "../ships/ship.h"

class PlayerInterface {
public:
    static std::shared_ptr<Ship> promptForShip(std::string& outType);
    static std::shared_ptr<Ship> loadOrCreateShip(std::string& outType);
    static std::string askPlayerName();
    static bool askToSaveGame();
};

#endif // SPACEGAMES_PLAYERINTERFACE_H

