#include <iostream>
#include <stdexcept>

class Rational
{
private:
    int Numerator;
    int Denominator;

    int gcd(int a, int b)
    {
        while (a)
        {
            auto t = b % a;
            b = a;
            a = t;
        }
        return b;
    }

    void reducer()
    {
        auto g = gcd(Numerator < 0 ? -Numerator : Numerator, Denominator);
        Numerator /= g;
        Denominator /= g;
        if (Denominator < 0)
        {
            Numerator *= -1;
            Denominator *= -1;
        }
    }

public:
    Rational(int n = 0, int d = 1) : Numerator(n), Denominator(d)
    {
        if (Denominator == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        reducer();
    }

    Rational(const Rational& other) : Numerator(other.Numerator), Denominator(other.Denominator) {}

    const Rational& operator=(const Rational& other)
    {
        Numerator = other.Numerator;
        Denominator = other.Denominator;
        return *this;
    }

    Rational operator+(const Rational& other) const
    {
        return Rational(Numerator * other.Denominator + other.Numerator * Denominator,
                        Denominator * other.Denominator);
    }

    Rational operator-(const Rational& other) const
    {
        return *this + Rational(-other.Numerator, other.Denominator);
    }

    Rational operator*(const Rational& other) const
    {
        return Rational(Numerator * other.Numerator, Denominator * other.Denominator);
    }

    Rational operator/(const Rational& other) const
    {
        if (other.Numerator == 0)
        {
            throw std::invalid_argument("Division by ZERO");
        }
        return Rational(Numerator * other.Denominator, Denominator * other.Numerator);
    }

    Rational operator+=(const Rational& other)
    {
        *this = *this + other;
        return *this;
    }

    Rational operator-=(const Rational& other)
    {
        *this = *this - other;
        return *this;
    }

    Rational operator*=(const Rational& other)
    {
        *this = *this * other;
        return *this;
    }

    Rational operator/=(const Rational& other)
    {
        *this = *this / other;
        return *this;
    }

    bool operator==(const Rational& other) const
    {
        return (Numerator == other.Numerator && Denominator == other.Denominator);
    }

    bool operator!=(const Rational& other) const
    {
        return !(*this == other);
    }

    Rational operator+() const
    {
        return *this;
    }

    Rational operator-() const
    {
        return Rational(-Numerator, Denominator);
    }

    Rational& operator++()
    {
        Numerator += Denominator;
        reducer();
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp = *this;
        ++(*this);
        return temp;
    }

    Rational& operator--()
    {
        Numerator -= Denominator;
        reducer();
        return *this;
    }

    Rational operator--(int)
    {
        Rational temp = *this;
        --(*this);
        return temp;
    }

    int numerator() const
    {
        return Numerator;
    }

    int denominator() const
    {
        return Denominator;
    }

    friend std::ostream& operator<<(std::ostream& out, const Rational& c)
    {
        out << c.numerator() << "/" << c.denominator();
        return out;
    }
};

Rational operator+(int value, const Rational& rational)
{
    return rational + value;
}

Rational operator-(int value, const Rational& rational)
{
    return Rational(value * rational.denominator() - rational.numerator(), rational.denominator());
}

Rational operator*(int value, const Rational& rational)
{
    return rational * value;
}

Rational operator/(int value, const Rational& rational)
{
    if (rational.numerator() == 0)
    {
        throw std::invalid_argument("Division by ZERO");
    }
    return Rational(value * rational.denominator(), rational.numerator());
}
