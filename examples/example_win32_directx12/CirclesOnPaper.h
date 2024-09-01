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
    void Update();

private:

    bool m_bAlive;

    std::vector<Circle> m_Circles;
};

