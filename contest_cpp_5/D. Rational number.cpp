#include <cmath>
#include <iostream>
#include <numeric>

class Rational
{
private:
    int Numerator;
    int Denominator;

    void reducer()
    {
        int d = std::gcd(Numerator, Denominator);
        Numerator /= d;
        Denominator /= d;
        if (Denominator < 0)
        {
            Numerator = -Numerator;
            Denominator = -Denominator;
        }
    }

public:
    // Конструкторы
    Rational(int Numerator = 0, int Denominator = 1);
    Rational(const Rational& other);

    // Перегрузка операторов
    const Rational& operator=(const Rational& other);
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    Rational operator+=(const Rational& other);
    Rational operator-=(const Rational& other);
    Rational operator*=(const Rational& other);
    Rational operator/=(const Rational& other);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;

    Rational operator+() const;
    Rational operator-() const;

    Rational& operator++();
    Rational operator++(int);
    Rational& operator--();
    Rational operator--(int);

    int numerator() const { return Numerator; }
    int denominator() const { return Denominator; }

    Rational operator+(int value) const
    {
        return Rational(Numerator + value * Denominator, Denominator);
    }

    friend Rational operator+(int value, const Rational& rational)
    {
        return rational + value;
    }

    Rational operator-(int value) const
    {
        return Rational(Numerator - value * Denominator, Denominator);
    }

    friend Rational operator-(int value, const Rational& rational)
    {
        return Rational(value * rational.Denominator - rational.Numerator, rational.Denominator);
    }

    Rational operator*(int value) const
    {
        return Rational(Numerator * value, Denominator);
    }

    friend Rational operator*(int value, const Rational& rational)
    {
        return rational * value;
    }

    Rational operator/(int value) const
    {
        return Rational(Numerator, Denominator * value);
    }

    friend Rational operator/(int value, const Rational& rational)
    {
        return Rational(value * rational.Denominator, rational.Numerator);
    }

    // friend дает доступ к private class
    friend std::ostream& operator<<(std::ostream& out, const Rational& c);

    friend Rational operator*(int left, const Rational& right);// Умножение на целое число
};

std::ostream& operator<<(std::ostream& out, const Rational& c)
{
    out << c.numerator() << "/" << c.denominator();
    return out;
}

// Реализация методов класса Rational

Rational::Rational(int Numerator, int Denominator) : Numerator(Numerator), Denominator(Denominator) { reducer(); }
Rational::Rational(const Rational& other)
{
    Numerator = other.Numerator;
    Denominator = other.Denominator;
}

// Оператор присваивания
const Rational& Rational::operator=(const Rational& other)
{
    Numerator = other.Numerator;
    Denominator = other.Denominator;
    return *this;
}

// Оператор сложения
Rational Rational::operator+(const Rational& other) const
{
    return Rational(Numerator * other.Denominator + other.Numerator * Denominator, Denominator * other.Denominator);
}

// Оператор вычитания
Rational Rational::operator-(const Rational& other) const
{
    return -other + *this;
}

// Оператор умножения
Rational Rational::operator*(const Rational& other) const
{
    return Rational(Numerator * other.Numerator, Denominator * other.Denominator);
}

// Оператор деления
Rational Rational::operator/(const Rational& other) const
{
    return Rational(Numerator * other.Denominator, Denominator * other.Numerator);
}

// Оператор сравнения на равенство
bool Rational::operator==(const Rational& other) const
{
    return (Numerator == other.Numerator && Denominator == other.Denominator);
}

// Оператор сравнения на неравенство
bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

// Унарный оператор плюс
Rational Rational::operator+() const
{
    return *this;
}

// Унарный оператор минус
Rational Rational::operator-() const
{
    return Rational(-Numerator, Denominator);
}

Rational Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

Rational Rational::operator-=(const Rational& other)
{
    *this = *this - other;
    return *this;
}

Rational Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    return *this;
}

Rational Rational::operator/=(const Rational& other)
{
    *this = *this / other;
    return *this;
}


Rational& Rational::operator++()
{
    Numerator += Denominator;
    reducer();
    return *this;
}

Rational Rational::operator++(int)
{
    Rational temp = *this;
    Numerator += Denominator;
    reducer();
    return temp;
}

Rational& Rational::operator--()
{
    Numerator -= Denominator;
    reducer();
    return *this;
}

Rational Rational::operator--(int)
{
    Rational temp = *this;
    Numerator -= Denominator;
    reducer();
    return temp;
}