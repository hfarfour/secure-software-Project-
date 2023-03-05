#pragma once
#include <string>
#include "SecureInts.h"

//Base class for user inputs.
class Input
{
public:
   Input(const int32_s& x, const int32_s& y, const std::string& label = "");
   virtual ~Input() {}
   virtual bool Show() = 0;

   std::string GetLabel() const { return m_label; }

protected:
   void ShowLabel() const;
   int32_s m_x;
   int32_s m_y;
   std::string m_label;
};
