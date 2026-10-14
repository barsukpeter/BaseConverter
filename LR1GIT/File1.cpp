#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::cout << "¬вед≥ть число, вих≥дну й ц≥льову основу через проб≥л: ";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream in(line);
    std::string number;
    int fromBase = 0, toBase = 0;
    in >> number >> fromBase >> toBase;
    std::cout << number << " " << fromBase << " " << toBase << std::endl;

    return 0;

}