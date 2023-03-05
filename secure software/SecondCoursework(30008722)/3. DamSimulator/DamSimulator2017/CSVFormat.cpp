#include "CSVFormat.h"

using namespace Logger;

CSVFormat::CSVFormat(std::unique_ptr<ILogger>& logger)
   :
   FormatDecorator(logger)
{
}

char* CSVFormat::GetDelimiter() const
{
   return ","; //Demo code, could return null pointer...
}

void CSVFormat::Log(const std::string& message)
{
   auto strings = Split(message);
   std::string output;

   //Demo code to show how to not initialize a string from a null pointer.
   const char* delimitierChar = GetDelimiter();
   if (delimitierChar != nullptr) //#V1_2 #V6_1
   {
      std::string delimitier(delimitierChar);

      for (auto& string : strings)
      {
         output += string + delimitier; //#2_2
      }

      FormatDecorator::Log(output);
   }
}
