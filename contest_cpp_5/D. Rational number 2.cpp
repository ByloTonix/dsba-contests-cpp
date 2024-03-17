#include <cmath>
#include <iostream>
#include <map>
#include <numeric>

class Rational
{
public:
    Rational(int = 0, int = 1);
    Rational operator+(const Rational&) const;
    Rational operator-(const Rational&) const;
    Rational operator*(const Rational&) const;
    Rational operator/(const Rational&) const;

    void operator+=(const Rational&);
    void operator-=(const Rational&);
    void operator*=(const Rational&);
    void operator/=(const Rational&);

    Rational operator+();
    Rational operator-();

    int denominator() const;
    int numerator() const;

    bool operator==(const Rational&) const;
    bool operator!=(const Rational&) const;

    Rational& operator++();
    Rational operator++(int);

    Rational& operator--();
    Rational operator--(int);


private:
    int numer;
    int denomin;

    void reducer();
};

Rational::Rational(int numer, int denomin) : numer(numer), denomin(denomin) { reducer(); }

void Rational::reducer()
{
    int d = std::gcd(numer, denomin);
    numer /= d;
    denomin /= d;
    if (denomin < 0)
    {
        numer = -numer;
        denomin = -denomin;
    }
}

Rational Rational::operator+(const Rational& frac) const
{
    return Rational{numer * frac.denominator() + frac.numerator() * denomin, denomin * frac.denominator()};
}

Rational operator+(int n, const Rational& frac)
{
    return frac + n;
}

Rational Rational::operator-(const Rational& frac) const
{
    return Rational{numer * frac.denominator() - frac.numerator() * denomin, denomin * frac.denominator()};
}

Rational operator-(int n, const Rational& frac)
{
    return Rational{n * frac.denominator() - frac.numerator(), frac.denominator()};
}

Rational Rational::operator*(const Rational& frac) const
{
    return Rational{numer * frac.numerator(), denomin * frac.denominator()};
}

Rational operator*(double r, const Rational& frac)
{
    return frac * r;
}

Rational Rational::operator/(const Rational& frac) const
{
    return Rational{numer * frac.denominator(), denomin * frac.numerator()};
}

Rational operator/(int r, const Rational& frac)
{
    return Rational{r * frac.denominator(), frac.numerator()};
}

Rational Rational::operator+()
{
    return *this;
}

Rational Rational::operator-()
{
    return Rational{-this->numerator(), this->denominator()};
}

int Rational::numerator() const
{
    return numer;
}

int Rational::denominator() const
{
    return denomin;
}

bool Rational::operator==(const Rational& frac) const
{
    return numer == frac.numer && denomin == frac.denomin;
}

bool Rational::operator!=(const Rational& frac) const
{
    return !(*this == frac);
}

Rational& Rational::operator++()
{
    numer += denomin;
    reducer();
    return *this;
}

Rational Rational::operator++(int)
{
    Rational temp = *this;
    numer += denomin;
    reducer();
    return temp;
}

Rational& Rational::operator--()
{
    numer -= denomin;
    reducer();
    return *this;
}

Rational Rational::operator--(int)
{
    Rational temp = *this;
    numer -= denomin;
    reducer();
    return temp;
}

void Rational::operator+=(const Rational& frac)
{
    *this = *this + frac;
}

void Rational::operator-=(const Rational& frac)
{
    *this = *this - frac;
}

void Rational::operator*=(const Rational& frac)
{
    *this = *this * frac;
}

void Rational::operator/=(const Rational& frac)
{
    *this = *this / frac;
}