//
//  main.cpp
//  c++
//
//  Created by 여진수 on 2021/11/06.
//

#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    char choice {};
    vector<int> numbers {};
    
    cout << "P - print numbers\nA - Add a number\n";
    cout << "M - Display mean of the numers\nS - Display the smallest number\n";
    cout << "L - Display largest number\nQ - Quit\n\n";
    
    int int_add {};
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 'p':
            case 'P': if(numbers.size() != 0) {
                cout << "[ ";
                for(auto number: numbers) {
                    cout << number << " ";
                }
                cout << "]" << endl;
            } else {
                cout << "[] - the list is empty";
            }
                break;
            case 'a':
            case 'A': cout << "Enter an integer to add to the list: ";
                cin >> int_add;
                numbers.push_back(int_add);
                cout << int_add << " added\n";
                break;
            case 'm':
            case 'M': {
                int avr{}, sum {};
                for(auto number: numbers) {
                    sum += number;
                }
                avr = sum/numbers.size();
                cout << "The mean is : " << avr << "\n";
                break;
            }
            case 's':
            case 'S': {
                int small {};
                cout << "The smallest number is: ";
                for(auto number: numbers) {
                    if(number < small) small = number;
                }
                cout << small << endl;
                break;
            }
            case 'l':
            case 'L': {
                int large {};
                cout << "The smallest number is: ";
                for(auto number: numbers) {
                    if(number > large) large = number;
                }
                cout << large << endl;
                break;
            }
            case 'q':
            case 'Q': cout << "Good bye...\n";
                break;
            default: cout << "Unknown selection, please try again\n";
                break;
        }
        printf("\n\n");
    } while(choice != 'q' && choice != 'Q');
    
    

    return 0;
}
