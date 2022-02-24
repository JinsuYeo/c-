#include <iostream>
#include <fstream>
#include <string>

int main(void) {
    std::fstream in_file;
    std::string line;
    int num;
    double total;
    
    in_file.open("./text.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        std::exit(1);
    }
    
    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    in_file.close();
    
    return 0;
}


