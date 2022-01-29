#include <iostream>
#include <string>

using namespace std;
    
long long gcd(long long a, long long b) {
    long long t = a % b;
    while(t != 0) {
        a = b;
        b = t;
        t = a % b;
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a{}, b{};
    cin >> a >> b;
    
    cout << string(gcd(a, b), '1') << "\n";
    
    return 0;
}
