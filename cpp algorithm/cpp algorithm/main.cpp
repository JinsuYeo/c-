#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000000];

int main(int argc, const char * argv[]) {
    int n{}, temp{};
    scanf("%d", &n);
    
    for(int i{}; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i{}; i < n - 1; i++) {
        for(int j{}; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    for(int i{}; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
