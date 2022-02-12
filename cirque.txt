// DS Question 11

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *FRONT=NULL;
struct node *REAR=NULL;


// Helper functions
int isEmpty();

// Driver functions
void enqueue(int val);
void dequeue(int val);
void display();

void main(){
    int i;
    int arr[] = {5, 7, 0, 6, 3, 9};
    int to_del[] = {6, 9, 5};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(to_del) / sizeof(to_del[0]);

    clrscr();
    printf("\nEnqueue:\n");
    for(i = 0; i < m; i++){
        enqueue(arr[i]);
        display();
        printf("\n\n");
        getch();
    }

    printf("\n\n\nDequeue:\n");
    for(i = 0; i < n; i++){
        dequeue(to_del[i]);
        display();
        printf("\n\n");
        getch();
    }
    return;
}

int isEmpty(){
    if((FRONT == NULL) && (REAR == NULL)){
        return 1;
    }
    return 0;
}

void enqueue(int val){
    struct node* n;

    n = (struct node*)malloc(sizeof(struct node));
    n -> val = val;
    n -> next = NULL;

    if(isEmpty()){
        FRONT = REAR = n;
        REAR -> next = FRONT;
    } else {
        REAR -> next = n;
        REAR = n;
        n -> next = FRONT;
    }
    printf("\nElement Added: %d", val);
    return;
}

void dequeue(int val){
    struct node* t;
    struct node* t2;
    if(isEmpty()){
        printf("\n The Queue Is Empty.....");
    } else {
        while(FRONT -> val != val){
            t = FRONT;
            FRONT = FRONT -> next;
            REAR = t;
            REAR -> next = FRONT;
        }
        t2 = FRONT;
        if(FRONT == REAR){
            FRONT = REAR = NULL;
            free(t2);
        } else {
            FRONT = FRONT -> next;
            REAR -> next = FRONT;
            free(t2);
        }
        printf("\nElement Deleted: %d", val);
    }
    return;
}

void display(){
    struct node *t;
    if(isEmpty()){
        printf("\nThe Queue Is Empty....");
    } else {
        printf("\nItems: {");
        t = FRONT;
        do{
            printf("\t%d", t -> val);
            t = t -> next;
        } while(t != FRONT);
        printf("\t}");
    }
}