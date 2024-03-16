#include <iostream>
#include <set>
#include <vector>

int main()
{

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, k;
    std::cin >> n >> k;
    // храним всю введённую строку
    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }
    // срез от начала до K и хранение в multiset
    std::multiset<int> window_numbers(numbers.begin(), numbers.begin() + k);
    for (int i = 0; i <= n - k; i++)
    {
        // multiset уже отсортирован
        std::cout << *window_numbers.begin() << "\n";

        if (i < n - k)
        {
            // обновление окна при сдвиге
            window_numbers.erase(window_numbers.find(numbers[i]));
            window_numbers.insert(numbers[i + k]);
        }
    }

    return 0;
}