#include "ConsoleLogger.h"

#include <iostream>

using namespace Logger;

void ConsoleLogger::Log(const std::string& message)
{
   std::cout << message << std::endl;
}
