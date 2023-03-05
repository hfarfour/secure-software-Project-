#pragma once
#include <string>
#include <windows.h>
#include "SecureInts.h"

//Static helper to be used when interacting with the Console.
class Console
{
public:

   static void Initialize(const int32_s& width, const int32_s& height);
   static void WriteLine(const int32_s& x, const int32_s& y, const std::string& text);
   static void WriteError(const std::string& text);
   static void Clear();

private:
   static HANDLE m_console;
   static int32_s m_width;
   static int32_s m_height;
};