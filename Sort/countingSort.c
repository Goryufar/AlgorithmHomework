#include <stdio.h>

void CountingSort(int A[],int n,int k){
   int B[n];
   int C[k+1];
   
   for(int i = 0 ; i <=k;i++){
       C[i]=0;
   }
    for(int j = 0 ; j <n;j++){
       C[A[j]]=C[A[j]]+1;
    }
     for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }
   
   
   for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
   
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

}

int getMax(int arr[],int size){
    int max = arr[0];
    for(int i =0; i < size;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int arr[]  = {0,40,1,5,30};// it should be non negative
    int n = sizeof(arr)/sizeof(arr[0]);
  
    CountingSort(arr,n,getMax(arr,n));
    return 0;
}