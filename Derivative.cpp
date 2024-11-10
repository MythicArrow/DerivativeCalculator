#include <iostream>
#include <cmath>
#include <functional>

// Define a function to calculate the derivative using a limiting process
double derivativeWithLimit(std::function<double(double)> func, double t, double initial_h = 1e-1, double tolerance = 1e-7) {
    double h = initial_h;
    double previous_result = 0;
    double result = 0;

    while (true) {
        result = (func(t + h) - func(t)) / h;
        
        // Check if the result has stabilized within the tolerance
        if (std::fabs(result - previous_result) < tolerance) {
            break;
        }

        // Update previous result and reduce h
        previous_result = result;
        h /= 2; // Halve h for finer approximation
    }

    return result;
}

// Example function: f(t) = t^2
double exampleFunction(double t) {
    return t * t;
}

int main() {
    double t; // Point at which to calculate the derivative
    std::cout<<"Write the value for t"<<std::endl;
    std::cin>> t;
    double initial_h = 0.1; // Starting value for h
    double tolerance = 1e-7; // Tolerance for convergence

    // Calculate the derivative of exampleFunction at t using the limiting process
    double result = derivativeWithLimit(exampleFunction, t, initial_h, tolerance);

    std::cout << "The derivative of f(t) = t^2 at t = " << t << " is approximately " << result << std::endl;

    return 0;
}