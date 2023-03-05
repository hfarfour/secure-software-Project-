#include "Console.h"

#include <cinttypes>
#include <iostream>
#include "SecureConverter.h"

HANDLE Console::m_console;
int32_s Console::m_width(200);
int32_s Console::m_height(100);

void Console::Initialize(const int32_s& width, const int32_s& height)
{
   m_width = width;
   m_height = height;
   m_console = GetStdHandle(STD_OUTPUT_HANDLE);

   CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
   GetConsoleScreenBufferInfo(m_console, &bufferInfo);

   int16_s int16Width = SecureConverter::Toint16(width); //#V2_3
   int16_s int16Height = SecureConverter::Toint16(height); //#V2_3

   SMALL_RECT rectangle = {
      0,
      0,
      (int16Width - int16_s(1)).GetValue(), //#V2_2
      (int16Height - int16_s(1)).GetValue() }; //#V2_2

   SetConsoleWindowInfo(m_console, TRUE, &rectangle);

   COORD size = { int16Width.GetValue(), int16Height.GetValue() };
   SetConsoleScreenBufferSize(m_console, size);

   CONSOLE_CURSOR_INFO cursorInfo;
   GetConsoleCursorInfo(m_console, &cursorInfo);
   cursorInfo.bVisible = false;
   SetConsoleCursorInfo(m_console, &cursorInfo);
}

void Console::WriteLine(const int32_s& x, const int32_s& y, const std::string& text)
{
   int32_s textLength = SecureConverter::Toint32(text.length()); //#V2_3
   if (x >= 0 && y >= 0 && x <= m_width - textLength && y < m_height) //#V2_2
   {
      int16_s xPosition = SecureConverter::Toint16(x); //#V2_3
      int16_s yPosition = SecureConverter::Toint16(y); //#V2_3

      COORD position = { xPosition.GetValue(), yPosition.GetValue() };
      SetConsoleCursorPosition(m_console, position);

      std::cout << text; //#V1_1
   }
}

void Console::Clear()
{
   COORD coordScreen = { 0, 0 };
   DWORD cCharsWritten = 0;
   CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
   GetConsoleScreenBufferInfo(m_console, &bufferInfo);

   int32_s consoleSize = int32_s(bufferInfo.dwSize.X) * int32_s(bufferInfo.dwSize.Y); //#V2_2

   uint32_s consoleSizeUnsigned = SecureConverter::Touint32(consoleSize); //#V2_1

   FillConsoleOutputCharacter(m_console, TEXT(' '), consoleSizeUnsigned.GetValue(), coordScreen, &cCharsWritten);
   GetConsoleScreenBufferInfo(m_console, &bufferInfo);
   FillConsoleOutputAttribute(m_console, bufferInfo.wAttributes, consoleSizeUnsigned.GetValue(), coordScreen, &cCharsWritten);
   
   SetConsoleCursorPosition(m_console, coordScreen);
}

void Console::WriteError(const std::string& text)
{
   WriteLine(1, m_height - int32_s(1), text); //#V2_2
}
