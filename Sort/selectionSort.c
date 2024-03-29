
#include <stdio.h>

int main() {
    
   int arr[] = {1,2,-10,0,4,100};
   int n = 6;
  
   for(int j =0;j < n-1;j++){
    
        int iMin = j;
        
        for(int i = j+1; i < n;i++){
            if(arr[i] < arr[iMin])
                iMin = i;
        }

        if(iMin !=j){
            int temp =  arr[iMin];
            arr[iMin] = arr[j];
            arr[j] = temp;
        }
            
       
       
    }
   
    for(int k =0;k < 6;k++)
        printf("%d ",arr[k]);
    
    return 0;
}

