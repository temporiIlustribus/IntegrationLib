#pragma once
#include <pch.h>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>

template <typename F>
class IntegrationMethod {
public:
    IntegrationMethod() {}
    virtual double Integrate(F&, const double&, const double&, const int) = 0;
};
template <typename F>
class RectangleRule : public IntegrationMethod<F> {
    virtual double Integrate(F& f, const double& a, const double& b, const int n) {
        double sum = 0;
        double x1, x2;
        double delta = (b - a) / n;
        for (size_t i = 0; i < n; ++i) {
            x1 = a + delta * i;
            x2 = a + delta * (i + 1);
            sum += f((x1 + x2) / 2) * (x2 - x1);
        }
        return sum;
    }
};

template <typename F>
class TrapezoidalRule : public IntegrationMethod<F> {
    virtual double Integrate(F& f, const double& a, const double& b, const int n) {
        double sum = 0;
        double x1, x2;
        double delta = (b - a) / n;
        for (size_t i = 0; i < n; ++i) {
            x1 = a + delta * i;
            x2 = a + delta * (i + 1);
            sum += ((f(x1) + f(x2)) / 2) * (x2 - x1);
        }
        return sum;
    }
};