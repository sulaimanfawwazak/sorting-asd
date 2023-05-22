#include <iostream>
using namespace std;

// Function to find the biggest element
int maxElem(int arr[], int size) {
    int max = arr[0];
    for(int i = 0; i < size; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

// Function to sort the elements by their digits
void countingSort(int arr[], int size, int digit) {
    const int max = 10;
    int output[size];
    int count[max] = {0};

    for(int i = 0; i < max; i++)
        count[i] = 0;
    
    // Determine count of elements
    for(int i = 0; i < size; i++) 
        count[(arr[i] / digit) % 10]++;

    // Determine the cumulative count
    for(int i = 1; i < max; i++)
        count[i] = count[i] + count[i - 1];

    // Sort the elements
    for(int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / digit) % 10] - 1] = arr[i];
        count[(arr[i] / digit) % 10]--;
    }

    for(int i = 0; i < size; i++)
        arr[i] = output[i];
}

// Function for radix sort
void radixSort(int arr[], int size) {
    int max = maxElem(arr, size);

    for(int place = 1; max/place > 0; place = place * 10)
        countingSort(arr, size, place);
}

int main() {
    int arr[10] = {182, 309, 404, 568, 686, 398, 330, 25, 132, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, size);
    
    cout << "Radix sorted: [";
    for(int i = 0; i < size; i++) {
        // When reached the latest element, don't print the ","
        (i == size-1)
            ?cout << arr[i] << "]"
            :cout << arr[i] << ", ";
    }
    return 0;
}
