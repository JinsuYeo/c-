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

inline void display_menu() {
    cout << "Enter your choice: ";
}
char user_input();
void case_p(vector<int> &numbers);
void case_a(vector<int> &numbers);
void case_m(vector<int> &numbers);
void case_s(vector<int> &numbers);
void case_l(vector<int> &numbers);

int main(int argc, const char * argv[]) {
    char choice {};
    vector<int> numbers {};
    
    cout << "P - print numbers\nA - Add a number\n";
    cout << "M - Display mean of the numers\nS - Display the smallest number\n";
    cout << "L - Display largest number\nQ - Quit\n\n";
    
    
    do {
        display_menu();
        choice = user_input();
        switch(choice) {
            case 'P':
                case_p(numbers);
                break;
            case 'A':
                case_a(numbers);
                break;
            case 'M': {
                case_m(numbers);
                break;
            }
            case 'S': {
                case_s(numbers);
                break;
            }
            case 'L': {
                case_l(numbers);
                break;
            }
            case 'Q': cout << "Good bye...\n";
                break;
            default: cout << "Unknown selection, please try again\n";
                break;
        }
        printf("\n\n");
    } while(choice != 'Q');
    
    

    return 0;
}

char user_input() {
    char choice {};
    cin >> choice;
    cin.clear();
    if(islower(choice)) return(toupper(choice));
    return choice;
}

void case_p(vector<int> &numbers){
    if(numbers.size() != 0) {
        cout << "[ ";
        for(auto number: numbers) {
            cout << number << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "[] - the list is empty";
    }
}

void case_a(vector<int> &numbers){
    int int_add {};
    cout << "Enter an integer to add to the list: ";
    cin >> int_add;
    numbers.push_back(int_add);
    cout << int_add << " added\n";
}

void case_m(vector<int> &numbers){
    int avr{}, sum {};
    for(auto number: numbers) {
        sum += number;
    }
    avr = sum/numbers.size();
    cout << "The mean is : " << avr << "\n";
}

void case_s(vector<int> &numbers){
    int small {};
    cout << "The smallest number is: ";
    for(auto number: numbers) {
        if(number < small) small = number;
    }
    cout << small << endl;
}

void case_l(vector<int> &numbers){
    int large {};
    cout << "The smallest number is: ";
    for(auto number: numbers) {
        if(number > large) large = number;
    }
    cout << large << endl;
}

