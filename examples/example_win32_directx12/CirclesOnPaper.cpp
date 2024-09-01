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


        ImVec2 current = ImGui::GetMousePos();

        ImGui::GetWindowDrawList()->AddCircle(current, 10, ImColor(255, 255, 255), 20, 10);


        if(ImGui::Button("Close Me"))
            m_bAlive = false;
        ImGui::End();
    }
}
