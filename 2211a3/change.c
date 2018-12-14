#include <stdio.h>
#include <stdlib.h>

//Nicholas Gardi - 250868721
//This program computes the most efficient amount of bills/coins to be used to pay

//prototype
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonies);
int main(void){
    int a, b, c, d, e, f, test;
    int x = 1;
    while(x = 1)
    {
        printf("\nPlease enter a dollar amount:");
        int test = scanf("%d", &a);
        fflush(stdin);
        //if input is less than or equal to 0
        if(a <= 0){
            printf("Error: please enter a valid dollar amount.");
        }
            //if input is not a number
        else if(test != 1){
            printf("Error: please enter a valid dollar amount.");
        }else{
            //call function to calculate bills
            pay_amount(a, &b, &c, &d, &e, &f);
            printf("$20s: %d\n", b);
            printf("$10s: %d\n", c);
            printf("$5s: %d\n", d);
            printf("$2s: %d\n", e);
            printf("$1s: %d\n", f);
            break;
        }
    }
    exit(0);
}
//function that calculates the bill/coins needed
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonies){
    *twenties=dollars/20;
    *tens=(dollars-(*twenties)*20)/10;
    *fives=(dollars-(*twenties)*20-(*tens)*10)/5;
    *toonies=(dollars-(*twenties)*20-(*tens)*10-(*fives)*5)/2;
    *loonies=dollars-(*twenties)*20-(*tens)*10-(*fives)*5-(*toonies)*2;
}