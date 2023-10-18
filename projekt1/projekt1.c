#include <stdio.h>
#include <math.h>

double countValue(double x, int n) {
    return (pow(x - 1, n) / (n * pow(x + 1, n)));
}

int main() {
    double a, b, epsilon;
    int p, M;

    printf("Podaj poczatek i koniec przedzialu [a, b] gdzie x > 0\n");
    scanf("%le%le", &a, &b);

    printf("podaj wartosc epsilon jaka program uzyje\n");
    scanf("%le", &epsilon);

    printf("Podaj liczbe M\n");
    scanf("%d", &M);

    printf("podaj ilosc podprzedzialow\n");
    scanf("%d", &p);

    double xArr[p - 1];
    double diff = (b - a) / p;
    xArr[0] = a;
    for (int i = 1; i < p; ++i) {
        if (i > 0)
            xArr[i] = xArr[i - 1] + diff;
        printf("%lf\n", xArr[i]);
    }

    for (int i = 0; i < p; ++i) {
        double x = xArr[i], lastValue, value = 0;
        int n = 1, counter = 0;

        printf("obliczanie %f:\n", x);
        do {
            lastValue = value;
            value = value + countValue(x, n);
            printf("%lf %lf\n", lastValue, value);
            n = n + 2;
            counter++;
        } while ((2 * value - 2 * lastValue >= epsilon) && counter < M);

        printf("wynik:\n");
        printf("%lf\n", 2 * value);
        printf("------------------\n");
    }

    return 0;
}
