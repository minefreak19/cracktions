#pragma once

#include <iostream>
#include <cstdint>

namespace Cracktions
{
    class Fraction
    {
    private:
        int64_t num;
        int64_t den;

        void reduce();

    public:
        Fraction(int64_t num, int64_t den);

        double abs();

        Fraction mult_inv();

        Fraction operator-();
        Fraction operator+(Fraction);
        Fraction operator-(Fraction);
        Fraction operator*(Fraction);
        Fraction operator/(Fraction);

        friend Fraction operator+(Fraction, int64_t);
        friend Fraction operator-(Fraction, int64_t);
        friend Fraction operator*(Fraction, int64_t);
        friend Fraction operator/(Fraction, int64_t);

        friend std::ostream &operator<<(std::ostream &os, const Fraction frac);
    };

    Fraction operator+(int64_t, Fraction);
    Fraction operator-(int64_t, Fraction);
    Fraction operator*(int64_t, Fraction);
    Fraction operator/(int64_t, Fraction);
}
