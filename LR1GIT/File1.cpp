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
    std::cout << "Введіть число, вихідну й цільову основу через пробіл: ";
    std::string line;
    std::getline(std::cin, line);

    if (line.empty())
    {
        std::cout << "Не введено жодного значення. "
            << "Очікується: число, вихідна й цільова основа." << std::endl;
        return 1;
    }

    std::istringstream in(line);
    std::string number, extra;
    int fromBase = 0, toBase = 0;
    if (!(in >> number >> fromBase >> toBase) || (in >> extra))
    {
        std::cout << "Потрібно рівно три значення: число та дві основи (цілі числа)." << std::endl;
        return 1;
    }

    if (fromBase < 2 || fromBase > 16 || toBase < 2 || toBase > 16)
    {
        std::cout << "Основа має бути цілим числом від 2 до 16." << std::endl;
        return 1;
    }

    for (char c : number)
    {
        int d = digitValue(c);
        if (d < 0 || d >= fromBase)
        {
            std::cout << "Число містить цифру, недопустиму для основи "
                << fromBase << "." << std::endl;
            return 1;
        }
    }

    std::cout << fromValue(toValue(number, fromBase), toBase) << std::endl;

    return 0;
}