//Mazen Baioumy 250924925
//Makefile to compile and link program
C = gcc
RM = -f
CIPHER = ciphers
CFLAGS = -std=c99

$(CIPHER): ciphers.o cipher_main.o
	$(CC) $(CFLAGS) -o $(CIPHER) ciphers.o cipher_main.o

cipher_main.o: ciphers.h cipher_main.c
	$(CC) $(CFLAGS) -c cipher_main.c

ciphers.o: ciphers.h ciphers.c
	$(CC) $(CFLAGS) -c ciphers.c

clean:
	rm $(RM) $(CIPHER) *.o core