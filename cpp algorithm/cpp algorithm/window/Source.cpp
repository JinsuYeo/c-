#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int dp(int a) {
	if (a == 1) return 1;
	if (a == 2) return 2;
	if (arr[a] != 0) return arr[a];
	return arr[a] = (dp(a - 1) + dp(a - 2))%10007;
}

int main() {
	int a{};

	cin >> a;
	cout << dp(a);

	return 0;
}