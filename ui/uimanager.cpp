#include "uimanager.h"
#include <algorithm>

Language UIManager::lang = Language::EN;

Language UIManager::parseLanguageInput(const std::string& input) {
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

    if (lowerInput == "tr" || lowerInput == "türkçe" || lowerInput == "turkish") {
        return Language::TR;
    }

    if (lowerInput == "en" || lowerInput == "eng" || lowerInput == "english") {
        return Language::EN;
    }

    std::cout << "Invalid input. Defaulting to English.\n";
    return Language::EN;
}
