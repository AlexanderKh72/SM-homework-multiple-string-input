// multiple_string_input.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

const int MAX_LEN{ 50 }, CP_MLT{ 10 }, CP_INIT{ 10 };

int main()
{
    char** strings;
    char buffer[MAX_LEN] = {};
    char** temp = nullptr;

    strings = new char* [CP_INIT];
    size_t cp{ CP_INIT }, sz{ 0 }; // capacity, size

    std::cout << "*** - end of input\nmax string length = " << MAX_LEN << std::endl;
    std::cin >> buffer;
    for (; strcmp(buffer, "***"); std::cin >> buffer, ++sz)
    {
        if (sz == cp)
        {
            temp = new char* [cp * CP_MLT];
            for (size_t i = 0; i < sz; ++i)
                temp[i] = strings[i];
            delete[] strings;
            strings = temp;
            cp *= CP_MLT;
            delete[] temp;
        }
        strings[sz] = new char[strlen(buffer)];
        strcpy(strings[sz], buffer);
    }

    for (size_t i = 0; i < sz; ++i)
        std::cout << strings[i] << std::endl;

    return 0;
}
