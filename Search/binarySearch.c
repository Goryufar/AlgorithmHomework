
#include <stdio.h>


int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}


int main(void)
{
	int arr[] = {1,2,5,10,15,20};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	int index  = binarySearch(arr, 0, n - 1, x);
	if(index != -1){
        printf("found your number at the index %d",index);
    }
    else{
          printf("integer not found");
    }
	return 0;
}
