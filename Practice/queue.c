// Data structures Q5

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val);
void dequeue();
void display();

void main(){
    int choice;
    int val;

    int arr [] =  {61, 16, 8, 27};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\n\nPerforming enqueue or insertion operations....\n");
    for(int i = 0; i < n; i++){
        enqueue(arr[i]);
        display();
    }

    printf("\n\nPerforming dequeue or deletion operations....\n");
    for(int i = 0; i < 3; i++){
        dequeue();
        display();
    }
    // while(1){
    //     printf("\nEnter your choice:\n1: Enqueue\n2: Dequeue\n3: Display\n4: Exit\n");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //         printf("\nEnter the value you want to enqueue: ");
    //         scanf("%d", &val);
    //         enqueue(val);
    //         break;
    //     case 2:
    //         dequeue();
    //         break;
    //     case 3:
    //         display();
    //         break;
    //     case 4:
    //         printf("\nExitting...");
    //         return;
    //     default:
    //         printf("\nEnter a correct option......\n");
    //         break;
    //     }
    // }

    return;
}

void enqueue(int val){
    struct node *newNode = malloc(sizeof(struct node));
    newNode -> data = val;
    newNode -> next = NULL;
    if(front == NULL && rear == NULL){
        rear = front = newNode;
        printf("\nAdded element: %d to an empty queue.\n", val);
    } else {
        rear -> next = newNode;
        rear = newNode;
        printf("\nAdded element: %d to the queue.\n", val);
    }
    return;
}

void dequeue(){
    struct node *temp;
    if(front == NULL){
        printf("\nQueue is empty...");
    } else {
        temp  = front;
        front = front -> next;

        if(front == NULL){
            rear = NULL;
        }

        printf("\nElement Deleted: %d\n", temp -> data);
        free(temp);
    }
    return;
}

void display(){
    struct node *temp = front;
    if(temp){
        printf("|-\t");
        while (temp)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("-|");
    } else {
        printf("\nEmpty Queue.....");
    }
    return;
}