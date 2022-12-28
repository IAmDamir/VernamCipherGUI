#pragma once

#include "imgui.h"
#include <string>
#include <vector>

namespace MyApp
{
    void RenderUI();
    std::string VernamCypher(
        const std::string& str,
        const std::string& key);
};
