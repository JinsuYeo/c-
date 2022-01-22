#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000000];

bool compare(int a, int b) {
    return a < b;
}

int main(int argc, const char * argv[]) {
    int n{};
    scanf("%d", &n);
    
    for(int i{}; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(&arr[0], &arr[n], compare);

    
    for(int i{}; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
