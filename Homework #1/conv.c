#include <stdio.h>
#include <stdlib.h>

float h[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
float x[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
float y[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#define ML 10
#define LL 10

#define max(x,y) ((x > y)? x:y)
#define min(x,y) ((x < y)? x:y)

void convolve(int M, int L, float *h, float *x, float *y)
{
    int n,m;
    for (n=0; n<L+M; n++)
        for (y[n]=0, m=max(0,n-L+1); m<=min(n,M-1); m++)
            y[n] += h[m] * x[n-m];
}

void main(int argc, char**argv)
{
    int i;
    convolve(ML, LL, h, x, y);
    for (i=0; i<LL+ML; i++)
        printf("y[%d] = %f\n", i, (double) y[i]);
}
