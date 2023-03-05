#pragma once
#include <string>
#include <vector>
#include "SecureInts.h"

class Label
{
public:
   Label(const int32_s& x, const int32_s& y, const std::string& text = "");
   Label(const int32_s& x, const int32_s& y, const std::vector<std::string>& text);
   void Show() const;
   void SetLabel(const std::string& text);
   void SetLabel(const std::vector<std::string>& text);

protected:
   int32_s m_x;
   int32_s m_y;
   std::vector<std::string> m_text;
};
