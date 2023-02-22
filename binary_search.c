#include<stdio.h>

int search(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(nums[mid] == target)
        return mid;
        else if(target > nums[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main(){
    int arr[] = {3,4,5,6,7,89};
    int index =  search(arr, sizeof(arr)/4, 89);
    printf("%d\n", index);
}