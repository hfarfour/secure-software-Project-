#pragma once
#include "FormatDecorator.h"
#include <vector>
#include <memory>
#include "ILogger.h"

namespace Logger
{
   class XMLFormat : public FormatDecorator
   {
   public:
      XMLFormat(std::unique_ptr<ILogger>& logger);
      void Log(const std::string& data) override;
   };
}

