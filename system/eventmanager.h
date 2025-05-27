#ifndef SPACEGAMES_EVENTMANAGER_H
#define SPACEGAMES_EVENTMANAGER_H

#pragma once
#include <memory>
#include "../ships/ship.h"
#include "../events/events.h"

class EventManager {
public:
    void triggerRandomEvent(const std::shared_ptr<Ship>& ship);

};

#endif // SPACEGAMES_EVENTMANAGER_H
