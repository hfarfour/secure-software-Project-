#pragma once
#include "ILogger.h"

#include <string>
#include <fstream>

namespace Logger
{
   class ConsoleLogger : public ILogger
   {
   public:
      virtual ~ConsoleLogger() {}
      void Log(const std::string& message) override;
   };
}
