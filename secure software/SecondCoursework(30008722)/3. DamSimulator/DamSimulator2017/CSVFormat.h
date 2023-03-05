#pragma once
#include "FormatDecorator.h"
#include <vector>

namespace Logger
{
   class CSVFormat : public FormatDecorator
   {
   public:
      CSVFormat(std::unique_ptr<ILogger>& logger);
      void Log(const std::string& message) override;
   private:
      char* CSVFormat::GetDelimiter() const;
   };
}

