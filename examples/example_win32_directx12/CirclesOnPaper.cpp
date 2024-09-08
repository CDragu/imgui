#include "CirclesOnPaper.h"

CirclesOnPaper::CirclesOnPaper()
{
    m_bAlive = true;
    m_bInitialized = false;
}

void CirclesOnPaper::Init()
{
    PopulateFKeysUI();
    m_bInitialized = true;
}

void CirclesOnPaper::Update()
{
    if(!m_bInitialized)
    {
        Init();
    }

    if(m_bAlive)
    {
        ImGui::Begin("Game Window", &m_bAlive);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");

        //Rendering
        ImVec2 mousePos = ImGui::GetMousePosOnOpeningCurrentPopup();
        ImVec2 windowPos = ImGui::GetWindowPos();

        ImGui::GetWindowDrawList()->AddCircle(mousePos, 10, ImColor(255, 255, 255), 20, 10);

        for(auto circle : m_Circles)
        {
            if(circle.m_Visible)
            {
                ImGui::GetWindowDrawList()->AddCircle(ImVec2(windowPos.x + circle.m_Pos.x, windowPos.y + circle.m_Pos.y), 10, ImColor(255, 255, 255), 20, 10);
            }
        }

        //Logic

        int startKey = ImGuiKey_F13;
        int endKey = ImGuiKey_F24;
        int lenght = endKey - startKey;
        for(int i = 0; i <= lenght; i++)
        {
            if(ImGui::IsKeyPressed(ImGuiKey(startKey + i)))
                m_Circles[i].m_Visible = !m_Circles[i].m_Visible;
        }

        if(ImGui::IsMouseClicked(RightMouseButton))
        {
            Circle c = { ImVec2(mousePos.x - windowPos.x ,  mousePos.y - windowPos.y ), true };
            m_Circles.push_back(std::move(c));
        }

        if(ImGui::Button("MakePile"))
        {
            PopulatePile();
        }

        if(ImGui::Button("Close Me"))
            m_bAlive = false;

        CheckFKeys();

        ImGui::End();
    }
}

void CheckFKeys()
{
    if(ImGui::IsKeyPressed(ImGuiKey_F13))
    {
        ImGui::Text("F13 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F14))
    {
        ImGui::Text("F14 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F15))
    {
        ImGui::Text("F15 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F16))
    {
        ImGui::Text("F16 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F17))
    {
        ImGui::Text("F17 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F18))
    {
        ImGui::Text("F18 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F19))
    {
        ImGui::Text("F19 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F20))
    {
        ImGui::Text("F20 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F21))
    {
        ImGui::Text("F21 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F22))
    {
        ImGui::Text("F22 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F23))
    {
        ImGui::Text("F23 Pressed");
    }
    if(ImGui::IsKeyPressed(ImGuiKey_F24))
    {
        ImGui::Text("F24 Pressed");
    }
}

void CirclesOnPaper::PopulatePile()
{
    ImVec2 windowPos = ImGui::GetWindowPos();

    windowPos.x = windowPos.x + 20;
    windowPos.y = windowPos.y + 20;

    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            Circle c = { ImVec2(windowPos.x + x * 20, windowPos.y + y * 20), true };
            m_Circles.push_back(std::move(c));
        }
    }
}

void CirclesOnPaper::PopulateFKeysUI()
{
    ImVec2 windowPos = ImGui::GetWindowPos();

    windowPos.x = windowPos.x + 50;
    windowPos.y = windowPos.y + 100;

    for(int y = 0; y < 4; y++)
    {
        for(int x = 0; x < 3; x++)
        {
            Circle c = { ImVec2(windowPos.x - x * 20, windowPos.y + y * 20), true };
            m_Circles.push_back(std::move(c));
        }
    }
}
