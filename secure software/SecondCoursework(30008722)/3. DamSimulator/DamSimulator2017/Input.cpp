#pragma once
#include "Input.h"

#include "Console.h"

Input::Input(const int32_s& x, const int32_s& y, const std::string& label)
   :
   m_x(x),
   m_y(y),
   m_label(label)
{
}

void Input::ShowLabel() const
{
   Console::WriteLine(m_x, m_y, m_label);
}