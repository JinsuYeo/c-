#include <iostream>
#include <algorithm>
#include <array>
#include <string>

using namespace std;
int arr[1000][1000];
int R, C;
string result;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    cin >> R >> C;
    for (int i{}; i < R; i++) {
        for (int j{}; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    
    if(R%2) {
        for (int i{}; i < R; i++) {
            for (int j{}; j < C-1; j++) {
                if (i % 2 == 0) {
                    result += 'R';
                } else {
                    result += 'L';
                }
            }
            if (i != R - 1) {
                result += 'D';
            }
        }
    } else if(!(R%2) && C%2) {
        for (int j{}; j < C; j++) {
            for (int i{}; i < R-1; i++) {
                if (j % 2 == 0) {
                    result += 'D';
                } else {
                    result += 'U';
                }
            }
            if (j != C-1) {
                result += 'R';
            }
        }
    } else if(!(R%2) && !(C%2)) {
        int min_v{987654321};
        int y{}, x{};
        for (int i{}; i < R; i++) {
            for (int j{}; j < C; j++) {
                if ((i + j) % 2 && min_v > arr[i][j]) {
                    min_v = arr[i][j];
                    y = i;
                    x = j;
                }
            }
        }
        int nR = y%2 ? y-1 : y;
        for (int i{}; i < nR; i++) {
            for (int j{}; j < C - 1; j++) {
                if (i%2 == 0) {
                    result += 'R';
                } else {
                    result += 'L';
                }
            }
            result += 'D';
        }
        int nC = x;
        for (int i{}; i < nC; i++) {
            if (i % 2 == 0) {
                result += "DR";
            } else {
                result += "UR";
            }
        }
        for (int i{nC}; i < C - 1; i++) {
            if (i % 2== 0) {
                result += "RD";
            } else {
                result += "RU";
            }
        }
        if (y % 2 == 0) {
            nR = R - (y+2);
        } else {
            nR = R - (y+1);
        }
        for (int i{}; i < nR; i++) {
            result += 'D';
            for (int j{}; j < C - 1; j++) {
                if (i % 2 == 0) {
                    result += 'L';
                } else {
                    result += 'R';
                }
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
