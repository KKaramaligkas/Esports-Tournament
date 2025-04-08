#include "ConsoleUtils.h"

//To ConsoleUtils exei kapoies voithitikes functions gia to programma mas.

void pauseConsole() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nPress Enter to continue...";
    std::cin.get();
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
