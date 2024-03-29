#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));

       
        if (arr[pos] == x)
            return pos;
        
       
        if (arr[pos] < x)
            low = pos + 1;
    
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 60;

    int index = interpolationSearch(arr, n, x);

    if (index != -1)
        printf("found %d  at index %d\n", x, index);
    else
        printf(" %d  not found in the array\n", x);

    return 0;
}
