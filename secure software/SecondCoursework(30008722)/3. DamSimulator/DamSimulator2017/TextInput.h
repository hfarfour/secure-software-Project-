#pragma once
#include "Input.h"

//Get user input text from the Console.
class TextInput : public Input
{
public:
   TextInput(
      const int32_s& x,
      const int32_s& y,
      const std::string& label = "",
      const int32_s& minLength = int32_s(0),
      const int32_s& maxLength = int32_s(30));

   //Draws the label and waits for user input at the x, y position.
   bool Show() override;

   //After Show has been called, returns text of user input.
   std::string GetText() const { return m_text; }

private:
   std::string m_text;
   int32_s m_minLength;
   int32_s m_maxLength;
};