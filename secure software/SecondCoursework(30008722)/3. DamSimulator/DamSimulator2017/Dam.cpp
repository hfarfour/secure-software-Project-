#include "Dam.h"

#include <string>
#include <vector>
#include "Texture.h"

Dam::Dam(const World& world)
   :
   m_world(world)
{
}

void Dam::Update()
{
   if (m_renderRequired)
   {
      m_renderRequired = false;
      Render();
   }
}

void Dam::Render()
{
   static const std::string C0 = { (char)0, (char)0 }; //Space
   static const std::string C1 = { (char)219, (char)219 };
   static const std::string C2 = { (char)176, (char)176 };

   Texture wall(2, 1,
   {
      C0 + C0 + C0 + C1 + C1 + C0 + C0 + C0,
      C0 + C0 + C0 + C1 + C1 + C0 + C0 + C0,
      C0 + C0 + C0 + C1 + C1 + C0 + C0 + C0,
      C0 + C0 + C0 + C1 + C1 + C0 + C0 + C0,
      C0 + C0 + C0 + C1 + C1 + C0 + C0 + C0,
   });

   Texture ground(2, 6,
   {
      C1 + C1 + C1 + C1 + C1 + C1 + C1 + C1
   });ll

   Texture waterIn(2, 2,
   {
      C2 + C2 + C2,
      C2 + C2 + C2,
      C2 + C2 + C2,
      C2 + C2 + C2
   });

   Texture waterOut(12, 5,
   {
      C2 + C2 + C2
   });

   wall.Draw();
   ground.Draw();
   waterIn.Draw();

   waterOut.Draw();

   //Draw text

   std::string waterLevelText = "Water level: " + std::to_string(m_waterLevel);
   Console::WriteLine(10, 2, waterLevelText);

   std::string flowRateText = "Flow rate: " + std::to_string(m_flowRate);
   Console::WriteLine(10, 2, waterLevelText);
}
