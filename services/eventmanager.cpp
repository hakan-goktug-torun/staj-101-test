#include "eventmanager.h"
#include "../events/abandonedplanetevent.h"
#include "../events/crossthebeltevent.h"
#include "../events/spacepiratesevent.h"
#include <cstdlib>

EventManager::EventManager() {
    eventFactory[EventType::Pirates] = []() { return std::make_unique<spacePiratesEvent>(); };
    eventFactory[EventType::Belt]    = []() { return std::make_unique<crossTheBeltEvent>(); };
    eventFactory[EventType::Planet]  = []() { return std::make_unique<abandonedPlanetEvent>(); };
}

void EventManager::triggerRandomEvent(const std::shared_ptr<Ship>& ship) {
    if (ship->getFuel() <= 0) {
        auto event = std::make_unique<abandonedPlanetEvent>();
        event->manageEvents(ship);
        return;
    }

    int index = rand() % eventFactory.size();
    auto it = std::next(eventFactory.begin(), index);

    if (it != eventFactory.end()) {
        std::unique_ptr<Events> event = it->second();
        event->manageEvents(ship);
    }
}

