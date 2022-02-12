// DS Question 11

#include<stdio.h>
#include<conio.h>

int gcd(int a, int b);

void main(){
    
    int result = gcd(4, gcd(6, 8));
    printf("\nThe GCD of 4, 6 and 8 is: %d\n", result);
    
    return;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    gcd(b, a % b);
}