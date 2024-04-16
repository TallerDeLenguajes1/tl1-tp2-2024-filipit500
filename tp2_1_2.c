#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
int i;
double vt[N];
double *Puntero = vt;
    for(i = 0;i<N; i++)
    {
        *(Puntero + i)=1+rand()%100;
        printf("%lf\n", *(Puntero + i));
    }
return 0;
}
