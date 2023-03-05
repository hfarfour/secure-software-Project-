#include "Model.h"
#include "ConsoleView.h"
#include "Controller.h"
#include "Console.h"
#include <iostream>

int main()
{
   try
   {
      SetConsoleTitle(L"DamSimulator2017");

      Model model;
      ConsoleView view;
      Controller controller(model, view);
   }
   catch(const std::exception& e)
   {
      Console::Clear();

      std::string errorMessage = "An unexpected error has occurred:\n";
      errorMessage += e.what() + std::string("\n");
      errorMessage += "The application will be safely terminated.\n";
      std::cout << errorMessage << std::endl;
      system("pause");
   }
   catch (...)
   {
      Console::Clear();

      std::string errorMessage = "An unexpected error has occurred:\n";
      errorMessage += "The application will be safely terminated.\n";
      std::cout << errorMessage << std::endl;
      system("pause");
   }
}
