#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// derivada f(x)
double fp_1(double xn, int n)
{
    double e;
    e = pow(xn, n);

    return n * e;
}

// f(x)
double fp(double xn, int n, double p) // certo
{

    return pow(xn, n) - p;
}

int main()
{
    int i = 0, n;
    double xn, delta, fxn, auxn, p;

    printf("p:\n");
    scanf("%lf", &p);
    printf("n:\n");
    scanf("%d", &n);

    xn = 1;
    delta = 1;

    printf("%lf\n", 1 - (fp(1, 4, 8.21)/fp_1(1, 4)));


    return 0;
}