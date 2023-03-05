#pragma once
#include "SecureInts.h"

//Allows various types to be safely converted to SecureInts.
//Throws std::exception if data is truncated.
class SecureConverter
{
public:
   static int16_s Toint16(const int32_s& value)
   {
      if (value.GetValue() < INT16_MIN || value.GetValue() > INT16_MAX)
      {
         throw std::exception("Conversion failed: Value will be truncated");
      }
      return static_cast<int16_t>(value.GetValue());
   }

   static int32_s Toint32(const double value)
   {
      if (value < static_cast<double>(INT32_MIN) || value > static_cast<double>(INT32_MAX))
      {
         throw std::exception("Conversion failed: Value will be truncated.");
      }
      return static_cast<int32_t>(value);
   }

   static int32_s Toint32(const uint32_s& value)
   {
      if (value.GetValue() > INT32_MAX)
      {
         throw std::exception("Conversion failed: Value will be truncated.");
      }
      return static_cast<int32_t>(value.GetValue());
   }

   static int32_s Toint32(const uint64_s& value)
   {
      if (value.GetValue() > INT32_MAX)
      {
         throw std::exception("Conversion failed: Value will be truncated.");
      }
      return static_cast<int32_t>(value.GetValue());
   }

   static int32_s Toint32(const size_t& value)
   {
      if (value > INT32_MAX)
      {
         throw std::exception("Conversion failed: Value will be truncated.");
      }
      return static_cast<int32_t>(value);
   }

   static uint32_s Touint32(const int32_s& value)
   {
      if (value.GetValue() < 0)
      {
         throw std::exception("Conversion failed: Value will be truncated.");
      }
      return static_cast<uint32_t>(value.GetValue());
   }

   static uint64_s Touint64(const int32_s& value)
   {
      if (value.GetValue() < 0)
      {
         throw std::exception("Conversion failed: Value will be truncated.");
      }
      return static_cast<uint64_s>(value.GetValue());
   }
};
