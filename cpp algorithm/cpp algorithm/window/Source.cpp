#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][10];


int main() {
	int n{};
	cin >> n;

	for (int i = 1; i < 10; i++) {
		arr[1][i] = 1; //arr[1][0] = 0
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				arr[i][j] = arr[i - 1][j + 1];
			}
			else if (j == 9) {
				arr[i][j] = arr[i - 1][j - 1];
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			}
			arr[i][j] %= 1000000000;
		}
	}

	int count{};
	for (int i = 0; i < 10; i++) {
		count += arr[n][i];
		count %= 1000000000;
	}

	cout << count;

	return 0;
}