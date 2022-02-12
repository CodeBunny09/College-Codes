#include<stdio.h>
#include<conio.h>

void display(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);

void main(){
    int arr[] = {75,8,1,16,48,3,7,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int choice;

    printf("The unsorted array is: \n");
    display(arr, n);

    printf("\n\nEnter your choice:\n1:\tInsertion Sort\n2:\tSelection Sort\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        insertion_sort(arr, n);
        break;

    case 2:
        selection_sort(arr, n);
        break;
    
    default:
        printf("Please enter a correct option...!!\n");
        break;
    }

    return;
}

void display(int arr[], int n){

    for(int i = 0; i<n; i++){
        printf("%d, ", arr[i]);
    }
    return;
}

void insertion_sort(int arr[], int n){
    
    for(int i = 0; i<n; i++){
        int temp = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > temp){
            
        }
    }
}

void selection_sort(int arr[], int n){
    printf("Selection Sort\n");
}