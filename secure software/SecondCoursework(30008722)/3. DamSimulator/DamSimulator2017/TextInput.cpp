#include "TextInput.h"

#include <iostream>
#include <iomanip>
#include "SecureConverter.h"

TextInput::TextInput(
   const int32_s& x,
   const int32_s& y,
   const std::string& label,
   const int32_s& minLength,
   const int32_s& maxLength)
   :
   Input(x, y, label),
   m_minLength(minLength),
   m_maxLength(maxLength)
{
}

bool TextInput::Show() //#V4_1
{
   ShowLabel();
   std::string inputText;
   std::cin >> std::setw(m_maxLength.GetValue()) >> inputText; //#V1_1

   uint32_s minLength = SecureConverter::Touint32(m_minLength); //Safely convert to unsigned to compare with size_t. //#V2_1
   if (std::cin.fail() || inputText.length() < minLength.GetValue())
   {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return false;
   }

   m_text = inputText;
   return true;
}
