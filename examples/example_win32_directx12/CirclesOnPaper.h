#pragma once

#include "imgui.h"
#include "vector"

static constexpr int RightMouseButton = 1;

struct Circle
{
    ImVec2  m_Pos;
    bool m_Visible;
};

class CirclesOnPaper
{
public:
    CirclesOnPaper();
    void Init();
    void Update();

    void PopulatePile();

    void PopulateFKeysUI();

private:

    bool m_bAlive;
    bool m_bInitialized;

    std::vector<Circle> m_Circles;
};

void CheckFKeys();
