#define IMGUI_DEFINE_MATH_OPERATORS
#include "SolarSystem.h"
#include "DataStore.h"
#include "imgui_internal.h"
#include <implot3d.h>
#include <string.h>
#include <string>


struct Planet
{
    std::string Name;
    int OrbitRes = 300;
    float x[300];
    float y[300];
    float z[300];
};

SolarSystem::SolarSystem(DataStore* data) :
    m_Data(data)
{
}

int NumOfPlanets = 9;
float x_data[9] = { 0, 0.387, 0.72, 1, 1.52, 5, 9.5, 19.2, 30.04 };//{ 1, 1, 1, 1, 1, 1, 1, 1 };
float y_data[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
float z_data[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
float speed[9] = { 1, 47.9, 35.0, 29.8, 24.0, 13.1, 9.69, 6.81, 5.43 };
float eccentricity[9] = { 0, 0.206, 0.007, 0.017, 0.094, 0.049, 0.052, 0.047, 0.010 };

std::string planetName[9] = {
    "Sun",
    "Mercury",
    "Venus",
    "Earth",
    "Mars",
    "Jupiter",
    "Saturn",
    "Uranus",
    "Neptune",
};
Planet Planets[9];

void SolarSystem::Init()
{
    m_bAlive = true;
    m_bInitialized = true;

    CalculatePlanetOrbit();
}

void SolarSystem::CalculatePlanetOrbit()
{
    for(int j = 0; j < NumOfPlanets; j++)
    {
        Planets[j].Name = planetName[j];
        for(int i = 0; i < Planets[j].OrbitRes; i++)
        {
            Planets[j].x[i] = x_data[j] * sin(((2 * 3.13159) / (Planets[j].OrbitRes-2)) * i);
            Planets[j].y[i] = x_data[j] * cos(((2 * 3.13159) / (Planets[j].OrbitRes-2)) * i) * (1 - eccentricity[j]);
            Planets[j].z[i] = 1;
        }
    }
}

void SolarSystem::Update()
{
    static float mk_size = 10;
    static float mk_weight = ImPlot3D::GetStyle().MarkerWeight;

    if(!m_bInitialized)
    {
        Init();
    }
    ImGui::Begin("My Solar Window");

    ImGui::DragFloat("Marker Size", &mk_size, 0.1f, 2.0f, 15.0f, "%.2f px");
    ImGui::DragFloat("Marker Weight", &mk_weight, 0.05f, 0.5f, 3.0f, "%.2f px");

    if(ImPlot3D::BeginPlot("Solar System", ImVec2(2000,2000)))
    {

        float xs[2] = { 0, 0 };
        float ys[2] = { 0, 0 };
        float zs[2] = { 0, 0 };

        ImPlot3D::SetupAxes(nullptr, nullptr, nullptr, ImPlot3DAxisFlags_NoDecorations, ImPlot3DAxisFlags_NoDecorations, ImPlot3DAxisFlags_NoDecorations);
        //ImPlot3D::SetupAxesLimits(-0.5, 1.5, -0.5, 1.5, 0, ImPlot3DMarker_COUNT + 1);
        
        for(int j = 0; j < NumOfPlanets; j++)
        {
            ImPlot3D::PlotLine(Planets[j].Name.c_str(), Planets[j].x, Planets[j].y, Planets[j].z, Planets[0].OrbitRes);
        }

        for(int m = 0; m < NumOfPlanets; ++m)
        {
            ImGui::PushID(m);
            ImPlot3D::SetNextMarkerStyle(m, mk_size, IMPLOT3D_AUTO_COL, mk_weight);

            
            xs[0] = x_data[m] * sin(((2 * 3.13159) / Planets[m].OrbitRes) * m_Data->m_Time * speed[m]);
            xs[1] = x_data[m] * sin(((2 * 3.13159) / Planets[m].OrbitRes) * m_Data->m_Time * speed[m]);

            ys[0] = x_data[m] * cos(((2 * 3.13159) / Planets[m].OrbitRes) * m_Data->m_Time * speed[m]) * (1 - eccentricity[m]);
            ys[1] = x_data[m] * cos(((2 * 3.13159) / Planets[m].OrbitRes) * m_Data->m_Time * speed[m]) * (1 - eccentricity[m]);

            zs[0] = 1;
            zs[1] = 1;
            ImPlot3D::PlotLine("##Filled", xs, ys, zs, 2);

            ImPlot3D::PlotText(planetName[m].c_str(), xs[0], ys[0], 1.05f);
            ImGui::PopID();
        }

        ImPlot3D::EndPlot();
    }

    ImGui::End();
}
