#include <iostream>
#include <string>

using namespace std;

string arr[5];

int main() {

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < arr[j].length()) {
				cout << arr[j][i];
			}
		}
	}

	cout << endl;

	return 0;
}