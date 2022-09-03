#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s{};
    
    cin >> s >> N;
    
    string::iterator it = s.end();
    
    for (int i{}; i < N; i++) {
        char c{};
        cin >> c;
        if (c == 'P') {
            cin >> c;
            it = s.insert(it, c);
            it++;
        } else if (c == 'L') {
            if(it != s.begin()) it--;
        } else if(c == 'D') {
            if(it != s.end()) it++;
        } else if(c == 'B') {
            if(it != s.begin()) it = s.erase(--it);
        }
    }

    cout << s;
    
    return 0;
}
