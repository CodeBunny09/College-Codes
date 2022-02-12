// Q2 Data Structures
#include<stdio.h>
#include<conio.h>

void bubbleSort(int arr[], int n);
void display(int arr[], int n);


void main(){
    int arr[] = {5, 3, 1, 6, 0, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The unsorted array is:\t");
    display(arr, n);
    printf("\n");
    bubbleSort(arr, n);

    return;
}

void display(int arr[], int n){

    for(int i = 0; i<n; i++){
        printf("%d, ", arr[i]);
    }
    return;
}

void bubbleSort(int arr[], int n){

    int temp;
    for(int pass = 0; pass < n-1; pass++){
        for(int i = 0; i<n; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;   
            }
        }
        printf("\nPass %d:\t", pass+1);
        display(arr, n);
    }
    printf("\n\nThe final sorted array is:\n");
    display(arr, n);

    return;
}