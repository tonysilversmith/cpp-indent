#include <iostream>
#include <Windows.h>

namespace tss
{
    void indentLeft(std::string str, size_t ConsoleBufferWidth = 80, char ToBeFilled = ' ', bool TerminateToNewLine = false)
    {
        size_t len = str.length();
        int spaces = static_cast<int>(ConsoleBufferWidth - len);
        if (spaces >= 0)
        {
            for (size_t i = 0; i < spaces; i++)
            {
                std::cout << ToBeFilled;
            }
            std::cout << str;
        }
        else
        {
            std::cout << str;
        }
        if (TerminateToNewLine == true)
        {
            std::cout << std::endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    int width = info.srWindow.Right - info.srWindow.Left + 1;
    std::string str;
    do
    {
        std::cout << "hello, Enter something  : ";
        getline(std::cin, str);
        std::cout << "\r";
        std::cout << "Your input was : ";
        std::cout << str << std::endl;
        tss::indentLeft(str, 20, ' ', false);
        tss::indentLeft(str, 20, ' ', true);
    } while (true);
    return 0;
}