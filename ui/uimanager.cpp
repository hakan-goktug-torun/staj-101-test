#include "uimanager.h"

std::unique_ptr<IUILanguage> UIManager::currentLang = nullptr;

void UIManager::setLanguage(std::unique_ptr<IUILanguage> lang) {
    currentLang = std::move(lang);
}

IUILanguage& UIManager::get() {
    return *currentLang;
}

