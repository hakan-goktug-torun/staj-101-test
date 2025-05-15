#ifndef SPACEGAMES_SCORESERVICE_H
#define SPACEGAMES_SCORESERVICE_H

#include <memory>
#include "ship.h"

class ScoreService {
public:
    static int calculate(const std::shared_ptr<Ship>& ship);
    static void display(int score);
};

#endif // SPACEGAMES_SCORESERVICE_H
