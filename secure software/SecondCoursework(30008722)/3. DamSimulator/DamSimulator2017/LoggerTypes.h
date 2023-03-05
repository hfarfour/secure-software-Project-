#pragma once
#include <cstdint>

namespace Logger
{
   enum class Type : int32_t
   {
      None = 0,
      Console = 1,
      File = 2
   };

   enum class Format :int32_t
   {
      None = 0,
      CSV = 1,
      XML = 2
   };
}
