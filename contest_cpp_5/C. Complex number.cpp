// Implement the class Complex (a complex number).

// The constructor of this class must receive either one or two numbers of type double (the real and imaginary part or just the real one) as input. Overload the binary operators of addition, subtraction, multiplication and division (they should work with real arguments as well), unary plus and minus.

// Provide Re and Im member functions for real and imaginary parts.

// Override the external function abs that returns the absolute value of a complex number. Overload operators == and !=.
// Notes

// Your solution should not have main function. Please provide only class Complex and required functions.

#include <iostream>
#include <cmath>

class Complex
{
private:
    double Real;
    double Imaginary;
public:
    Complex();
    Complex(double Real, double Imaginary = 0);
    Complex(const Complex &other);
    const Complex &operator=(const Complex &other);
    Complex operator+(const Complex &other);
    Complex operator-(const Complex &other);
    Complex operator*(const Complex &other);
    Complex operator/(const Complex &other);
    
    bool operator==(const Complex &other);
    bool operator!=(const Complex &other);
    
    Complex operator+() const { return *this; }
    Complex operator-() const { return Complex(-Real, -Imaginary); }

    double Re() const { return Real; }
    double Im() const {return Imaginary; }

    friend double abs(const Complex& c) {
        return std::sqrt(c.Real * c.Real + c.Imaginary * c.Imaginary);
    }
};


std::ostream &operator<<(std::ostream &out, const Complex &c);


std::ostream &operator<<(std::ostream &out, const Complex &c) {
    out << "(" << c.Re() << "," << c.Im() << ")";
    return out;
}

Complex::Complex(): Real(0), Imaginary(0) {}

Complex::Complex(double Real, double Imaginary): Real(Real), Imaginary(Imaginary) {}

Complex::Complex(const Complex &other)
{
    Real = other.Real;
    Imaginary = other.Imaginary;
}


const Complex &Complex::operator=(const Complex &other) {
    Real = other.Real;
    Imaginary = other.Imaginary;

    return *this;
}

Complex Complex::operator+(const Complex &other) {
    return Complex (Real + other.Real, Imaginary + other.Imaginary);
}

Complex Complex::operator-(const Complex &other) {
    return Complex (Real - other.Real, Imaginary - other.Imaginary);
}

Complex Complex::operator*(const Complex &other) {
    return Complex (Real * other.Real - Imaginary * other.Imaginary, other.Real * Imaginary + Real * other.Imaginary);
}

Complex Complex::operator/(const Complex &other) {
        double denominator = other.Real * other.Real + other.Imaginary * other.Imaginary;
        double newReal = (Real * other.Real + Imaginary * other.Imaginary) / denominator;
        double newImaginary = (Imaginary * other.Real - Real * other.Imaginary) / denominator;
        return Complex(newReal, newImaginary);
    }

bool Complex::operator==(const Complex &other) {
    return (Real == other.Real and Imaginary == other.Imaginary);
}
bool Complex::operator!=(const Complex &other) {
    return !(*this == other);
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
        std::cout << "a != b\n";
    }

    return 0;
}