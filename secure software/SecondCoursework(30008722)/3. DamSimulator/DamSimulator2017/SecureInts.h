#pragma once
#include <cinttypes>
#include <stdexcept>
#include <limits>

//Templated class allows for creation of custom Secure types.
//Any arithmetic that causes an overflow is detected and an std::exception is thrown.
//Constructed with a Type, Minimum and Maximum value.
//Reference for boundary checking: https://www.securecoding.cert.org/confluence/x/RgE
template <class T, T min, T max> class int_s
{
public:
   //Implicit constructor.
   int_s(const T& value)
      :
      m_value(value),
      m_min(min),
      m_max(max)
   {
   }

   //Assignment operator.
   void operator= (const int_s& rhs)
   {
      m_value = rhs.m_value;
   }

   //Comparison operators with int_s.
   bool operator== (const int_s& rhs) const
   {
      return m_value == rhs.m_value;
   }   
   bool operator!= (const int_s& rhs) const
   {
      return m_value != rhs.m_value;
   }
   bool operator< (const int_s& rhs) const
   {
      return m_value < rhs.m_value;
   }
   bool operator<= (const int_s& rhs) const
   {
      return m_value <= rhs.m_value;
   }
   bool operator> (const int_s& rhs) const
   {
      return m_value > rhs.m_value;
   }
   bool operator>= (const int_s& rhs) const
   {
      return m_value >= rhs.m_value;
   }

   //Comparison operators with non-secure type because will not overflow.
   bool operator== (const T& rhs) const
   {
      return m_value == rhs;
   }
   bool operator!= (const T& rhs) const
   {
      return m_value != rhs;
   }
   bool operator< (const T& rhs) const
   {
      return m_value < rhs;
   }
   bool operator<= (const T& rhs) const
   {
      return m_value <= rhs;
   }
   bool operator> (const T& rhs) const
   {
      return m_value > rhs;
   }
   bool operator>= (const T& rhs) const
   {
      return m_value >= rhs;
   }

   //Arithmetic operators with overflow checks.
   int_s operator+ (int_s& rhs) const
   {
      if (((rhs.m_value > 0) && (m_value > (m_max - rhs.m_value))) ||
         ((rhs.m_value < 0) && (m_value < (m_min - rhs.m_value))))
      {
         throw overflowException;
      }
      return m_value + rhs.m_value;
   }
   int_s operator- (int_s& rhs) const
   {
      if (((rhs.m_value > 0) && (m_value < m_min + rhs.m_value)) ||
         ((rhs.m_value < 0) && (m_value > m_max + rhs.m_value)))
      {
         throw overflowException;
      }
      return m_value - rhs.m_value;
   }
   int_s operator* (int_s& rhs) const
   {
      if (m_value > 0) //m_value is positive.
      {
         if (rhs.m_value > 0) //m_value and rhs.m_value are positive.
         {
            if (m_value > (m_max / rhs.m_value))
            {
               throw overflowException;
            }
         }
         else //m_value positive, rhs.m_value non-positive.
         {
            if (rhs.m_value < (m_min / m_value))
            {
               throw overflowException;
            }
         }
      }
      else //m_value is non-positive.
      {
         if (rhs.m_value > 0) //m_value is non-positive, rhs.m_value is positive.
         {
            if (m_value < (m_min / rhs.m_value))
            {
               throw overflowException;
            }
         }
         else //m_value and rhs.m_value are non-positive.
         {
            if ((m_value != 0) && (rhs.m_value < (m_max / m_value)))
            {
               throw overflowException;
            }
         }
      }
      return m_value * rhs.m_value;
   }

   int_s operator/ (const int_s& rhs) const
   {
      if ((rhs.m_value == 0) || ((m_value == m_min) && (rhs.m_value == -1)))
      {
         throw overflowException;
      }
      return m_value / rhs.m_value;
   }

   int_s operator% (const int_s& rhs) const
   {
      if((rhs.m_value == 0) || ((m_value == m_min) && (rhs.m_value == -1)))
      {
         throw overflowException;
      }
      return m_value % rhs.m_value;
   }

   //Return value as base type.
   T GetValue() const { return m_value; }

private:
   T m_value = 0;
   T m_min = 0;
   T m_max = 0;
   
   const std::exception overflowException = std::exception("SecureInt arithmetic failed: Overflow detected.");
};

typedef int_s<int64_t, INT64_MIN, INT64_MAX> int64_s;
typedef int_s<int32_t, INT32_MIN, INT32_MAX> int32_s;
typedef int_s<int16_t, INT16_MIN, INT16_MAX> int16_s;
typedef int_s<uint64_t, 0, UINT64_MAX> uint64_s;
typedef int_s<uint32_t, 0, UINT32_MAX> uint32_s;
typedef int_s<uint16_t, 0, UINT16_MAX> uint16_s;
