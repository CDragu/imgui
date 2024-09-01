#include "CirclesOnPaper.h"

CirclesOnPaper::CirclesOnPaper()
{
    m_bAlive = true;
}

void CirclesOnPaper::Update()
{
    if(m_bAlive)
    {
        ImGui::Begin("Game Window", &m_bAlive);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");


        ImVec2 current = ImGui::GetMousePosOnOpeningCurrentPopup();

        ImGui::GetWindowDrawList()->AddCircle(current, 10, ImColor(255, 255, 255), 20, 10);

        for(auto circle : m_Circles)
        {
            if(circle.m_Visible)
            {
                ImGui::GetWindowDrawList()->AddCircle(ImVec2(ImGui::GetWindowPos().x + circle.m_Pos.x, ImGui::GetWindowPos().y + circle.m_Pos.y), 10, ImColor(255, 255, 255), 20, 10);
            }
        }

        if(ImGui::IsMouseClicked(RightMouseButton))
        {
            Circle c = { ImVec2(current.x - ImGui::GetWindowPos().x ,  current.y - ImGui::GetWindowPos().y ), true };
            m_Circles.push_back(std::move(c));
        }

        if(ImGui::Button("Close Me"))
            m_bAlive = false;
        ImGui::End();
    }
}
