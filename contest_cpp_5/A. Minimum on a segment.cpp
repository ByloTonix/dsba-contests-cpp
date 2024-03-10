// Consider a sequence of integers of length n. The window of length k moves
// along it with step 1.

// The is, at the start the first k numbers are in the window, at the next step
// the window will contain k numbers, starting with the second one, and so on
// until the end of the sequence.

// Find the minimum of numbers in the window for each position of it.
// Input format

// The first line of input contains two natural numbers n and k (n ≤ 150000, k ≤
// 10000, k ≤ n) - the length of the sequence and the window, respectively. The
// next line contains n numbers - the sequence itself. Output format

// The output must contain n - k + 1 lines - the minimum for each position of
// the « window ». Sample Input Output

// 7 3
// 1 3 2 4 5 3 1

// 1
// 2
// 2
// 3
// 1

// Notes

// Please note that a solution with a direct calculation of the minimum for each
// window position will not pass the time limit. One way to solve the problem is
// to use the std::multiset container to store the contents of the window and
// quickly get the minimum. Read more about std::multiset here:
// http://en.cppreference.com/w/cpp/container/multiset.

#include <iostream>
#include <set> //  для multiset
#include <vector>

int main()
{
  // спидхак
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, k, x;
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