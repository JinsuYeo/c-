#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int N;
string s;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore(1);
    for (int i{}; i < N; i++) {
        string t;
        getline(cin, s);
        stringstream ss{s};
        while(ss >> t){
            reverse(t.begin(), t.end());
            cout << t << " ";
        }
            
        cout << endl;
    }
    
    return 0;
}
