#include <iostream>
#include <algorithm>

using namespace std;

int arr[11];

int dp(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (arr[n] != 0) return arr[n];
	return arr[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
}

int main() {
	int a{};
	cin >> a;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < 11; j++) {
			arr[j] = 0;
		}
		int n{};

		cin >> n;
		cout << dp(n) << "\n";
	}

	return 0;
}