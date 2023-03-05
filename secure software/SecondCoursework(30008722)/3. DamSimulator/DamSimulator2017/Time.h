#pragma once
#include <string>
#include "SecureInts.h"

struct Time
{
   Time(const int32_s& hours, const int32_s& minutes)
      :
      m_hours(hours),
      m_minutes(minutes)
   {}

   int32_s Minutes() const
   {
      return m_minutes;
   }

   int32_s Hours() const
   {
      return m_hours;
   }

   std::string ToString() const
   {
      auto hoursString = std::to_string(m_hours.GetValue());
      if(hoursString.length() < 2)
      {
         hoursString = "0" + hoursString;
      }

      auto minutesString = std::to_string(m_minutes.GetValue());
      if (minutesString.length() < 2)
      {
         minutesString = "0" + minutesString;
      }

      return hoursString + ":" + minutesString;
   }

private:
   int32_s m_hours = 0;
   int32_s m_minutes = 0;
};