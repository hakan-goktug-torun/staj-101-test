#ifndef SPACEGAMES_GAMEENGINE_H
#define SPACEGAMES_GAMEENGINE_H

#pragma once
#include <memory>
#include "../ships/ship.h"

class GameEngine {
public:
    int start(const std::shared_ptr<Ship>& ship);
    void printStatus(const std::shared_ptr<Ship>& ship);

};

#endif // SPACEGAMES_GAMEENGINE_H
