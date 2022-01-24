#include <cstdio>
#include <algorithm>

int arr[3];

int main(int argc, const char * argv[]) {
    int n{3}, j{}, temp{};
    
    for(int i{}; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i{}; i < n-1; i++) {
        j = i;
        while (j >= 0 && arr[j] > arr[j+1]) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }
    
    for(int i{}; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
