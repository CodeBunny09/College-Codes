#include<stdio.h>
#include<conio.h>

int binarySrc(int arr[], int l, int u, int x);

void main(){
    int arr[] = {4, 7, 3, 2, 1, 7, 9, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result;
    int sorted_arr [] = {0, 1, 2, 3, 4, 7, 7, 9};

    result = binarySrc(sorted_arr, 0, n, 7);

    result == -1 ? printf("\nElement is not present in the array\n") : printf("\nElement present in index: %d\n", result);

    return;

}

int binarySrc(int arr[], int l, int u, int x){
    
    int mid;

    while(l <= u){

        mid = l + (u - l) / 2;

        if (arr[mid] == x){
            return mid;
        }
        if(arr[mid] > x){
        return binarySrc(arr, l, mid - 1, x);
        }
        return binarySrc(arr, mid + 1, u, x);

    }
    
    return -1;
}