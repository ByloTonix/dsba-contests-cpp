/*
Write a split function in C++ with the following prototype:

std::vector<std::string> split(const std::string& str, char delimiter);

The function must return the vector of strings obtained by splitting the string str into parts by the specified delimiter character. If the separator is encountered at the beginning or at the b of the line, then at the beginning (respectively, at the b) of the vector with the result there must be an empty string.
If two separators meet next to each other, then an empty string between them should also be returned.
*/

#include <vector>
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::string token;
    std::vector<std::string> result;
    short int a = 0, b;

    while ((b = str.find(delimiter, a)) != std::string::npos) {
        token = str.substr(a, b - a);
        a = b + 1;
        result.push_back(token);
    }

    result.push_back(str.substr(a));
    return result;
}