#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000000];

void quickSort(int* arr, int start, int end) {
    if(start < end) {
        int key{start}, i{start+1}, j{end}, temp{};
        while(i <= j) {
            while(i <= end && arr[i] <= arr[key])
                i++;
            while(j > start && arr[j] >= arr[key])
                j--;
            
            if(i > j) {
                temp = arr[j];
                arr[j] = arr[key];
                arr[key] = temp;
            } else {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        quickSort(arr, start, j-1);
        quickSort(arr, j+1, end);
    }
    return;
}

int main(int argc, const char * argv[]) {
    int n{};
    scanf("%d", &n);
    
    for(int i{}; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n-1);
    
    for(int i{}; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
