#include <iostream>
using namespace std;

// Function to merge the sub-arrays
void merge(int arr[], int start, int mid, int end) {
    // Create the sub-arrays
    int size1 = mid - start + 1;
    int size2 = end - mid;

    int *X = new int[size1];
    int *Y = new int[size2];

    for(int i = 0; i < size1; i++) {
        X[i] = arr[start+i];
    }
    for(int j = 0; j < size2; j++) {
        Y[j] = arr[mid + 1 + j];
    }

    // Set the indices for the sub-arrays
    int i, j, k;
    i = j = 0;
    k = start;

    // Compare the elements in the sub-arrays
    // and place it into the main array
    while(i < size1 && j < size2) {
        if(X[i] <= Y[j]) {
            arr[k] = X[i];
            i++;
        }
        else {
            arr[k] = Y[j];
            j++;
        }
        k++;
    }

    // Put the remaining elements into the main array
    while(i < size1) {
        arr[k] = X[i];
        i++;
        k++;
    }

    while(j < size2) {
        arr[k] = Y[j];
        j++;
        k++;
    }

    delete[] X;
    delete[] Y;
}

void mergeSort(int arr[], int start, int end) {
    if(start < end) {
        // Create the midpoint where array is divided
        int mid = (end - start) / 2 + start;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Call the merge function
        merge(arr, start, mid, end);
    }
}


int main() {
    int arr[] = {182, 309, 404, 568, 686, 398, 330, 25, 132, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size-1);

    cout << "Merge sorted: [";
    for(int i = 0; i < size; i++) {
        // When reached the latest element, don't print the ","
        (i == size-1)
            ?cout << arr[i] << "]"
            :cout << arr[i] << ", ";
    }

    return 0;
}
