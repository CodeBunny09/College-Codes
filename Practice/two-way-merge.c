#include<stdio.h>
#include<conio.h>

void merge(int arr[], int arr2[], int m, int n);
void displayArr(int arr[], int n);


void main(){
    int arr[] = {1, 3, 5, 6, 14, 15, 28, 29};
    int arr2[] = {3, 4, 7, 9, 10, 14, 16, 27};

    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nThe first array is:\n");
    displayArr(arr, m);

    printf("\nThe second array is:\n");
    displayArr(arr2, n);
    
    merge(arr, arr2, m, n);

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

void merge(int arr[], int arr2[], int m, int n){
    
    int j = 0, k = 0;

    printf("\n\nArray after 2 way merge :-\n");

    printf("\n{\t");

    while(j < m && k < n){
        if(arr[j] <= arr2[k]){
            printf("\t%d", arr[j]);
            j++;
        } else {
            printf("\t%d", arr2[k]);
            k++;
        }

    }
    for(j; j < m; j++){
        printf("\t%d", arr[j]);
    }
    for(k; k < n; k++){
        printf("\t%d", arr2[k]);
    }

    printf("\t}\n");

    return;
}