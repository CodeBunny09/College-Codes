#include<stdio.h>
#include<conio.h>

void bubbleSort(int arr[], int n);
void displayArr(int arr[], int n);

void main(){
    int arr[] = {5, 3, 1, 6, 0, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The unsorted array is: \t");
    displayArr(arr, n);

    printf("\n\n");

    bubbleSort(arr, n);
    return ;
}

void displayArr(int arr[], int n){
    printf("{ ");
    for(int i = 0; i < n; i++){
        printf("\t%d", arr[i]);
    }
    printf("\t}");
    return;
}

void bubbleSort(int arr[], int n){

    int temp;
    for(int pass = 0; pass < n-1; pass++){
        for(int j = 0; j < n; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("\n Pass %d:\t", pass);
        displayArr(arr, n);
    }

    printf("\n\nThe final array is: \n");
    displayArr(arr, n);

    return;
}