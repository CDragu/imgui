#pragma once

#include "imgui.h"

class DataStore
{
    struct Player
    {
        ImVec2 m_Pos;
    };

public:
    Player m_Player;
    float m_Time = 0.0f;
};

