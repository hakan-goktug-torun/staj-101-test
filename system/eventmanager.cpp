#include "eventmanager.h"
#include "../events/abandonedplanetevent.h"
#include "../events/crossthebeltevent.h"
#include "../events/spacepiratesevent.h"
#include <cstdlib>

void EventManager::triggerRandomEvent(const std::shared_ptr<Ship>& ship) {
    if (ship->getFuel() <= 0) {
        std::cout << "[!] Your ship has no fuel left. Event skipped.\n";
        return;
    }   
     
    int eventType = rand() % 3;
    std::unique_ptr<Events> event;

    switch (eventType) {
        case 0: event = std::make_unique<spacePiratesEvent>(); break;
        case 1: event = std::make_unique<crossTheBeltEvent>(); break;
        case 2: event = std::make_unique<abandonedPlanetEvent>(); break;
    }

    if (event) {
        event->manageEvents(ship);  // sadece tek fonksiyon
    }
}
