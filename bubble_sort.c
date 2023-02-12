#include<stdio.h>

void bubble_sort(int arr[], int size){
    for(int i = 0; i < size; i ++){
        int flag = 0;
        for(int j = 1; j < size - i; j ++){
            if(arr[j] < arr[j - 1]){
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            return;
        }
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    bubble_sort(arr, sizeof(arr)/4);
    for(int i = 0; i < sizeof(arr)/4; i ++){
        printf("%d ", arr[i]);
    }
}