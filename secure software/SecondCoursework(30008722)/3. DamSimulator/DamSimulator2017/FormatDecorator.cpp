#include "FormatDecorator.h"
#include <iostream>

using namespace Logger;

FormatDecorator::FormatDecorator(std::unique_ptr<ILogger>& logger)
   :
   m_logger(std::move(logger))
{
}

void FormatDecorator::Log(const std::string& message)
{
   m_logger->Log(message);
}

std::vector<std::string> FormatDecorator::Split(const std::string& message)
{
   std::string delimiter = " ";
   std::string input = message;
   std::vector<std::string> output;
   size_t position = std::string::npos;

   do
   {
      position = input.find(delimiter);
      output.push_back(input.substr(0, position));

      if (position != std::string::npos)
      {
         input = input.substr(position + delimiter.size());
      }

   } while (position != std::string::npos);

   return output;
}