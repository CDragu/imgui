#pragma once

#include "imgui.h"

class DataStore;

class Map
{
public:

    Map(DataStore* data);
    void Init();
    void Update();

private:
    DataStore* m_Data;
    bool m_bAlive;
    bool m_bInitialized;

};

