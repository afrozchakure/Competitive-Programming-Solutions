#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);
    int len = ((2*n)-1);
    int m;
    for (int row = 0; row< len; row++) {
       for (int col = 0; col< len; col++) {
           m = min(row, col);
           m = min(m, len-row-1);
           m = min(len-col-1, m);
           printf("%d ", n-m);
       }
       printf("\n");
    }
    return 0;
}
