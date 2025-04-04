#include "ConsoleUtils.h"

//Here we define the ConsoleUtils functions that help with console operations

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
