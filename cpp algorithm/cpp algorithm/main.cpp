#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

using namespace std;

int N, M, c;
int MAX{1 << 31};

array<int, 10> arr {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i{}; i < M; i++) {
        int t{};
        cin >> t;
        arr[t] = -1;
    }
    
    string s;
    s = to_string(N);
    c = abs(N-100);
    if (c <= 3) {
        cout << c;
        return 0;
    }
    
    for (int i{}; i <= 999999; i++) {
        string temp = to_string(i);
        bool flag = true;
        for (int j{}; j < temp.length(); j++) {
            if (arr[temp[j]-'0'] == -1) {
                flag = false;
            }
        }
        if (flag) {
            c = min(c, int(abs(N-i) + to_string(i).length()));
        }
    }
    
    cout << c;
    
    return 0;
}
