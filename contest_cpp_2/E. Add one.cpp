/*
Write a program that adds 1 to the natural number N (the length of the number N is up to 1000 characters).

Decomposition requirement: Implement the solution as a function that takes a number N and returns the number N+1.
You may choose the exact type of input argument and the returned value, to fit your representation of the number.
Use this function in the function main() to solve the problem.

Формат ввода

A single line containing the number N
Формат вывода

The number N + 1
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>

const int LEN = 1001;

char *addOne(char*, char*);

int main()
{
    char s[LEN];
    char result[LEN + 1];
    std::cin >> s;
    std::cout << addOne(s, result) << std::endl;
    return 0;
}

char *addOne(char *s, char *result)
{
    size_t slen = strlen(s);

    if (s[slen - 1] != '9')
        s[slen - 1]++;
    else
    {
        s[slen - 1] = '0';
        for (int i = slen - 2; i >= 0; i--)
        {
            if (s[i] == '9')
                s[i] = '0';
            else
            {
                s[i]++;
                break;
            }
        }

        if (s[0] == '0')
        {
            result[0] = '1';
            for (size_t i = 0; i < LEN; i++)
                result[i + 1] = s[i];
            return result;
        }
    }
    return s;
}
