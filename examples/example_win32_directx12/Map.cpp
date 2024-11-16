#define IMGUI_DEFINE_MATH_OPERATORS
#include "Map.h"
#include "DataStore.h"
#include "imgui_internal.h"

Map::Map(DataStore* data) :
    m_Data(data)
{
}

void Map::Init()
{
    m_bAlive = true;
    m_bInitialized = true;
}

void Map::Update()
{
    if(!m_bInitialized)
    {
        Init();
    }

    ImGui::Begin("Map Window", &m_bAlive);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    ImGui::Text("Player Pos: %f %f", m_Data->m_Player.m_Pos.x, m_Data->m_Player.m_Pos.y);

    ImVec2 windowPos = ImGui::GetWindowPos();
    ImVec2 windowMax = ImGui::GetContentRegionAvail();
    ImVec2 windowMin = ImGui::GetWindowContentRegionMin();

    ImVec2 ZeroPos = ImVec2(windowPos.x + windowMax.x / 2, windowPos.y + windowMax.y / 2);

    ImGui::GetWindowDrawList()->AddCircle(ImAdd(ZeroPos, m_Data->m_Player.m_Pos), 10, ImColor(25, 255, 25), 20, 10);

    ImGui::End();
}
