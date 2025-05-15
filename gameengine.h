#ifndef SPACEGAMES_GAMEENGINE_H
#define SPACEGAMES_GAMEENGINE_H

#include "ship.h"
#include <memory>

class GameEngine {
public:
    void start(const std::shared_ptr<Ship>& ship);
};

#endif // SPACEGAMES_GAMEENGINE_H
