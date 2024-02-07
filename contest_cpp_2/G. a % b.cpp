/*
Напишите программу, вычисляющую остаток от деления заданного «длинного» числа на заданную цифру.

Формат ввода

В первой строке задана цифра K (1 ≤ K ≤ 9). Во второй строке задано натуральное число N, состоящее из не более чем 250 цифр.

Формат вывода

Выведите остаток от деления N на K. 
*/

#include <iostream>

int longDiviser(std::string N, int K) {
    int R = 0;
    for (char i : N)
        R = (10*R + i - '0') % K;
    return R;
}

int main() {
    int K;
    std::string N;
    std::cin >> K >> N;
    std::cout << longDiviser(N, K);
    return 0;
}