#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double verify1 = 0;
double verify2 = 0;

// derivada f(x)
double fpn_1(double Xn)
{
    return 2 * cos(Xn) + 1;
}

// f(x)
double fp(double Xn)
{
    return 2 * sin(Xn) + Xn - 2.8;
}

int verification(double interval1, double interval2)
{

    verify1 = fp(interval1);
    verify2 = fp(interval2);

    if ((verify1 > 0 && verify2 < 0) || (verify1 < 0 && verify2 > 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int option = 0;

    do
    {
        system("clear");

        int i = 0;
        double interval1, interval2, err, Xn, delta, fxn, auXn;

        printf("Interval[a, b]:\n");
        scanf("%lf%lf", &interval1, &interval2);

        printf("Error:\n");
        scanf("%lf", &err);

        system("clear");

        if (verification(interval1, interval2) == 0)
        {
            system("clear");
            do
            {

                if (i == 0)
                {
                    Xn = (interval1 + interval2) / 2;
                    delta = 1; // delta = 1 ,para o delta ser maior que o erro na primeira chamada

                    if (fpn_1(Xn) == 0)
                    {
                        printf("Root not found!\n");
                        system("pause");
                        exit(1);
                    }
                }
                else
                {
                    if (fpn_1(auXn) == 0)
                    {
                        printf("Root not found!\n");
                        system("pause");
                        exit(1);
                    }

                    Xn = auXn - (fp(auXn) / fpn_1(auXn));
                    delta = (Xn - auXn);

                    delta < 0 ? delta = delta * -1 : delta;
                }

                auXn = Xn;
                fxn = fp(Xn);

                fxn < 0 ? fxn = fxn * -1 : fxn;

                if (i == 0)
                {
                    printf("I: %i\n\t Xn: %.9lf\n\t|Xn - Xn-1|: -----\n\t|F(Xn)|: %.9lf\n", i, Xn, fxn);
                }
                else
                {

                    printf("I: %i\n\t Xn: %.20lf\n\t|Xn - Xn-1|: %.20lf\n\t|F(Xn)|: %.20lf\n", i, Xn, delta, fxn);
                }

                if (delta < err)
                {
                    printf("\nRoot found! interaction: %i, value: %.15lf\n", i, Xn);
                }

                i++;
            } while (delta > err);
        }
        else
        {
            printf("Root dont exist! --> [%.2lf,%.2lf]\n", interval1, interval2);
            printf("dont change (-|+):\nfp(%.2lf): %lf\nfp(%.2lf): %lf\n", interval1, verify1, interval2, verify2);
        }

        printf("Continue?\n");
        printf("1 - YES\n0 - NO\n");
        scanf("%d", &option);

    } while (option == 1);

    return 0;
}