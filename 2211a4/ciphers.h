//nicholas gardi - 250868721 - 4/7/17
//header file for assignment 4

#include <stdio.h>
char * caesar_encrypt(char *plaintext, int key);

char * caesar_decrypt(char *ciphertext, int key);

char * vigen_encrypt(char *plaintext, char *key);

char * vigen_decrypt(char *ciphertext, char *key);

void freq_analysis(char *ciphertext, double letters[26]);

#endif