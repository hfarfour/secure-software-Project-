#pragma once
#include "ILogger.h"

#include <string>
#include <fstream>

namespace Logger
{
   class FileLogger : public ILogger
   {
   public:
      FileLogger(const std::string& filePath);
      ~FileLogger();
      void Log(const std::string& message) override;

   private:
      std::string m_filePath;
      std::ofstream m_outputStream;
   };
}
