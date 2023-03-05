#pragma once
#include "ILogger.h"

#include <memory>
#include <string>
#include <vector>

namespace Logger
{
   class FormatDecorator : public ILogger
   {
   public:
      FormatDecorator(std::unique_ptr<ILogger>& logger);

   protected:
      void Log(const std::string& message) override;
      static std::vector<std::string> Split(const std::string& message);

   private:
      std::unique_ptr<ILogger> m_logger;
   };
}
