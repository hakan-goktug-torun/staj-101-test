#ifndef SPACEGAMES_GAMEENGINE_H
#define SPACEGAMES_GAMEENGINE_H

#include "ship.h"
#include <memory>
#include <string>

class GameEngine {
public:
    bool start(const std::shared_ptr<Ship>& ship);
    void printStatus(const std::shared_ptr<Ship>& ship);

};

#endif // SPACEGAMES_GAMEENGINE_H
