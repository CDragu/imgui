#pragma once

#include "imgui.h"
#include "vector"

class CirclesOnPaper
{
public:
    CirclesOnPaper();
    void Update();

private:

    bool m_bAlive;

    std::vector<Circle>(); //I want this to be a class that represents a circle in 2d space

};

