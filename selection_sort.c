#include<stdio.h>

void selection_sort(int arr[], int size){
    for(int i = 0; i < size; i ++){
        int small = i;
        for(int j = i + 1; j < size; j ++){
            if(arr[j] < arr[small]){
                small = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

void main(){
    int arr[] = {5,6,7,8,4,3,2,1,0};
    selection_sort(arr, sizeof(arr)/4);
    for(int i = 0; i < sizeof(arr)/4; i ++){
        printf("%d ", arr[i]);
    }
}