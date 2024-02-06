/*
A string consisting of lowercase Latin letters and spaces is given.
Check whether it is a palindrome without spaces (eg, "no lemon no melon").

The solution has to include functional decomposition.
Failure to follow the decomposition requirements will result in the lower score, even if the solution gets "OK" from the contest checker.

Requirement: Implement the solution as a function that takes a string as input and returns true/false depending on whether the string is a palindrome or not.
Use this function in the function `main()` to solve the problem.
Формат ввода

The input is 1 line of not more than 100 characters, including spaces. There can be an arbitrary number of spaces between words.
Формат вывода

Output "yes" if the given string is a palindrome, and "no" otherwise. 
*/

#include <iostream>

bool isPalindrome(std::string s) {
    for (size_t i = 0; i < s.length()/2; i++) {
        if (i == s.length()/2) {
            if (tolower(s[i]) != tolower(s[s.length()-i]))
                return 0;
        } 
        else {
            if (tolower(s[i]) != tolower(s[s.length()-i-1]))
                return 0;
        }
    }
    return 1;
}

std::string removeSpaces(std::string s) {
    std::string str;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
            str += s[i];
    }
    return str;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string str = removeSpaces(s);
    if (isPalindrome(str))
        std::cout << "yes";
    else
        std::cout << "no";
    return 0;
}