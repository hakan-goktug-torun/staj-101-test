#ifndef SPACEGAMES_EVENTMANAGER_H
#define SPACEGAMES_EVENTMANAGER_H

#include <memory>
#include "ship.h"
#include "spacepiratesevent.h"
#include "crossthebeltevent.h"
#include "abandonedplanetevent.h"

class EventManager {
public:
    void triggerRandomEvent(const std::shared_ptr<Ship>& ship);

};

#endif // SPACEGAMES_EVENTMANAGER_H
