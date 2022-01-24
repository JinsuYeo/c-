#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000000];

int main(int argc, const char * argv[]) {
    int n{}, min{INT_MAX}, index{}, temp{};
    scanf("%d", &n);
    
    for(int i{}; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i{}; i < n - 1; i++) {
        min = INT_MAX;
        for(int j{i}; j < n; j++) {
            if(min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    
    for(int i{}; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
