/*
Write a join function in C++ with the following header:

std::string join(const std::vector<std::string>& tokens, char delimiter);

The function should return the string obtained by joining the elements of the vector with the specified separator.
*/
std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string string;

    for (size_t i = 0; i < tokens.size(); i++) {
        string += tokens[i];
        if (tokens.size() - 1 != i)
            string += delimiter;
    }

    return string;    
}