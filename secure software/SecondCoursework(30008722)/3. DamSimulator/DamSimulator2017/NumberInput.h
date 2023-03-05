#pragma once
#include "Input.h"
#include "SecureInts.h"

//Get user input number from the Console.
class NumberInput : public Input
{
public:
   NumberInput(
      const int32_s& x,
      const int32_s& y,
      const std::string& label = "",
      const int32_s& min = int32_s(0),
      const int32_s& max = int32_s(1000));

   //Draws the label and waits for user input at the x, y position.
   bool Show() override;

   //After Show has been called, returns value of user input.
   int32_s GetValue() const { return m_value; }

private:
   int32_s m_value = int32_s(0);
   int32_s m_min; //Inclusive
   int32_s m_max; //Inclusive
};