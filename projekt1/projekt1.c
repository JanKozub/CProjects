#include <stdio.h>

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

int main() {
    double a, b, epsilon;
    int p;

    printf("Podaj poczatek i koniec przedzialu [a, b] gdzie x > 0\n");
    scanf("%le%le", &a, &b);

    printf("podaj wartosc epsilon jaka program uzyje\n");
    scanf("%le", &epsilon);

    printf("podaj ilosc podprzedzialow\n");
    scanf("%le", &p);

    for (int i = 0; i < p; ++i) {

    }
    return 0;
}
