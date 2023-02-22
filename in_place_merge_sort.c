#include <stdio.h>
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

int main() {
    printf("*****Program for Merge Sort*****\n\n");
    int n;
    printf("Enter the Array Size: ");
    if(!scanf("%d", &n)){ 
        printf("Size Can Contain Positive Integer Value Only\n");
        return 0;
    }
    int arr[n];
    printf("Enter the Elements: ");
        for(int i = 0; i < n; i ++){
            if(!scanf("%d", &arr[i])){
                printf("Array Elements Can Contain Integers Only\n");
                return 0;
            }
        }
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSteps\n");
    mergeSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
