#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

int digitValue(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;
}

unsigned long long toValue(const std::string& digits, int base)
{
    unsigned long long value = 0;
    for (char c : digits)
        value = value * base + digitValue(c);
    return value;
}

std::string fromValue(unsigned long long value, int base)
{
    if (value == 0) return "0";
    const char* digits = "0123456789ABCDEF";
    std::string result;
    while (value > 0)
    {
        result.insert(result.begin(), digits[value % base]);
        value /= base;
    }
    return result;
}

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
    std::cout << fromValue(toValue(number, fromBase), toBase) << std::endl;

    return 0;

}