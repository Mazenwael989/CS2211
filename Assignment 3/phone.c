//Mazen Baioumy 250924925
#include <stdio.h>
int main() {
        printf("Enter phone number:");
        int i, original, area, central, line;
        char option;
        i = scanf("%3d%3d%4d", &area, &central, &line);
        // This if statement is for error checking if values is less than 3
        if ((i != 3)) {
                printf("Invalid Number");
                return 1;
        }

        // Error Checking again incase of invalid number for area, central or line
        if ( (area<100) || (central < 100) || (line<1000) ) {
                printf("Invalid Number");
                return 1;
        }
        // Provide use with options to pick
        printf("Enter an option:");
        scanf("\n%c", &option);
        switch(option){
                case 'a':
                case 'A': printf("%d-%d", central, line);
                          break;
                case 'b':
                case 'B': printf("(%d) %d-%d", area, central, line);
                          break;
                case 'c':
                case 'C': printf("+1-%d-%d-%d", area, central, line);
                          break;
                case 'd':
                case 'D': printf("%6.4d%6.4d%6.4d", area, central, line);
                          break;
                default: printf("Invalid Option");
        }
        return 0;
}
