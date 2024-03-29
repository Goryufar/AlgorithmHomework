#include <stdio.h>

int main() {
    
   int arr[] = {1,2,-10,2,4,1};
   int n = 6;
   int j =0;
   for(int i =1;i < n-1;i++){
       
         j = i;
        
            while(j>0 && arr[j-1]>arr[j]){
                
                int temp = arr[j];
                arr[j]= arr[j-1];
                arr[j-1] = temp;
                
                j = j-1;
            }
    }
   
    for(int k =0;k < 6;k++)
        printf("%d ",arr[k]);
    
    return 0;
}

