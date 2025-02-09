#pragma once

#include "imgui.h"

class DataStore;

class SolarSystem
{
public:

    SolarSystem(DataStore* data);
    void Init();
    void CalculatePlanetOrbit();
    void Update();

private:
    DataStore* m_Data;
    bool m_bAlive;
    bool m_bInitialized = false;
};

