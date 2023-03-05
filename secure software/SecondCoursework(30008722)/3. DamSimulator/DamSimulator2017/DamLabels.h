#pragma once
#include "Label.h"
#include "SecureInts.h"

//Static helper class, containing all the labels used to draw the Dam image.
class DamLabels
{
public:
   static const Label Wall;
   static const Label Ground;
   static const Label WaterOutput;
   static const Label WaterInput1;
   static const Label WaterInput2;
   static const Label WaterInput3;
   static const Label WaterInput4;
   static const Label Rain1;
   static const Label Rain2;

private:
   static const int32_s m_originX;
   static const int32_s m_originY;

   static const std::string S;
   static const std::string D;
   static const std::string W;
   static const std::string R1;
   static const std::string R2;
};