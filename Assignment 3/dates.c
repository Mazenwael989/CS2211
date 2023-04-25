#include <stdio.h>
/* Mazen Baioumy 250924925 this code determines which of the entered dates comes later on the
calendar.*/
int main() {
        int t=0, c=0, z=0, m, d, y, pass=0;

        while(1) {
                // Enter the  date
                printf("Enter a date:");
                //If statement to check if input is integer
                if (scanf("%d/%d/%d", &m, &d, &y) != 3) {
                        while (getchar() != '\n')
                        printf("Need integer inputs");
                        continue;
                }
                if ( (d==0) && (m==0) && (y==0) ) {
                        if ( (t==0) && (c==0) && (z==0) ) {
                                printf("At least one date must be input!");
                                return 1;
                        }
                        else {
                                printf("Most Recent Date: %.2d/%.2d/%.2d", t, c, z);
                                break;
                        }
                }

                if ( (d<1) || (d>31) ) {
                        printf("Invalid Input");
                        pass = -1;
                }

                if ( (m<1) || (m>12) ) {
                        printf("Invalid Input");
                        pass = -1;
                }

                if ( (y<0 ) || (y>99) ) {
                        printf("Invalid Input");
                        pass = -1;
		 }

                if (pass == 0) {
                        if (y>z) {
                                t=m;
                                z=y;
                                c=d;
                        } else if ( y == z) {
                                if (m > t) {
                                        t=m;
                                        z=y;
                                        c=d;
                                }
                                else if ( ( d > c ) && (m == t) ) {
                                                t=m;
                                                z=y;
                                                c=d;
                                }
                        }
                }
        }
        return 0;
}

