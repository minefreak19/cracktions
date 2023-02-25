#include "./fraction.hh"

namespace
{
    int64_t gcd(int64_t a, int64_t b)
    {
        int64_t max = a > b ? a : b;
        int64_t min = a < b ? a : b;

        if (max % min == 0)
            return min;

        return gcd(min, max - min);
    }

    int64_t lcm(int64_t a, int64_t b)
    {
        return a * b / gcd(a, b);
    }
}

namespace Cracktions
{
    Fraction::Fraction(int64_t num, int64_t den)
    {
        this->num = num;
        this->den = den;

        reduce();
    }

    double Fraction::abs()
    {
        return (double)this->num / this->den;
    }

    std::ostream &operator<<(std::ostream &os, const Fraction frac)
    {
        return os << frac.num << "/" << frac.den
                  << " (" << ((double)frac.num / (double)frac.den) << ")";
    }

    void Fraction::reduce()
    {
        if (this->den < 0)
        {
            this->num = -this->num;
            this->den = -this->den;
        }

        int64_t temp = this->num;
        if (this->num < 0)
        {
            this->num = -this->num;
        }

        int64_t hcf = gcd(this->num, this->den);

        this->num = temp / hcf;
        this->den /= hcf;
    }

    Fraction Fraction::operator+(Fraction other)
    {
        int64_t den = lcm(this->den, other.den);

        int64_t a = this->num * (den / this->den);
        int64_t b = other.num * (den / other.den);

        return Fraction(a + b, den);
    }

    Fraction Fraction::operator-()
    {
        return Fraction(-this->num, this->den);
    }

    Fraction Fraction::operator-(Fraction other)
    {
        return *this + -other;
    }

    Fraction Fraction::operator*(Fraction other)
    {
        return Fraction(this->num * other.num, this->den * other.den);
    }

    Fraction Fraction::operator/(Fraction other)
    {
        return *this * other.mult_inv();
    }

    Fraction Fraction::mult_inv()
    {
        return Fraction(this->den, this->num);
    }

    Fraction operator+(Fraction f, int64_t a)
    {
        return Fraction(f.num + a * f.den, f.den);
    }

    Fraction operator-(Fraction f, int64_t a)
    {
        return f + -a;
    }

    Fraction operator*(Fraction f, int64_t a)
    {
        return Fraction(f.num * a, f.den);
    }

    Fraction operator/(Fraction f, int64_t a)
    {
        return Fraction(f.num, f.den * a);
    }

    Fraction operator+(int64_t a, Fraction f) {
        return f + a;
    }

    Fraction operator - (int64_t a, Fraction f) {
        return a + -f;
    }

    Fraction operator*(int64_t a, Fraction f) {
        return f * a;
    }

    Fraction operator/(int64_t a, Fraction f) {
        return a * f.mult_inv();
    }
}
