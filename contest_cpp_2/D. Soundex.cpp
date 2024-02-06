/*
The well-known Soundex algorithm (https://ru.wikipedia.org/wiki/Soundex) determines whether two English words are similar in sound.
At the entrance he takes the word and replaces it with some four-character code. If the codes of two words match, then the words, as a rule, sound similar.

You need to implement this algorithm. It works like this:

    The first letter of the word is saved.
    The rest of the word:
        letters, denoting, as a rule, vowels: a, e, h, i, o, u, w и y — discarded;
        the remaining letters (consonants) are replaced with numbers from 1 to 6, with the same numbers corresponding to the sound of the letters:
        1: b, f, p, v
        2: c, g, j, k, q, s, x, z
        3: d, t
        4: l
        5: m, n
        6: r
    Any sequence of identical numbers is reduced to one such number.
    The final line is truncated to the first four characters. If the length of the string is less than the required, the missing characters are replaced by a 0.

Examples:
аmmonium → ammnm → a5555 → a5 → a500
implementation → implmnttn → i51455335 → i514535 → i514

The solution has to include functional decomposition.
Failure to follow the decomposition requirements will result in the lower score, even if the solution gets "OK" from the contest checker.

Requirements: Implement the solution as a function that takes a word as input and returns its Soundex representation as output.
Use this function in the function main() to solve the problem.

Input format

The input is one non-empty word, written in lowercase Latin letters. The word length does not exceed 20 characters.
Output format

Type a four-letter code for the word.
*/

#include <iostream>

std::string removeVowels(std::string s) {
    std::string str;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != 'a' and s[i] != 'e' and s[i] != 'h' and s[i] != 'i' and s[i] != 'o' and s[i] != 'u' and s[i] != 'w' and s[i] != 'y') {
            str += s[i];
        }
    }
    return str;
}

std::string replaceLetter(std::string s) {
    std::string str;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == 'b' or s[i] == 'f' or s[i] == 'p' or s[i] == 'v')
            str += '1';
        else if (s[i] == 'c' or s[i] == 'g' or s[i] == 'j' or s[i] == 'k' or s[i] == 'q' or s[i] == 's' or s[i] == 'x' or s[i] == 'z')
            str += '2';
        else if (s[i] == 'd' or s[i] == 't')
            str += '3';
        else if (s[i] == 'l')
            str += '4';
        else if (s[i] == 'm' or s[i] == 'n')
            str += '5';
        else if (s[i] == 'r')
            str += '6';
        else
            str += s[i];
        }
    return str;
}

std::string numberReducer(std::string s) {
    std::string str, str2;
    str[0] = s[0];
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i+1] != s[i])
            str += s[i];
    }
    str += "000";
    for (size_t i = 0; i < 3; i++)
        str2 += str[i];
    return str2;
}

int main() {
    std::string s, t;
    std::cin >> s;
    t = s[0];
    s = s.substr(1, s.length());
    s = removeVowels(s);
    s = replaceLetter(s);
    s = numberReducer(s);
    s = t + s;
    std::cout << s;   
}