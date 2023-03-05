#pragma once
#include "NumberInput.h"

#include <iostream>

NumberInput::NumberInput(
   const int32_s& x,
   const int32_s& y,
   const std::string& label,
   const int32_s& min,
   const int32_s& max)
   :
   Input(x, y, label),
   m_min(min),
   m_max(max)
{
}

bool NumberInput::Show()
{
   ShowLabel();
   int32_t inputValue;
   std::cin >> inputValue; //#V1_1
   int32_s secureInputValue(inputValue);

   if(std::cin.fail() || secureInputValue > m_max || secureInputValue < m_min)
   {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return false;
   }

   m_value = secureInputValue;
   return true;
}