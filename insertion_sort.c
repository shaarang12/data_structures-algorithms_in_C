#include<stdio.h>

void insertion_sort(int arr[], int size){
    for(int i = 0; i < size - 1; i ++){
        for(int j = i + 1; j > 0; j --){
            if(arr[j] < arr[j - 1]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
                break;
        }
    }
}
void main(){
    int arr[] = {3,4,5,1,2,0,10,8,7,19,11};
    insertion_sort(arr, sizeof(arr)/4);
    for(int i = 0; i < sizeof(arr)/4; i ++){
        printf("%d ", arr[i]);
    }
}