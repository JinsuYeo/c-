#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];

int main() {
    int n{};
    cin >> n;
    for(int i{}; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i{1}; i < n; i++) {
        int c{i};
        do {
            int root = (c-1)/2;
            if(arr[root] < arr[c]) {
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        }
        while(c != 0);
    }
    
    for(int i{n-1}; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        int root{};
        int c{};
        do {
            c = root * 2 + 1;
            if(c < i - 1 && arr[c] < arr[c+1]) c++;
            if(c < i && arr[root] < arr[c]) {
                temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            root = c;
        } while (c < i);
    }
    
    for (int i{}; i < n; i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}
