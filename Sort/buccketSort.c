#include <stdio.h>  

int getMax(int arr[], int n)  
{  
  int max = arr[0];  
  for (int i = 1; i < n; i++)  
    if (arr[i] > max)  
      max = arr[i];  
  return max;  
}  
void bucket(int arr[], int n) 
{  
  int max = getMax(arr, n); 
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    bucket[arr[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      arr[j++] = i;  
      bucket[i]--;  
    }  
  }  
}  
void printArr(int arr[], int n) 
{  
  for (int i = 0; i < n; ++i)  
    printf("%d  ", arr[i]);  
}  
int main()  
{  
   int arr[] = {10,2310,0,120,2};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Before  \n");  
  printArr(arr, n);  
  bucket(arr, n);  
  printf("\nAfter \n");  
  printArr(arr, n);  
}  