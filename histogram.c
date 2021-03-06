#include<stdio.h>
#include<conio.h>          
#include<stdlib.h>

void main(){

    int i, j; //Declaring iterative variables
    int arr[] = {0, 1, 5, 3, 7, 8, 6, 3, 8, 6, 9, 4, 2, 8, 0, 5, 6, 8 ,4, 0, 9, 7, 5, 4, 3, 2, 7, 8, 9, 4, 8, 0, 7, 5, 3, 2, 5, 6, 7, 8, 4, 3}; //Declaring and defining an array of numbers from 0 to 9
    int freq[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Declaring array for Frequency Distribution

    int num = sizeof(arr)/sizeof(arr[0]); // Calculating the size of the array  


    // Preparing the frequency distribution table
    for(i = 0; i <= 9; i++){
	    for(j = 0; j <= num; j++){
            if(i == arr[j]){
                freq[i]++;
            }
	    }
    }

    // Printing Out The Histogram
    // clrscr();
    printf("\n\nTotal Elements: %d\n\nFrequency Distribution Histogram:-\n", num);
    for(i = 0; i <= 9; i++){
	    printf("\n%d |-", i);

        for(j = 1; j <= freq[i]; j++){
            printf("#");
        }
        printf("  %d", freq[i]);
    }
    // getch();
    
    return;
}