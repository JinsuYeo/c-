#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
    int n[3][4]{}, count[3]{};
    char result[5] = { 'D', 'C', 'B', 'A', 'E' };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            cin >> n[i][j];
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            if (n[i][j]) {
                count[i]++;
            }
        cout << result[count[i]] << endl;
    }



    return 0;
}