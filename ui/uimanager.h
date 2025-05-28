#pragma once
#include "uilanguage.h"
#include <memory>

class UIManager {
public:
    static void setLanguage(std::unique_ptr<IUILanguage> lang);
    static IUILanguage& get();

private:
    static std::unique_ptr<IUILanguage> currentLang;
};
