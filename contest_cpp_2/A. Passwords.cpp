/*
Vasya wants to change his email password, because he is afraid that his mailbox might have been hacked.
According to the rules, a new password must meet the following restrictions:

    consist of ASCII table characters with codes from 33 to 127;
    be at least 8 characters and no longer than 14;
    from 4 classes of symbols - large letters, small letters, numbers, other symbols - at least three of any should be present in the password.

Help Vasya to write a program that will verify that his new password is valid.

The solution has to include functional decomposition.
Failure to follow the decomposition requirements will result in the lower score, even if the solution gets "OK" from the contest checker.
You may add extra functions in addition to the required ones. This rule applies to all tasks in the contest.

Requirement: Implement the solution as a function that takes a password as input and returns true/false for passwords that fit or don't fit the restrictions.
Use this function in the function main() to solve the problem.
Формат ввода

The program receives one line as input - Vasya's new password.
Формат вывода

Output YES, if Vasya's password meets the requirements, and NO otherwise.
*/

/*
Vasya wants to change his email password, because he is afraid that his mailbox might have been hacked. According to the rules, a new password must meet the following restrictions:

    consist of ASCII table characters with codes from 33 to 127;
    be at least 8 characters and no longer than 14;
    from 4 classes of symbols - large letters, small letters, numbers, other symbols - at least three of any should be present in the password.

Help Vasya to write a program that will verify that his new password is valid.

The solution has to include functional decomposition. Failure to follow the decomposition requirements will result
in the lower score, even if the solution gets "OK" from the contest checker. You may add extra functions in addition to the required ones.
This rule applies to all tasks in the contest.

Requirement: Implement the solution as a function that takes a password as input and returns true/false for passwords that fit
or don't fit the restrictions. Use this function in the function main() to solve the problem.
Формат ввода

The program receives one line as input - Vasya's new password.
Формат вывода

Output YES, if Vasya's password meets the requirements, and NO otherwise.
Vasya123 YES
*/

#include <iostream>

bool passwdChecker(std::string passwd) {
    bool caps = 0, lows = 0, nums = 0, other = 0;
    if (passwd.length() >= 8 and passwd.length() <= 14)
        for (size_t i = 0; i < passwd.length(); i++) {
            if (char(passwd[i]) >= 33 and char(passwd[i] <= 127)) {
                if (char(passwd[i]) >= 48 and char(passwd[i]) <= 57)
                    nums = 1;
                else if (char(passwd[i]) >= 65 and char(passwd[i]) <= 90)
                    caps = 1;
                else if (char(passwd[i]) >= 97 and char(passwd[i]) <= 122)
                    lows = 1;
                else
                    other = 1;
            }
        }
    if (nums + caps + lows + other >= 3)
        return 1;
    else
        return 0;
}

int main() {
    std::string passwd;
    std::cin >> passwd;
    if (passwdChecker(passwd))
        std::cout << "YES";
    else
        std::cout << "NO";
}