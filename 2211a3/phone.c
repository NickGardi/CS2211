#include <stdio.h>
#include <stdlib.h>
//Nicholas Gardi - 250868721
//C program that takes a phone number as standard input from the user and outputs the formatted number
int main(void){
    int a, b, c, d, e, f, g, h, i, j, y;
    char A, B, C, D, E, F, G, H, I, J;
    char x;
    printf("(enter at least 10 characters) Input phone number: ");
    //read in the number char by char
    y = scanf("%c %c %c %c %c %c %c %c %c %c", &A,&B,&C,&D,&E,&F,&G,&H,&I,&J);
    fflush(stdin);
    //assign integer values all 0
    a=A-'0';
    b=B-'0';
    c=C-'0';
    d=D-'0';
    e=E-'0';
    f=F-'0';
    g=G-'0';
    h=H-'0';
    i=I-'0';
    j=J-'0';

    //error if not a 10 digit long number
    if(y != 10 ||a<0||a>9||b<0||b>9||c<0||c>9||d<0||d>9||e<0||e>9||f<0||f>9||g<0||g>9||h<0||h>9||i<0||i>9||j<0||j>9){
        printf("Error!\n");
        exit(0);
    }

    //print the format options
    printf("Format Options: \n A.Local \n B. Domestic \n C.International \n D. Odd");

    printf("\nInput Option: ");
    scanf("%c", &x);

    //option A or a
    if(x == 'A' || x == 'a'){
        printf("Phone Number: %d%d%d-%d%d%d%d", d, e, f, g, h, i, j);
        return 0;

    }
        //option B or b
    else if(x == 'B' || x == 'b'){
        printf("Phone Number: (%d%d%d) %d%d%d-%d%d%d%d", a, b, c, d, e, f, g, h, i, j);
        return 0;
    }
        //option C or c
    else if(x == 'C' || x == 'c'){
        printf("Phone Number: +1-%d%d%d-%d%d%d-%d%d%d%d", a, b, c, d, e, f, g, h, i, j);
        return 0;
    }
        //option D or d
    else if(x == 'D' || x == 'd'){
        printf("Phone Number: 0%d%d%d 0%d%d%d %d%d%d%d", a,b,c,d,e,f,g,h,i,j);
        return 0;
    }
    //error if bad format char is given
    if(x != 'A' && x != 'a' && x != 'B' && x != 'b' && x != 'C' && x != 'c' && x !='D' && x!='d') {
        printf("Error: invalid format option\n");
        exit(1);
    }
}
