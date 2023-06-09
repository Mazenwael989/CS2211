#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/* Mbaioumy 250924925
This code is for approximating the mathematical constant π*/

double estimate_pi(long long n) {
        long long int i, inside = 0;
        double ratio;

        for (i = 1; i <= n; i++) {
                double x = (double)rand() / (double)RAND_MAX;
                double y = (double)rand() / (double)RAND_MAX;

        if ( ( (x*x) + (y*y) ) <= 1)
                inside++;
        }
        //calculating the ratio
        ratio = ((double)inside / (double)n);
        return 4 * ratio;
}

int main() {
        srand(time(0));
        long long int N;
        printf("Enter N Value");
        scanf("%lld", &N);
        int i;
        double pivalue[10], total=0;

        printf("Estimated pi val");
        for (i=0; i < 10; i++) {
                pivalue[i] = estimate_pi(N);
                printf("%d\t\t\t%.10f\n", (i+1), pivalue[i]);
                total = total + pivalue[i];
        }
	 }

        //finding the mean
        double mean = total/10;
        double sd = 0;
        for (i=0; i < 10; i++) {
                sd = sd + pow((pivalue[i] - mean),2);
        }

        //finding the standard deviation
        sd = sd /10;
        double std = sqrt(sd);
        printf("Estimated mean = %.10f\n", mean);
        printf("Standard Deviation = %.10f\n", std);
}

