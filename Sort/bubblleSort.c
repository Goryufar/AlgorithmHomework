
#include <stdio.h>

int main() {
    
   int arr[] = {1,2,-10,2,4,0};
   int n = 6;
   int j =0;
   for(int i =1;i < n;i++){
       for(int j=0; j < n-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1]= arr[j];
                    arr[j] = temp;
                }
       }
    }
   
    for(int k =0;k < 6;k++)
        printf("%d ",arr[k]);
    
    return 0;
}