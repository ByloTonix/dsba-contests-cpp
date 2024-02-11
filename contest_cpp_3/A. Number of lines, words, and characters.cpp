/*
The program receives a file as input. Determine how many letters (of the Latin alphabet), words, lines are in the file. Output the three computed numbers in the format given in the example. A word is a sequence of letters of the Latin alphabet.

To save memory, read the file character by character, that is, without saving the file or its individual lines in memory.

The solution has to include functional decomposition. Failure to follow the decomposition requirements will result in the lower score, even if the solution gets "OK" from the contest checker.

Requirements: Implement the solution as a function that takes an input stream object and returns the three computed values by reference. The function should take four arguments as input: input stream and three references for output. Use this function in the function `main()` to solve the problem.
Пример 1
Ввод
Вывод

Beautiful is better than ugly.
Explicit is better than implicit.
Simple is better than complex.
Complex is better than complicated.

Input file contains:
108 letters 
20 words 
4 lines 
*/

#include <iostream>
#include <fstream>

void counter(std::ifstream& file, int& letters, int& words, int& lines) {
    letters = 0, words = 0, lines = 0;
    bool isWord = 0;
    char c;

    while (file.get(c)) {
        if (isalpha(c)) {
            letters++;
            if (!isWord) {
                isWord = true;
                words++;
            }
        }
        else
            isWord = false;
        if (c == '\n')
            lines++;
    }
}

int main() {
    std::ifstream file("input.txt");

    int letters, words, lines;
    counter(file, letters, words, lines);
    std::cout << "Input file contains:" << '\n';
    std::cout << letters << " letters" << '\n';
    std::cout << words << " words" << '\n';
    std::cout << lines << " lines" << '\n';

    return 0;
}
