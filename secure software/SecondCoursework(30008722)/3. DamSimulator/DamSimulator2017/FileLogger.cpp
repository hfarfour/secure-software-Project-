#include "FileLogger.h"

#include <iostream>
#include "Console.h"

using namespace Logger;

FileLogger::FileLogger(const std::string& filePath)
   :
   m_filePath(filePath)
{
   try
   {
      m_outputStream.open(filePath, std::ios::out); //#V5_1
   }
   catch (std::ofstream::failure)
   {
      Console::WriteError("Exception opening file.");
   }
}

FileLogger::~FileLogger()
{
   try
   {
      if (!m_outputStream.fail()) //#V5_1
      {
         m_outputStream.close(); //#V5_2
      }
   }
   catch (std::ofstream::failure)
   {
      Console::WriteError("Exception closing file.");
   }
}

void FileLogger::Log(const std::string& message)
{
   try
   {
      if (!m_outputStream.fail()) //#V5_1
      {
         m_outputStream << message << std::endl << std::flush;
      }
   }
   catch (std::ofstream::failure)
   {
      Console::WriteError("Exception writing to file.");
   }
}
