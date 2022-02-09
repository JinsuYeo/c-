#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int miles{};
    int gallons{};
    double miles_per_gallon{};
    
    cout << "Enter the miles: ";
    cin >> miles;
    cout << "Enter the gallons: ";
    cin >> gallons;
    
//    if (gallons != 0) {
//        miles_per_gallon = static_cast<double>(miles) / gallons;
//        cout << "Result: " << miles_per_gallon << "\n";
//    } else {
//        cerr << "Sorry. can't divide by zero" << endl;
//    }
    
    try {
        if (gallons == 0)
            throw 0;
        miles_per_gallon = static_cast<double>(miles) / gallons;
        cout << "Result: " << miles_per_gallon << "\n";
    } catch (int &ex) {
        cerr << "Sorry. you can't divide by zero" << endl;
    }
    
    cout << "Bye" << endl;
    
    return 0;
}
