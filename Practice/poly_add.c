#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int power;
    struct node *next;
};

void display_poly(struct node *exp);
void addnode(int coeff, int power, struct node **prev_node);
void addpoly(struct node *poly1, struct node *poly2, struct node *result);

void main(){

    struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    addnode(6, 3, &poly1);
    addnode(10, 2, &poly1);
    addnode(0, 1, &poly1);
    addnode(5, 0, &poly1);

    printf("\nPolynomial 1:\t");
    display_poly(poly1);
    
    addnode(4, 2, &poly2);
    addnode(2, 1, &poly2);
    addnode(1, 0, &poly2);

    printf("\nPolynomial 2:\t");
    display_poly(poly2);
    
    result = (struct node*)malloc(sizeof(struct node));

    addpoly(poly1, poly2, result);

    printf("\nAdded Polynomial :\t");
    display_poly(result);
    
    return;
}

void addnode(int coeff, int power, struct node **prev_node){    

    struct node *node1, *node2;

    node2 = *prev_node;
    if(node2 == NULL){
        node1 = (struct node*)malloc(sizeof(struct node));
        node1 -> coeff = coeff;
        node1 -> power = power;
        *prev_node = node1;
        node1 -> next = (struct node*)malloc(sizeof(struct node));
        node1 = node1 -> next;
        node1 -> next = NULL;

    } else {
        node1 -> coeff = coeff;
        node1 -> power = power;
        node1 -> next = (struct node*)malloc(sizeof(struct node));
        node1 = node1 -> next;
        node1 -> next = NULL;
    }
    return;
}

void display_poly(struct node *exp){
    while (exp -> next){
        
        if (exp -> power == 0){
            printf("%d", exp -> coeff);
        } else if (exp -> power == 1){
            printf("%dx", exp -> coeff);
        } else {
            printf("%dx^%d", exp -> coeff, exp -> power);
        }
        
        exp = exp -> next;
        
        if (exp -> coeff >= 0 && exp -> next != NULL){
            printf(" + ");
        } else {
            printf("  ");
        }
        
    }
    return;   
}

void addpoly(struct node *poly1, struct node *poly2, struct node *result){

    while (poly1 -> next && poly2 -> next){
        
        if(poly1 -> power > poly2 -> power){
            result -> power = poly1 -> power;
            result -> coeff = poly1 -> coeff;
            poly1 = poly1 -> next; 
        } else if (poly2 -> power > poly1 -> power){
            result -> power = poly2 -> power;
            result -> coeff = poly2 -> coeff;
            poly2 = poly2 -> next;
        } else {
            result -> power = poly1 -> power;
            result -> coeff = poly1 -> coeff + poly2 -> coeff;
            poly1 = poly1 -> next;
            poly2 = poly2 -> next;
        }

        result -> next = (struct node*)malloc(sizeof(struct node));
        result = result -> next;
        result -> next = NULL;
    }

    while (poly1 -> next || poly2 -> next){
        if(poly1 -> next){
            result -> power = poly1 -> power;
            result -> coeff = poly1 -> coeff;
            poly1 = poly1 -> next;
        }
        if(poly2 -> next){
            result -> power = poly2 -> power;
            result -> coeff = poly2 -> coeff;
            poly2 = poly2 -> next;
        }
        result -> next = (struct node*)malloc(sizeof(struct node));
        result = result -> next;
        result -> next = NULL;
    }
}