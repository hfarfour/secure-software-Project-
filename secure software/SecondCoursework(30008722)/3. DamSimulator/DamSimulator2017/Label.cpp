#include "Label.h"
#include "Console.h"
#include "SecureInts.h"

Label::Label(const int32_s& x, const int32_s& y, const std::string& text)
   :
   m_x(x),
   m_y(y),
   m_text({ text })
{
}

Label::Label(const int32_s& x, const int32_s& y, const std::vector<std::string>& text)
   :
   m_x(x),
   m_y(y),
   m_text(text)
{
}

void Label::Show() const
{
   //Using range-based loop instead of indexed loop, as it eliminates type conversion in this case.
   int32_s i = 0;
   for (auto& line : m_text)
   {
      Console::WriteLine(m_x, m_y + i, line); //#V2_2
      i = i + int32_s(1); //#V2_2
   }
}

void Label::SetLabel(const std::string& text)
{
   m_text = { text };
}

void Label::SetLabel(const std::vector<std::string>& text)
{
   m_text = text;
}