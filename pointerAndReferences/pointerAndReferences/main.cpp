#include <iostream>

using namespace std;

void print(const int arr[], size_t size);
int* apply_all(int arr1[], size_t arr1_size, int arr2[], size_t arr2_size);

int main(int argc, const char * argv[]) {
    const size_t array1_size {5};
    const size_t array2_size {3};
    
    int array1[] {1, 2, 3, 4, 5};
    int array2[] {10, 20, 30};
    
    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size {array1_size * array2_size};
    
    cout << "Result: ";
    print(results, results_size);
    
    cout << endl;
    
    delete [] results;
    
    return 0;
}

void print(const int arr[], size_t size){
    cout << "[ ";
    for(size_t i{}; i < size; i++)
        cout << arr[i] << " ";
    cout << "]";
    cout << endl;
}

int* apply_all(int arr1[], size_t arr1_size, int arr2[], size_t arr2_size){
    size_t size {0};
    size = arr1_size * arr2_size;
    int* new_arr {nullptr};
    new_arr = new int[size];
    
    for(size_t i{}; i < arr2_size; i++) {
        for(size_t j{}; j < arr1_size; j++){
            *(new_arr + i*5 + j) = arr2[i] * arr1[j];
        }
    }
    
    return new_arr;
}
