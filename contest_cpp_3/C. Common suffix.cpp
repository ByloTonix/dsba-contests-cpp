/*
Write the function std::string common_suffix(const std::string& a, const std::string& b), which returns the largest common suffix of these two strings.

(The suffix of a string is any substring of this string that includes its end. For example, the suffixes of the word apple are the empty string, e, le, ple, pple, apple. For apple and tuple, the greatest common suffix is ple.)
Примечания

Your solution should have only this function. We will test its work using our main function. 
*/
std::string common_suffix(const std::string& a, const std::string& b) {
    int c = a.length(), d = b.length(), len = std::min(c, d);

    std::string suffix;

    for (size_t i = 1; i <= len; i++) {
        if (a.substr(c - i) == b.substr(d - i))
            suffix = a.substr(c - i);
        else
            break;
    }

    return suffix;
}