#include "ciphers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
* caesar and vigen ciphers
* Has frequency analysis
* Mazen Baioumy 250924925
*/
char * caesar_encrypt(char *plaintext, int key){

    // Calculating key to used later on and uses previous keys
    key = key % 26;
    char *encryptedtext = (char *)malloc(500*sizeof(char)); //allocate heap memory to store cipher string

    //makes sure there is enough memory to store the cipher string
    if ( encryptedtext == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
	//making copy of string without modify original
    strcpy(encryptedtext, plaintext);
	//for loop makes any letter uppercase and uses caesar encryption
    for (int i = 0; encryptedtext[i] != '\0';i++){
        encryptedtext[i] = toupper((char) encryptedtext[i]);
        if(encryptedtext[i] >= 'A' && encryptedtext[i] <= 'Z'){
            int x = ((encryptedtext[i]- 65) + key) %26;
            x += 'A';
            encryptedtext[i] = (char) x;
        }

    }

    return encryptedtext;
}


char * caesar_decrypt(char *ciphertext, int key){
    //decrypting the txt
    int i;
    key = key % 26;
    char *out = (char *)malloc(500*sizeof(char)); //allocate heap memory to store cipher string

    //makes sure there is enough memory to store the cipher string
    if ( out == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    //duplicating the string to keep the original
    strcpy(out, ciphertext);

    for(i=0;out[i] != '\0';i++){
        if((out[i]>='A'&&out[i] <='Z')){
            int y = ((out[i]- 90) - key) %26;

            y += 'Z';
            out[i] = (char) y;
        }
    }
    return out;
}

char * vigen_encrypt(char *plaintext, char *key){
    //This is an index for encrypted message
    char *cipherText;
    char *key_text;
    int i,j;

    cipherText = (char *)malloc(500*sizeof(char)); //allocate heap memory to store cipher string
    key_text = (char *)malloc(500*sizeof(char)); //allocate heap memory to store cipher string

    //makes sure there is enough memory to store the cipher string
    if ( cipherText == NULL || key_text == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(cipherText, plaintext);
    strcpy(key_text, key);

    for (i = 0,j=0;cipherText[i] != '\0'; i++,j++){
        if (key_text[j] == '\0')
            j=0;

        cipherText[i] = toupper((char) cipherText[i]);
        key_text[j] = toupper((char) key_text[j]);

        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z'){
            cipherText[i] = ((cipherText[i] + key_text[j]) % 26) + 'A';
        }

    }

return cipherText;
}

char * vigen_decrypt(char *ciphertext, char *key){
    char *plainText;
    char *key_text;
    int i,j;

    plainText = (char *)malloc(500*sizeof(char)); //allocate heap memory to store cipher string
    key_text = (char *)malloc(500*sizeof(char)); //allocate heap memory to store cipher string


    if ( plainText == NULL ||  key_text == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    //making copy of string without modify original
    strcpy(plainText, ciphertext);
    strcpy(key_text, key);

    for (i = 0,j=0;plainText[i] != '\0'; i++,j++){
        if (key_text[j] == '\0')
            j=0;

        plainText[i] = toupper((char) plainText[i]);
        key_text[j] = toupper((char) key_text[j]);

        if(plainText[i] >= 'A' && plainText[i] <= 'Z'){

            plainText[i] = (((plainText[i] - key_text[j])) % 26);

            if(plainText[i] < 0)
                plainText[i] += 26;
            plainText[i] += 'A';
        }

    }

    return plainText;

}

//frequancey analysis find the frequency of each letter in cipher text
void freq_analysis(char *ciphertext, double letters[26]){
    for(int i=0 ; i<26; ++i)

        letters[i] = 0.0;

    int total = 0.0;

    for(int i=0; i<strlen(ciphertext) ; ++i){

        ciphertext[i] = tolower((char) ciphertext[i]);

        if(ciphertext[i] >='a' && ciphertext[i] <='z'){
            ++letters[ciphertext[i]-'a'];
            ++total;
        }
    }

    for(int i=0; i<26 ; ++i){

        letters[i] = letters[i]*100/total;


    }

}
int validString( const char s[] )
{
    unsigned char c;

    while ( ( c = *s ) && ( isalpha( c ) ) ) ++s;

    return *s == '\0';
}

