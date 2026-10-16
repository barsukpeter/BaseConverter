#define NOMINMAX
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>

int digitValue(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return -1;
}

bool toValue(const std::string& digits, int base, unsigned long long& value)
{
    value = 0;
    for (char c : digits)
    {
        int d = digitValue(c);
        if (d < 0 || d >= base)
            return false;
        if (value > (std::numeric_limits<unsigned long long>::max() - d) / base)
            return false;
        value = value * base + d;
    }
    return true;
}

std::string fromValue(unsigned long long value, int base)
{
    if (value == 0) return "0";
    const char* digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result;
    while (value > 0)
    {
        result.insert(result.begin(), digits[value % base]);
        value /= base;
    }
    return result;
}

bool validBase(int base)
{
    return base >= 2 && base <= 36;
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

    if (!validBase(fromBase))
    {
        std::cout << "Вихідна основа " << fromBase
            << " недопустима: потрібно ціле число від 2 до 36." << std::endl;
        return 1;
    }

    if (!validBase(toBase))
    {
        std::cout << "Цільова основа " << toBase
            << " недопустима: потрібно ціле число від 2 до 36." << std::endl;
        return 1;
    }

    for (char c : number)
    {
        int d = digitValue(c);
        if (d < 0 || d >= fromBase)
        {
            std::cout << "Символ '" << c << "' недопустимий для основи "
                << fromBase << "." << std::endl;
            return 1;
        }
    }

    unsigned long long value = 0;
    if (!toValue(number, fromBase, value))
    {
        std::cout << "Число занадто велике для обробки." << std::endl;
        return 1;
    }

    std::cout << fromValue(value, toBase) << std::endl;
    return 0;
}