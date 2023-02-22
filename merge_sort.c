#include<stdio.h>

void merge(int arr[], int start, int mid, int end){
    int size1 = mid - start + 1;
    int size2 = end - mid;
    int left[size1];
    int right[size2];
    for(int i = 0; i < size1; i ++){
        left[i] = arr[start + i];
    }
    for(int j = 0; j < size2; j ++){
        right[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while(i < size1 && j < size2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i ++;
        }
        else{
            arr[k] = right[j];
            j ++;
        }
        k ++;
    }

    while(i < size1){
        arr[k] = left[i];
        i ++;
        k ++;
    }
    
    while(j < size2){
        arr[k] = right[j];
        j ++;
        k ++;
    }
}

void merge_sort(int arr[], int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[] = {7,6,5,4,3,2,7,1,-1};
    merge_sort(arr, 0, sizeof(arr)/4 - 1);
    for(int i = 0; i < sizeof(arr)/4; i ++){
        printf("%d ", arr[i]);
    }
}