#include <iostream>
#include <utility>
using namespace std;

// Function prototypes
void heapify(int arr[], int size, int i);
void heapSort(int arr[], int size);

// Main function
int main() {
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    cout << "Heap sorted: [";
    for(int i = 0; i < size; i++) {
        // When reached the latest element, don't print the ","
        (i == size-1)
            ?cout << arr[i] << "]"
            :cout << arr[i] << ", ";
    }

    return 0;
}

// Function implementation
void heapify(int arr[], int size, int init) {
    int largest = init;
    int left_child = 2*init+1;
    int right_child = 2*init+2;

    if(left_child < size && arr[left_child] > arr[largest]) {
        largest = left_child;
    }

    if(right_child < size && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    if(largest != init) {
        swap(arr[init], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for(int i  = size-1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}