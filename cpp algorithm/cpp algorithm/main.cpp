#include <iostream>
#include <cstdio>
#include <array>
#include <string>

using namespace std;

int n;
array<array<int, 64>, 64> arr;
string s;

void check(int x, int y, int size) {
    int num = arr[x][y];
    for (int i{x}; i < x + size; i++) {
        for (int j{y}; j < y + size; j++) {
            if (arr[i][j] != num) {
                s += "(";
                check(x, y, size/2);
                check(x, y + size/2, size/2);
                check(x + size/2, y, size/2);
                check(x + size/2, y + size/2, size/2);
                s += ")";
                return;
            }
        }
    }
    s += to_string(num);
}

int main()
{
    
    
    cin >> n;

    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    check(0, 0, n);
    
    cout << s;
    
    return 0;
}
