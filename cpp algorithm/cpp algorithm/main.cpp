#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string n, result, ts;

bool compare(char a, char b){
    return a > b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    ts = n;
    sort(ts.begin(), ts.end(), compare);
    
    if (ts.at(ts.length()-1) != '0') {
        cout << -1;
    } else {
        long long ll{};
        for (int i{}; i < ts.length(); i++) {
            ll += static_cast<long long>(ts.at(i));
        }
        if(ll%3 == 0) cout << ts;
        else cout << -1;
    }
    

    
    return 0;
}
