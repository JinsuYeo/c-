#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main(void) {
    std::fstream in_file;
    std::string line;
    char c;
    in_file.open("./text.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        std::exit(1);
    }
        
    while(in_file.get(c)) {
        std::cout << c;
    }
    
    in_file.close();
    
    in_file.open("./text.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        std::exit(1);
    }
    
    while(std::getline(in_file, line)) {
        std::cout << std::setw(10) << std::left << line
                  << std::endl;
    }
    
    in_file.close();
    
    return 0;
}


