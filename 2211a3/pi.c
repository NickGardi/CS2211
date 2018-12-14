#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Nicholas Gardi - 250868721
//this program takes estimates the value of pi using an arithmetic approach
//gcc pi.c -o pi -lm 	to compile

double estimate_pi(long long n);

int main(){
    srand(time(0));
    long long int N;
    printf("Enter the value for N: ");
    scanf("%lld", &N);
    double sum = 0;
    double values[10];
    int i;
    //calculate pi 10 times
    for(i = 0; i < 10; i++){
        values[i] = estimate_pi(N);
        printf("%.10f\n", values[i]);
        sum = sum + values[i];
    }
    double mean = sum / 10; //calculate mean
    double x = 0;
    for(i = 0; i < 10; i++){
        x = x + pow( (values[i] - mean), 2); //calculations for std dev
    }
    x = x / 10;
    double std = sqrt(x);
    //print the mean and standard deviation
    printf("\nMean: %.10f\n", mean);
    printf("Standard Deviation: %.10f\n", std);
}

double estimate_pi(long long n){

    long long int i;
    long long int pointsInCircle = 0;
    double ratio;
    //loop n times
    for(i = 1; i <= n; i++){
        //set x and y to random values between 1-0
        double x = (double)rand()/(double)RAND_MAX;
        double y = (double)rand() / (double)RAND_MAX;
        //if x*x+y*y is <=1, increment pointsInCircle
        if( ( (x*x) + (y*y) ) <= 1){
            pointsInCircle = pointsInCircle + 1;
        }
    }
    //ratio
    ratio = ((double)pointsInCircle /(double) n);
    //pi = 4*ratio
    return 4*ratio;
}