#include "DamLabels.h"
#include "Label.h"
const int32_s DamLabels::m_originX(36);
const int32_s DamLabels::m_originY(3);

#pragma warning( disable : 4309 )
const std::string DamLabels::S({ static_cast<char>(0x00), static_cast<char>(0x00) }); //Space
const std::string DamLabels::D({ static_cast<char>(0xDB), static_cast<char>(0xDB) }); //Dam
const std::string DamLabels::W({ static_cast<char>(0xB1), static_cast<char>(0xB1) }); //Water
const std::string DamLabels::R1({ static_cast<char>(0x27), static_cast<char>(0x2E) }); //Rain 1
const std::string DamLabels::R2({ static_cast<char>(0x2E), static_cast<char>(0x27) }); //Rain 2
#pragma warning( default : 4309 )

const Label DamLabels::Wall = Label(
   m_originX + int32_s(12), //#V2_2
   m_originY + int32_s(2), //#V2_2
   {
      D + D,
      D + D,
      D + D,
      D + D,
      D + D,
   });

const Label DamLabels::Ground = Label(
   m_originX,
   m_originY + int32_s(7), //#V2_2
   {
      D + D + D + D + D + D + D + D + D + D + D + D + D + D,
      D + D + D + D + D + D + D + D + D + D + D + D + D + D
   });

const Label DamLabels::WaterInput1 = Label(
   m_originX,
   m_originY + int32_s(6), //#V2_2
   {
      W + W + W + W + W + W
   });

const Label DamLabels::WaterInput2 = Label(
   m_originX,
   m_originY + int32_s(5), //#V2_2
   {
      W + W + W + W + W + W,
      W + W + W + W + W + W
   });

const Label DamLabels::WaterInput3 = Label(
   m_originX,
   m_originY + int32_s(4), //#V2_2
   {
      W + W + W + W + W + W,
      W + W + W + W + W + W,
      W + W + W + W + W + W
   });

const Label DamLabels::WaterInput4 = Label(
   m_originX,
   m_originY + int32_s(3), //#V2_2
   {
      W + W + W + W + W + W,
      W + W + W + W + W + W,
      W + W + W + W + W + W,
      W + W + W + W + W + W
   });

const Label DamLabels::WaterOutput = Label(
   m_originX + int32_s(16), //#V2_2
   m_originY + int32_s(6), //#V2_2
   {
      W + W + W + W + W + W
   });

const Label DamLabels::Rain1 = Label(
   m_originX,
   m_originY,
   {
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1,
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1,
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1,
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1,
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1,
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1,
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1,
      R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1 + R1
   });

const Label DamLabels::Rain2 = Label(
   m_originX,
   m_originY,
   {
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2,
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2,
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2,
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2,
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2,
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2,
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2,
      R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2 + R2
   });