#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {
    int n{}, result{};
    cin >> n;
    int arr[1001][10]{};

    for (int i = 0; i < 10; i++) {
        arr[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {

        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                arr[i][j] += arr[i - 1][k] % 10007;
                arr[i][j] %= 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        result += arr[n][i] % 10007;
        result %= 10007;
    }

    cout << result;

    return 0;
}