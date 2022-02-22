#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    double num1{123456789.987654321};
    double num2{1234.5678};
    double num3{1234.0};
    
    // Using default settings
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Note how since we can't display in precision 2 scientific notation is used
    std::cout << std::setprecision(2);
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Using precision 3 and fixed
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Using precision 3, fixed and scientific notation
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Same but display capital 'E' in scientific
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Show '+' symbol for positive numbers
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Back to defaults
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);
    
    // Show trailing zeroes up to precision 10
    
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << num3 << std::endl;
    
    // Back to defaults
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showpoint);
    
    return 0;
}
