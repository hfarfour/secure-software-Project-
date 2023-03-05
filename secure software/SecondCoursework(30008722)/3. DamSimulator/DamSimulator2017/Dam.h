#pragma once
#include "World.h"

class Dam
{
public:
   Dam(const World& world);
   void Update();
   void Render();

private:
   const double MIN_FLOWRATE = 0.0;
   const double MAX_FLOWRATE = 100.0;
   const double MIN_WATER_LEVEL = 0.0;
   const double MAX_WATER_LEVEL = 100000.0;

   const World& m_world;

   double m_waterLevel = 0;
   double m_flowRate = 0;
   bool m_renderRequired = true;
};
