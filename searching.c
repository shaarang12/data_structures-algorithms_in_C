#include<stdio.h>
#include<stdlib.h>

void createArray(int arr[], int n){
    for(int i = 0; i < n; i ++){
        arr[i] = rand() % 237;
    }
    printf("Array Created\n");
}
void printArray(int arr[], int size){
    printf("Array: ");
    for(int i = 0; i < size; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;

    int temp[end + 1];
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int p = start; p <= end; p++) {
        arr[p] = temp[p];
    }
    

}

void mergeSort(int arr[], int start, int end) {
    
    for(int i = start; i <= end; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void linearSearch(int arr[], int size, int target){
    for(int i = 0; i < size; i ++){
        if(arr[i] == target){
            printf("%d Found at Index: %d\n", target, i);
            return;
        }
    }
    printf("%d not Found\n", target);
}

void binarySearch(int arr[], int size, int target){
    int s = 0;
    int e = size - 1;
    int iter = 0;
    while(s <= e){        
        int m = s + (e - s) / 2;
        printf("Iteration #%d, START = %d, MID = %d, END = %d\n", iter++, s, m, e);
        if(arr[m] == target){
            printf("%d Found at Index: %d\n", target, m);
            return;
        }
        else if(target > arr[m]){
            s = m + 1;
        }
        else if(target < arr[m]){
            e = m - 1;
        }
    }
    printf("%d not Found\n", target);
}

int main(){
    printf("*****Program to Search for a Target*****\n\n");
    int size;
    int choice;
    int target;
    printf("Array Size: ");
    scanf("%d", &size);
    int arr[size];
    while(1){
        printf("\nCreate Array: '1'\n");
        printf("Array Elements: '2'\n");
        printf("Sort Array: '3'\n");
        printf("Linear Search: '4'\n");
        printf("Binary Search: '5'\n");
        printf("Exit: '0'\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            createArray(arr, size);
            break;
        case 2:
            printArray(arr, size);
            break;
        case 3:
            printf("Merge Sorting Array...\n");
            mergeSort(arr, 0, size - 1);
            printf("\n");
            printf("Sorted Array: ");
            for(int i = 0; i < size; i ++){
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 4:
            printf("Target: ");
            scanf("%d", &target);
            linearSearch(arr, size, target);
            printf("\n");
            break;
        case 5:
            printf("Merge Sorting Array...\n");
            mergeSort(arr, 0, size - 1);
            printf("\n");
            printf("Merged & Sorted Array: ");
            for(int i = 0; i < size; i ++){
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("Target: ");
            scanf("%d", &target);
            int start = 0;
            int end = size - 1;
            binarySearch(arr, size, target);
            printf("\n");
            break;
        case 0:
            exit(0);
        default:
            break;
        }

    }
}