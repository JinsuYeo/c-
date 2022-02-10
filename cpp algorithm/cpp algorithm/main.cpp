#include <iostream>
#include <cstdio>
#include <array>
#include <string>

using namespace std;

int n;
array<array<char, 3072*2>, 3072> arr;

void draw(int x, int y, int size) {
    if (size == 3) {
        for (int i{x-1}; i <= x + 1; i++) {
            for (int j{y-2}; j <= y + 2; j++) {
                if(i == x-1 && j == y) {
                    arr[i][j] = '*';
                }
                if (i == x && j == y - 1) {
                    arr[i][j] = '*';
                }
                if (i == x && j == y + 1) {
                    arr[i][j] = '*';
                }
                if (i == x + 1 && j >= y - 2 && j <= y + 2) {
                    arr[i][j] = '*';
                }
            }
        }
        return;
    }
    int t = size/2;
    draw(x - t, y, t);
    draw(x, y - t, t);
    draw(x, y + t, t);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i{}; i < n; i++) {
        arr[i].fill(' ');
    }
    
    draw(n-2, n-1, n);
    
    for (int i{}; i < n; i++) {
        for (int j{}; j < 2*n-1; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
