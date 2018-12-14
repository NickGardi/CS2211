#include <stdio.h>
#include <stdlib.h>
//Nicholas Gardi - 250868721
//this program takes in and validates multiple dates and prints out the latest date
int main(void){
    int mm, dd, yy, x;
    int latestMonth = 0;
    int latestDay = 0;
    int latestYear = 0;
    //takes input until 0/0/0 is entered
    while(x){
        printf("enter the date (mm/dd/yy): ");
        int test = scanf("%d/%d/%d", &mm, &dd, &yy);
        fflush(stdin);
        
        //if 0/0/0 is entered
        if(mm==0 && dd==0 && yy==0) {
            break;
        }
        //validating input
        if(test != 3){
            printf("Error: Invalid date format\n");
	    while(getchar() != '\n');
	    continue;
        }
        else if(mm>12 || mm<1){
            printf("Error: Invalid month number!\n");
        }
        else if(dd<1 || dd>31){
            printf("Error: Invalid day number!\n");
        }
        else if(yy>99 || yy<0){
            printf("Error: Invalid year number!\n");
        }
        else{
            //if year entered is greater than current latest year
            if (yy>latestYear){
                //update the latest values
                latestYear=yy;
                latestDay=dd;
                latestMonth=mm;
            }
                //if year entered is the same as current latest year
            else if(yy==latestYear){
                //if month entered is greater than current latest month
                if (mm>latestMonth){
                    //update the latest values
                    latestYear=yy;
                    latestDay=dd;
                    latestMonth=mm;
                }
                    //if entered month is the same as the current latest month
                else if(mm==latestMonth) {
                    //if day entered is greater than current latest day
                    if(dd>latestDay){
                        //set the latest values
                        latestYear=yy;
                        latestDay=dd;
                        latestMonth=mm;
                    }
                }
            }
        }
    }

    if(latestDay == 0 && latestMonth == 0 && latestYear == 0){
        printf("Error, no dates added");
        exit(1);
    }else{
        //print the latest date
        printf("%d/%d/%d is the latest date", latestMonth, latestDay, latestYear);
        exit(0);
    }
}