#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// derivada f(x)
double fp_1(double xn, int n)
{
    double e;
    e = pow(xn, n - 1);
    return n * e;
}

// f(x)
double fp(double xn, int n, double p)
{
    return pow(xn, n) - p;
}

int main()
{
    int option = 0;

    do
    {
        system("clear");

        int i = 0, n;
        double xn, delta, fxn, auxn, p;

        printf("p:\n");
        scanf("%lf", &p);
        printf("n:\n");
        scanf("%d", &n);

        system("clear");

        xn = 1;
        delta = 1;

        do
        {
            if (i == 0)
            {
                printf("interaction: %i\nxn: %.9lf\ndelta: %.20lf\n", i, xn, delta - 1);
            }
            else
            {
                xn = auxn - (fp(auxn, n, p) / fp_1(auxn, n));
                delta = xn - auxn;
                delta < 0 ? delta = delta * -1 : delta;

                printf("interaction: %i\nxn: %.9lf\ndelta: %.20lf\n", i, xn, delta);
            }

            auxn = xn;

            printf("\n");

            if (delta == 0)
            {
                printf("Root found! interaction: %i\nValue: %lf\n", i, xn);
            }

            i++;
        } while (delta > 0);

        printf("\n");

        printf("Continue?\n");
        printf("1 - YES\n0 - NO\n");
        scanf("%d", &option);
    } while (option == 1);

    return 0;
}