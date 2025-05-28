#ifndef SPACEGAMES_EVENTMANAGER_H
#define SPACEGAMES_EVENTMANAGER_H

#pragma once
#include <memory>
#include <map>
#include <functional>
#include "../ships/ship.h"
#include "../events/events.h"

enum class EventType { Pirates, Belt, Planet };

class EventManager {
public:
    EventManager(); // constructor'da map kur
    void triggerRandomEvent(const std::shared_ptr<Ship>& ship);

private:
    std::map<EventType, std::function<std::unique_ptr<Events>()>> eventFactory;
};

#endif // SPACEGAMES_EVENTMANAGER_H
