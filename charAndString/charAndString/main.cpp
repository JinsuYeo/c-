#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[]) {
    string input {};
    cin >> input;
    
    int temp = 1;
    size_t ts = input.length() - 1;
    while(1){
        for(size_t i = ts; i > 0; i--) {
            cout << " ";
        }
        for(size_t j = 0; j < temp; j++) {
            cout << input.at(j);
        }
        if(temp > 1) {
            for(int k = temp - 2; k >= 0; k--) {
                cout << input.at(k);
            }
        }
        temp += 1;
        cout << endl;
        ts--;
        if(temp > input.length()) break;
    }

    return 0;
}


