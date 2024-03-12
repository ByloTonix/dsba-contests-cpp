// Implement the class Complex (a complex number).

// The constructor of this class must receive either one or two numbers of type double (the real and imaginary part or just the real one) as input. Overload the binary operators of addition, subtraction, multiplication and division (they should work with real arguments as well), unary plus and minus.

// Provide Re and Im member functions for real and imaginary parts.

// Override the external function abs that returns the absolute value of a complex number. Overload operators == and !=.
// Notes

// Your solution should not have main function. Please provide only class Complex and required functions.

// Implement the class Complex (a complex number).

// The constructor of this class must receive either one or two numbers of type double (the real and imaginary part or just the real one) as input. Overload the binary operators of addition, subtraction, multiplication and division (they should work with real arguments as well), unary plus and minus.

// Provide Re and Im member functions for real and imaginary parts.

// Override the external function abs that returns the absolute value of a complex number. Overload operators == and !=.
// Notes

// Your solution should not have main function. Please provide only class Complex and required functions.

#include <cmath>
#include <iostream>
#include <stdexcept>

class Complex
{
private:
    double Real;
    double Imaginary;

public:
    // Конструкторы
    Complex();                                 // Конструктор по умолчанию
    Complex(double Real, double Imaginary = 0);// Конструктор с параметрами (мнимая часть по умолчанию равна 0)
    Complex(const Complex& other);             // Конструктор копирования

    // Перегрузка операторов
    const Complex& operator=(const Complex& other);// Оператор присваивания
    Complex operator+(const Complex& other) const; // Оператор сложения
    Complex operator-(const Complex& other) const; // Оператор вычитания
    Complex operator*(const Complex& other) const; // Оператор умножения
    Complex operator/(const Complex& other) const; // Оператор деления

    // Логические операторы равенства и неравенства
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Унарные операторы сложения и вычитания
    Complex operator+() const;
    Complex operator-() const;

    // Методы для получения частей комплексного числа
    double Re() const { return Real; }
    double Im() const { return Imaginary; }

    // Функция для вычисления модуля комплексного числа
    // friend дает доступ к private class
    friend double abs(const Complex& c)
    {
        return std::sqrt(c.Real * c.Real + c.Imaginary * c.Imaginary);
    }

    // Перегрузка оператора вывода для класса Complex
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);

    friend Complex operator*(int left, const Complex& right); // Умножение на целое число

};


std::ostream& operator<<(std::ostream& out, const Complex& c)
{
    out << "(" << c.Re() << "," << c.Im() << ")";// Вывод комплексного числа в формате (a, b)
    return out;
}

// Реализация методов класса Complex

// Конструктор по умолчанию инициализирует действительную и мнимую части нулями
Complex::Complex() : Real(0), Imaginary(0) {}

// Конструктор с параметрами инициализирует действительную и мнимую части заданными значениями
Complex::Complex(double Real, double Imaginary) : Real(Real), Imaginary(Imaginary) {}

// Конструктор копирования копирует значения действительной и мнимой частей из другого объекта
Complex::Complex(const Complex& other)
{
    Real = other.Real;
    Imaginary = other.Imaginary;
}
// вообще эти три можно перенести в паблик, но пока рано

// Оператор присваивания
const Complex& Complex::operator=(const Complex& other)
{
    Real = other.Real;
    Imaginary = other.Imaginary;
    return *this;
}

// Оператор сложения
Complex Complex::operator+(const Complex& other) const
{
    return Complex(Real + other.Real, Imaginary + other.Imaginary);
}

// Оператор вычитания
Complex Complex::operator-(const Complex& other) const
{
    return Complex(Real - other.Real, Imaginary - other.Imaginary);
}

// Оператор умножения
Complex Complex::operator*(const Complex& other) const
{
    return Complex(Real * other.Real - Imaginary * other.Imaginary, other.Real * Imaginary + Real * other.Imaginary);
}

// Оператор деления
Complex Complex::operator/(const Complex& other) const
{
    double denominator = other.Real * other.Real + other.Imaginary * other.Imaginary;
    if (denominator == 0)
    {
        throw std::invalid_argument("Division by ZERO");
    }
    double newReal = (Real * other.Real + Imaginary * other.Imaginary) / denominator;
    double newImaginary = (Imaginary * other.Real - Real * other.Imaginary) / denominator;
    return Complex(newReal, newImaginary);
}

// Оператор сравнения на равенство
bool Complex::operator==(const Complex& other) const
{
    return (Real == other.Real && Imaginary == other.Imaginary);
}

// Оператор сравнения на неравенство
bool Complex::operator!=(const Complex& other) const
{
    return !(*this == other);
}

// Унарный оператор плюс
Complex Complex::operator+() const
{
    return *this;
}

// Унарный оператор минус
Complex Complex::operator-() const
{
    return Complex(-Real, -Imaginary);
}

// Умножение на целое число
Complex operator*(int left, const Complex& right) {
    return Complex(left * right.Real, left * right.Imaginary);
}

int main() {
    Complex a(3, 4);
    Complex b(1, 2);

    Complex sum = a + b;
    Complex difference = a - b;
    Complex product = a * b;
    Complex quotient = a / b;

    std::cout << "Sum: " << sum.Re() << " + " << sum.Im() << "i\n";
    std::cout << "Difference: " << difference.Re() << " + " << difference.Im() << "i\n";
    std::cout << "Product: " << product.Re() << " + " << product.Im() << "i\n";
    std::cout << "Quotient: " << quotient.Re() << " + " << quotient.Im() << "i\n";

    std::cout << "abs(a): " << abs(a) << "\n";
    
    if (a == b) {
        std::cout << "a == b\n";
    } else {
        std::cout << "a !=b\n";
    }

    return 0;
}