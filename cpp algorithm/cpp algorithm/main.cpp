#include <cstdio>
#include <climits>

using namespace std;

int arr[3];

int main(int argc, const char * argv[]) {
    int n{3}, temp{}, min{}, index{};
    
    for(int i{}; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i{}; i < n-1; i++) {
        min = INT_MAX;
        for(int j{i}; j < n; j++) {
            if(arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
    
    for(int i{}; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
