#include <iostream>
#include <cmath>
#include <numbers> // C++20 for pi constant

// Function to calculate the value of Si(x) using Simpson's Rule
double Si(double x) {
    if (x == 0.0) return 0.0;

    const int n = 1000; // Number of intervals, increase for better accuracy
    const double h = x / n; // Width of each interval

    double sum = std::sin(0.0) / 0.0; // sin(0)/0 is defined as 1

    for (int i = 1; i < n; ++i) {
        double t = i * h;
        if (i % 2 == 0) {
            sum += 2 * std::sin(t) / t; // Even indices
        } else {
            sum += 4 * std::sin(t) / t; // Odd indices
        }
    }

    sum += std::sin(x) / x; // Add the last term

    return sum * h / 3.0; // Apply Simpson's Rule
}

int main() {
    double x;
    std::cout << "Enter the value of x to calculate Si(x): ";
    std::cin >> x;

    double result = Si(x);
    std::cout << "Si(" << x << ") = " << result << std::endl;

    return 0;
}
