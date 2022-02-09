#include <iostream>
#include <cstdio>
#include <array>
#include <string>

using namespace std;

int n;
array<array<char, 6561>, 6561> arr;

void draw(int x, int y, int size) {
    if (size == 3) {
        for (int i{x}; i < x + size; i++) {
            for (int j{y}; j < y + size; j++) {
                if(i == x + 1 && j == y + 1) {
                    arr[i][j] = ' ';
                    continue;
                }
                arr[i][j] = '*';
            }
        }
        return;
    }
    draw(x, y, size/3);
    draw(x + size/3, y, size/3);
    draw(x + size*2/3, y, size/3);
    draw(x, y + size/3, size/3);
    draw(x + size*2/3, y + size/3, size/3);
    draw(x, y + size*2/3, size/3);
    draw(x + size/3, y + size*2/3, size/3);
    draw(x + size*2/3, y + size*2/3, size/3);
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for (int i{}; i < n; i++) {
        arr[i].fill(' ');
    }
    
    draw(0, 0, n);
    
    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
