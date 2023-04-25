/*
 * Mazen Baioumy 250924925
 */

//Prototypes for Caesar cipher functions
char *caesar_encrypt(char *plaintext, int key);
char *caesar_decrypt(char *cyphertext, int key);

//Prototypes for Vigenere cipher functions
char *vigen_encrypt(char *plaintext, char *key);
char *vigen_decrypt(char *cyphertext, char *key);

//Prototype for Frequency Analysis function
void freq_analysis(char *ciphertext, double letters[26]);
