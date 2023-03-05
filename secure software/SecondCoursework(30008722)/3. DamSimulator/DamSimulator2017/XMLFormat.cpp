#include "XMLFormat.h"

using namespace Logger;

XMLFormat::XMLFormat(std::unique_ptr<ILogger>& logger)
   :
   FormatDecorator(logger)
{}

void XMLFormat::Log(const std::string& message)
{
   auto strings = Split(message);

   std::string output = "<log>\n";
   for (auto& string : strings)
   {
      output += "   <item>" + string + "<item/>\n";
   }
   output += "<log/>";

   FormatDecorator::Log(output);
}
