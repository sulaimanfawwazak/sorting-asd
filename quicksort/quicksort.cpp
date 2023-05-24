#include <iostream>
#include <utility>
using namespace std;

// Function protoytpes
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);

// Main function
int main() {
    int arr[] = {3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size-1);
    
    cout << "Quick sorted: [";
    for(int i = 0; i < size; i++) {
        // When reached the latest element, don't print the ","
        (i == size-1)
            ?cout << arr[i] << "]"
            :cout << arr[i] << ", ";
    }
    return 0;
}

// Function implementation
int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;

    for(int j = start; j < end; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[end]);
    return (i+1);
}

void quickSort(int arr[], int start, int end) {
    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}
