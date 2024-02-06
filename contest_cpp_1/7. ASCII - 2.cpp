/*
Print the ASCII table for characters from 32 to 127. 
Your table should have 6 rows and 16 columns, as well as two headers: for rows and for columns.
The initial column should be the most significant hexadecimal digit of the character code.
The starting line must have a lower hexadecimal digit. Alphanumeric characters must be capitalized.
Separate items on the same line with tab characters.
Примечания

Your table should look something like this (only without the first two lines with control characters): https://clck.ru/AFtzU.
Borders between cells do not need to be drawn.
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{   
    int a = 0;
    int c = 2;
    cout << "\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\tA\tB\tC\tD\tE\tF";
    for (int i = 32; i < 128; i++) {
        if (a % 16 == 0) {
            cout << "\n" << c;
            c++;
        }
        cout << "\t" << (char) i;
        a++;
    }
    return 0;
}