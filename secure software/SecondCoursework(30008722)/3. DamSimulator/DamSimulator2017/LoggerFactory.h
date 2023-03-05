#pragma once
#include "ILogger.h"
#include "LoggerTypes.h"

#include <memory>

namespace Logger
{
   class LoggerFactory
   {
   public:
      static ILogger* CreateLogger(const Type& outputType, const Format& formatType);
   };
}
