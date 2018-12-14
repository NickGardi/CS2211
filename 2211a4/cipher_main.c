//nicholas gardi - 250868721 - 4/7/17
//this main class tests the cipher functions in ciphers.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ciphers.h"

char * reader();

int main(void){
    int inputScan = 0;
    int cipher;
    char *plaintext;
    char *ciphertext;
    char *decrypted;
    double letters[26];

    //use helper function to read in plaintext
    printf("Input plaintext: ");
    plaintext = reader();
    printf("\nAvailable Ciphers:\n1) Caesar\n2) Vigenere\n\nSelect Cipher: ");
    //read in the cipher choice and verify that either a 1 or 2 was inputted
    inputScan = scanf("%d", &cipher);
    if(inputScan != 1 || (cipher != 1 && cipher != 2)){
        printf("Error: Bad Selection!\n");
        return 1;
    }
    printf("cipher :  %d", &cipher);
    //if cipher 1 is chosen, and a number key is given, apply the caesear cipher
    if(cipher == 1){
        int key;
        printf("Input key as number: ");
        inputScan = scanf("%d", &key);
        if(inputScan != 1){
            printf("Error: bad key!\n");
            return 1;
        }
        ciphertext = caesar_encrypt(plaintext, key);
        decrypted = caesar_decrypt(ciphertext, key);
    }
        //if cipher 2 was chosen
    else{
        char *key;
        int i;
        printf("Input key as string: ");
        //use helper method to read in key string
        key = reader();
        //make sure the key is valid
        for(i = 0; *(key + i) != 0; i++){
            if (!isalpha(*(key + i))) {
                printf("Error: Bad Key! Invalid Char!\n");
                return 1;
            }
        }
        //if all tests past, apply the cipher
        ciphertext = vigen_encrypt(plaintext, key);
        decrypted = vigen_decrypt(ciphertext, key);
    }
    printf("\nPlaintext:\n%s\nCiphertext:\n%s\nDecrypted Plaintext:\n%s\n", plaintext, ciphertext, decrypted);
    //call the freq analysis method
    freq_analysis(ciphertext, letters);
    return 0;
}

//helper method for reading user input
char * reader(){
    int size = 1;
    //allocate space on heap
    char *input = (char *) malloc(size);
    char nextChar;
    int i = 0;
    //increment the input buffer to avoid conflicts
    scanf(" %c", &nextChar);
    //loop through whole input
    while (nextChar != '\n'){
        size++;
        //allocate enough memory for string and null terminator
        input = (char *) realloc(input, size);
        *(input + i) = nextChar;
        scanf("%c", &nextChar);
        i++;
    }
    //null terminate the string
    *(input + i) = 0;
    return input;
}