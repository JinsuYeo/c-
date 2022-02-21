#include <iostream>
#include <iomanip>

int main(int argc, const char * argv[]) {
    int num{255};
    
    // Displaying using different bases
    std::cout << "\n----------------------------" << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    
    // Displaying showing the base prefix for hex and oct
    std::cout << "\n----------------------------" << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // Displaying the hex value in uppercase
    std::cout << "\n----------------------------" << std::endl;
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;

    // Displaying the + sign in front of positive base 10 numbers
    std::cout << "\n----------------------------" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;
    
    // setting using the set method
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::showpos);
    std::cout.setf(std::ios::uppercase);
    
    // resetting to defaults
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);
    
    return 0;
}
