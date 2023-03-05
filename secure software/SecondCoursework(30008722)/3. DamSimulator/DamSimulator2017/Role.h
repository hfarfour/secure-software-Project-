#pragma once
#include <cstdint>

namespace Users
{
   enum class Role : int32_t
   {
      NoRole = 0,
      Visitor = 1,
      Employee = 2,
      Admin = 3
   };
}