#include "ciphers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


//------------COMMENTS---------------
// c99 to compile
 * Main file for using ciphers
 * Mazen Baioumy 250924925
 */
int main(){

        char plaintext[100];
        int selection;
        // ask user for plaintext
        printf("Input plaintext: ");
        fgets (plaintext, 100, stdin);

        // prompt user for encryption message they like to use
        printf("Available Ciphers\n");
        printf(" 1) Ceasar\n");
        printf(" 2) Vignere\n");

        
	scanf("%d",&selection);

        // statement to read cipher

        
	switch(selection) {
            case 1:{
                //Going to take in the key for ceasar encryption
                int num_key;
                printf("Input Key: ");
                //get the key and check that scanf is successful
		int check = scanf("%d",&num_key);
                if (check != 1){
                    printf("Input key can only be a number!\n");
                    exit(EXIT_FAILURE);
                }
            	
                printf("\n");
                // printing the plain text
                printf("Text before applying cipher:\n%s", plaintext);

                // encrypt plain text and show it
                char *encryptedtext = caesar_encrypt(plaintext,num_key);
                printf("Test after applying cipher: \n");
                printf("%s",encryptedtext);
                printf("\n");

                //decrypt ciphered messaged and show it
                printf("Text after decryption: \n");
                char *Otext = caesar_decrypt(encryptedtext,num_key);
                printf("%s",Otext);
		
                break;
            }
            case 2:{
                // vigenere vector
                char key;
                printf("Input Key: ");
                scanf("%s",&key);

                if (!checkString(&key)){
                    printf("Input key can only be letters!\n");
                    exit(EXIT_FAILURE);
                }

                double letters[26];
                printf("\n");
                //print plain text before input
                printf("Text before encryption:\n%s", plaintext);
                printf("\n");
                //encrypt plain text and show it
                char *encryptedtext = vigen_encrypt(plaintext,&key);
                printf("Text after encryption: \n");
                printf("%s",encryptedtext);
                printf("\n");
                //decrypt ciphered messaged and show it
                printf("Text after decryption: \n");
                char * Otext = vigen_decrypt(encryptedtext,&key);
                printf("%s",Otext);
               
                break;
            }
            default: printf("Bad input!\n");
		//this is a check for if a person uses invalid input
        }

	//this is to run the frequency analysis to determine plaint text
		double letters[26];
                freq_analysis(plaintext,letters);
                for(int i=0; i<26 ; ++i){

                    if ((i % 4) == 0){
                        printf("\n");
                    }
                    printf("%c --> %lf %%\t",i+'a', letters[i]);
                }

                printf("\n");
                //Destroying the encrypted and plain text
                free(Otext);
                free(encryptedtext);

    return 0;

}
