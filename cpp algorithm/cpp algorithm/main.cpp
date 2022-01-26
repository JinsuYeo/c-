#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[26];
char carr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
        
    for (int i{}; i < 26; i++) {
        arr[i] = -1;
    }
    
    for(int i{}; i < s.length(); i++) {
        for(int j{}; j < 26; j++) {
            if(s.at(i) == carr[j]) {
                if((arr[j] != -1 && i < arr[j]) || arr[j] == -1) {
                    arr[j] = i;
                }
            }
        }
    }
    
    for(int i{}; i < 26; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
   
    return 0;
}
