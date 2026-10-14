#include <iostream>
#include <string>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "¬вед≥ть число, вих≥дну й ц≥льову основу через проб≥л: ";
    std::string line;
    std::getline(std::cin, line);
    return 0;
}
