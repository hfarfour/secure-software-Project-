#include "LoggerFactory.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "CSVFormat.h"
#include "XMLFormat.h"

using namespace Logger;

ILogger* LoggerFactory::CreateLogger(const Type& outputType, const Format& formatType)
{
   std::unique_ptr<ILogger> logger;

   switch(outputType)
   {
      case Type::Console:
      {
         logger = std::make_unique<ConsoleLogger>(); //#V6_2
         break;
      }
      case Type::File:
      {
         //Log to same folder as executable.
         logger = std::make_unique<FileLogger>("Dam.log"); //#V6_2
         break;
      }
      case Type::None:
      default:
      {
         return nullptr;
      }
   }

   switch (formatType)
   {
      case Format::CSV:
      {
         return new CSVFormat(logger); //#V3_1
      }
      case Format::XML:
      {
         return new XMLFormat(logger); //#V3_1
      }
      case Format::None:
      default:
      {
         return new FormatDecorator(logger); //#V3_1
      }
   }
}