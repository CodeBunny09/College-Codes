#include<stdio.h>
#include<conio.h>

void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void displayArr(int arr[], int n);

void main(){
    int arr[] = {75, 8, 1, 16, 48, 3, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    printf("The unsorted aray is:\n");
    displayArr(arr, n);

    printf("\nEnter Your Choice :-\n1: Insertion Sort\n2: Selection Sort\n3: Exit\n");
    scanf("%d", &choice);

    switch (choice){
    case 1:
        insertionSort(arr, n);
        break;
    case 2:
        selectionSort(arr, n);
        break;
    case 3:
        printf("\n\nExitting the programme...");
        break;

    default:
        printf("\n\nPlease enter a correct choice...\n");
    }

    return;
}

void displayArr(int arr[], int n){ 
    printf("{ ");
    for(int i = 0; i < n; i++){
        printf("\t%d", arr[i]);
    }
    printf("\t}");
    return;
}

void insertionSort(int arr[], int n){
    int temp, j;
    for(int i = 1; i < n; i++){
        temp = arr[i];

        j = i-1;
        while (j >= 0 && arr[j] < temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;

        printf("\nPass: %d\t", i-1);
        displayArr(arr, n);

    }
    printf("\n\nThe array after insertion sort:\n");
    displayArr(arr, n);

    return;
}

void selectionSort(int arr[], int n){

    int temp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        printf("\nPass: %d\t", i+1);
        displayArr(arr, n);
    }

    printf("\n\nThe array after selection sort:\n");
    displayArr(arr, n);

    return;
}