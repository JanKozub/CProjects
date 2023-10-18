#include <stdio.h>
#include <math.h>

/*
 Policz wartości funkcji y = f(x) we wszystkich punktach podziału na n części

przedziału [a,b]. Funkcja f dana jest w postaci rozwinięcia w szereg

potęgowy i w postaci wzoru analitycznego. Obliczanie sumy szeregu

wykonaj z dokładnością ε. Algorytm obliczania sumy szeregu zapisz w

oddzielnej funkcji. Przykładowa funkcja: y=sin(x). Uzupełnij funkcję

obliczającą sumę szeregu tak, by sumowanych było co najwyżej M

wyrazów szeregu. Oznacza to, że przerwanie sumowania może nastąpić

również wtedy, gdy nie zostanie osiągnięta ¡dana dokładność. Informacja

o tym, czy została osiągnięta dokładność czy też nie winna być znana w

funkcji main. Uzupełnij funkcję obliczającą sumę szeregu tak, by w funkcji

main znana była dodatkowo liczba sumowanych wyrazów szeregu.
 */

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
        double x = xArr[i];

        int n = 1, counter = 0;
        double lastValue;
        double value = 0;
        printf("obliczanie %f:\n", x);
        do {
            lastValue = value;
            value = value + countValue(x, n);
            n = n + 2;
            printf("%lf %lf\n", lastValue, value);
            counter++;
        } while ((2 * value - 2 * lastValue >= epsilon) && counter < M);

        printf("wynik:\n");
        printf("%lf\n", 2 * value);

        printf("------------------\n");
    }

    return 0;
}
