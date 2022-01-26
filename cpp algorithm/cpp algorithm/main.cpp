#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    
    cout << stol(s1 + s2) + stol(s3 + s4) << "\n";
    
    return 0;
}
