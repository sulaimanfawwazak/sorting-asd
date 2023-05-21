#include <iostream>
#include <sys/time.h>
#include <iomanip>
using namespace std;

// Function for shell sort
void shellSort(int arr[], int size) {
    for (int intv = size / 2; intv > 0; intv /= 2) {
        for (int i = intv; i < size; i++) {
        int temp = arr[i];
        int j = i;
        while (j >= intv && arr[j - intv] > temp) {
            arr[j] = arr[j - intv];
            j -= intv;
        }
        arr[j] = temp;
        }
    }
}

// main function
int main() {
    int arr[100] = {184, 78, 187, 199, 22, 17, 130, 124, 160, 195, 86, 154, 97, 214, 152, 172, 240, 204, 27, 77, 73, 26, 161, 247, 55, 66, 143, 194, 54, 121, 72, 33, 219, 169, 196, 61, 147, 67, 206, 117, 149, 164, 208, 227, 235, 209, 171, 191, 92, 159, 221, 237, 112, 23, 234, 137, 20, 236, 9, 45, 115, 65, 212, 202, 28, 132, 179, 36, 52, 56, 16, 38, 43, 89, 156, 238, 48, 162, 11, 99, 106, 207, 47, 118, 50, 173, 186, 217, 181, 151, 224, 128, 63, 35, 71, 239, 136, 116, 246, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Start measuring the time
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    // Shell sort function call
    shellSort(arr, size);

    // Stop measuring the time and calculate the elapsed time
    gettimeofday(&end, 0);

    cout << "Shell sorted: [";
    for(int i = 0; i < size; i++) {
        // When reached the latest element, don't print the ","
        (i == size-1)
            ?cout << arr[i] << "]"
            :cout << arr[i] << ", ";
    }

    long long seconds = end.tv_sec - begin.tv_sec;
    long long microseconds = end.tv_usec - begin.tv_usec;
    long double elapsed = seconds*1000 + microseconds*1e-3;
    cout << "\n\nThe execution time is " << setprecision(10) << elapsed << " milliseconds";

    return 0;
}