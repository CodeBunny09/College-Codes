// Data Structures Question 9

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 200

int top = -1, stack[size];
void push(int val);
void pop();
void display();

void main(){
    int i = 0;
    int arr[] = {5, 9, 34, 17, 32};
    int n = sizeof(arr) / sizeof(arr[n]);
    clrscr();
    for(i = 0; i < n; i++){
	push(arr[i]);
	display();
	getch();
    }

    for (i = 0; i < 3; i++){
	pop();
	display();
	getch();
    }
    getch();
    return;
}

void push(int val){
    if(top == size - 1){
	printf("\nStack Overflow...\n");
    }else {
	printf("\nAdded element is: %d\n", val);
	top++;
	stack[top] = val;
    }
    return;
}

void pop(){
    if(top == -1){
	printf("\nStack Underflow...\n");
    } else {
	printf("\nDeleted element is %d", stack[top]);
	top--;
    }
    return;
}

void display(){
    int i;
    if(top == -1){
	printf("\nEmpty Stack... Nothing to display..\n");
    } else {
	for (i = top; i >= 0; --i){
	    printf("\n|-\t%d\t-|", stack[i]);
        }
        printf("\n\n");
    }
    return;
}