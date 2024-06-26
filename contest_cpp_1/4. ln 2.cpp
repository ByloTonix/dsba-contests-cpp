/*
По данному числу n вычислите сумму (-1)^{n+1}/n.
Операцией возведения в степень пользоваться нельзя.
Алгоритм должен иметь сложность O(n).
Попробуйте также обойтись без использования инструкции if.
Формат ввода

Вводится натуральное число.
Формат вывода

Выведите ответ на задачу. 
*/

#include <iostream>

int main() {
    int n;
    double b = 0;
    std::cin >> n;
    for (double i = 0; i < n; i++) {
        if ((int) i % 2 == 0) {
            b = b + (1 / (i + 1));
        }
        else {
            b = b - (1 / (i+1));
        }
    }
    std::cout << b;
    return 0;
}
