#include <stdio.h>
int LinearSearch(int arr[] ,int n, int value);

int main()
{
    int array[] =  {1,2,-10,2,4,0};
    int n = sizeof(array)/sizeof(array[0]);
    
    int index  = LinearSearch(array,n,0); // we search for example 0
    // Time complexity is Big O(n)
    if(index != -1){
        printf("Ellement found in array at the index %d" , index);
    }
    else{
           printf("Ellement NotFound" );
    }
    return 0;
}

int LinearSearch(int arr[] ,int n, int value){
    for(int i = 0;i < n;i++){
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}