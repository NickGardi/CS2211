//nicholas gardi - 250868721 - 4/7/17
//this class contains all the cipher encrypt and decrypt functions as well as the analysis fuction

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "ciphers.h"


char * caesar_encrypt(char *plaintext, int key){
    int i;
    //allocate memory on the heap
    char *encrypted = (char *) malloc( (strlen(plaintext) + 1) * sizeof(char) );
    //apply caesar encryption
    for(i = 0; *plaintext != 0; i++){
        char letter = *plaintext;
        if(isalpha(letter)){
            int j;
            //if the char is a letter, make it uppercase
            letter = toupper(letter);
            //if key is > 0, increment the letter (key%26) times
            if(key <= 0){
                //if the key is <= 0, decrement the letter (key%26) times
                for(j = (key % 26); j < 0; j++){
                    letter--;
                    if(letter < 'A') {
                        letter = 'Z';
                    }
                }
            }
            else{
                for(j = (key % 26); j > 0; j--){
                    letter++;
                    //if the ascii value of the letter goes past Z then it should wrap around to A
                    if(letter > 'Z') {
                        letter = 'A';
                    }
                }
            }
        }
        *(encrypted + i) = letter;
        plaintext++;
    }
    //null terminate the string
    *(encrypted + i) = 0;
    return encrypted;
}

//decrypt is encrypt with (-1)*key
char * caesar_decrypt(char *ciphertext, int key){
    return caesar_encrypt(ciphertext, (0 - key));
}


char * vigen_encrypt(char *plaintext, char *key){
    int i;
    int keyLength = strlen(key);
    int textLength = strlen(plaintext);
    //allocate memory
    char *encrypted = (char *) malloc( (textLength + 1) * sizeof(char) );
    char paddedKey[keyLength * ((textLength /keyLength) + 1)];

    int j = 0, numOfKeyWords = ((textLength/keyLength) + 1);
    for(i = 0; i < numOfKeyWords; i++){
        strcpy(paddedKey + j, key);
        j += keyLength;
    }
    //null terminate string
    paddedKey[j] = 0;

    //cycle through plaintext
    for(i = 0; *plaintext != 0; i++){
        //plaintext letter
        char letter = *plaintext;
        //letter to use for encryption
        char letterInKey = toupper(paddedKey[i]);
        //if the letter is alpha
        if(isalpha(letter)){
            //make it uppercase
            letter = toupper(letter);

            //encrypt
            while(letterInKey - 'A' != 0){
                letter++;
                letterInKey--;

                //Z --> A
                if(letter > 'Z'){
                    letter = 'A';
                }
            }
        }
        plaintext++;
        *(encrypted + i) = letter;
    }
    //null terminate string
    *(encrypted + i) = 0;
    return encrypted;
}

//decrypt, create a key to use with encrypt to get the result
char * vigen_decrypt(char *ciphertext, char *key){
    int i;
    char decryptKey[strlen(key) + 1];

    for(i = 0; *key != 0; i++){
        //letter = first char in the key
        char letter = *key;
        //if the letter is alpha
        if(isalpha(letter)){
            //uppercase it
            letter = toupper(letter);
            //decrypt it
            letter = (65+(26-(letter-65)%26));
        }
        //add new letter to decryptKey
        decryptKey[i] = letter;
        key++;
    }
    //null terminate the key
    decryptKey[i] = 0;
    //use the encryption function to decrypt the text.
    //ex: a shift right 10 then another shift right of (26-10) = the original letter
    return vigen_encrypt(ciphertext, decryptKey);
}


void freq_analysis(char *ciphertext, double letters[26]) {
    int i;
    char letter;
    double total;

    //zero the values in the array
    for (i = 0; i < 26; i++) {
        *(letters + i) = 0;
    }

    //lop through the letters in the string
    for (i = 0; *ciphertext != 0; i++) {
        letter = *ciphertext;
        //if is alpha
        if (isalpha(letter)) {
            //uppercase it
            toupper(letter);
            //sum the frequency
            *(letters + (letter - 65)) += 1;
            total++;
        }
        ciphertext++;
    }

    //print the analysis
    printf("Frequency Analysis:\n");
    printf("-------------");
    letter = 'A';
    for(i = 0; i < 26; i++){
    *(letters + i) = (*(letters + i) / total) * 100;
    printf("%5c:", letter);
    letter++;
     printf("%5.1f", *(letters + i));
    }
    printf("------------");
}
