#include <stdio.h>
#include <string.h>

//https://www.youtube.com/watch?v=YhNrGmgZ9tw
//https://pl.wikipedia.org/wiki/Metoda_LU

typedef struct {
    char name[50];
    char surname[50];
    int year;
} Entry;

#define MAX 100

Entry tab[MAX];
int currentIdx = -1;

void addElement() {
    if (currentIdx > MAX) {
        printf("Stos nie ma już miejsca\n");
    } else {
        printf("Podaj imie, nazwisko i rok urodzenia studenta\n");

        char name[50], surname[50];
        int year;
        int ret = scanf("%s%s%i", name, surname, &year);
        if (ret != 3) printf("Blad wczytywania\n");

        currentIdx++;
        strcpy(tab[currentIdx].name, name);
        strcpy(tab[currentIdx].surname, surname);
        tab[currentIdx].year = year;

        printf("Dodano wpis:\n");
        printf("idx: %i, imie: %s, nazwisko: %s, rok urodzenia: %i\n", currentIdx, tab[currentIdx].name,
               tab[currentIdx].surname, tab[currentIdx].year);
    }
}

void getElement() {
    printf("Podaj index\n");

    int idx;
    int ret = scanf("%i", &idx);
    if (ret != 1) {
        printf("Blad wczytywania\n");
    }

    if (idx >= 0 && idx <= currentIdx) {
        printf("idx: %i, imie: %s, nazwisko: %s, rok urodzenia: %i\n", idx, tab[idx].name, tab[idx].surname,
               tab[idx].year);
    } else {
        printf("Bledny index\n");
    }

}

void FindElementByField() {
    printf("Wybierz pole po ktorym chcesz szukac\n");
    printf("1. Imie\n");
    printf("2. Nazwisko\n");
    printf("3. Rok urodzenia\n");

    int res;
    int ret = scanf("%i", &res);
    if (ret != 1) printf("Blad wczytywania\n");

    switch (res) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Wybrano zla wartosc\n");
    }

}

void getAllElements() {

}

void getNumberOfElements() {

}

void deleteAllElements() {

}


int main() {
    do {
        printf("1. Dodaj element\n");
        printf("2. Pobierz element\n");
        printf("3. Wyszukaj element po polu\n");
//        printf("4. Pobierz wszystkie dokumenty\n");
//        printf("5. Sprawdz liczbe elementow w strukturze\n");
//        printf("6. Usuniecie wszystkich elementow ze struktury\n");
        printf("7. Zakonczenie programu\n");

        int res = 0;
        int ret = scanf("%i", &res);
        if (ret != 1) printf("Blad wczytywania\n");

        switch (res) {
            case 1:
                addElement();
                break;
            case 2:
                getElement();
                break;
            case 3:
                FindElementByField();
                break;
            case 4:
                getAllElements();
                break;
            case 5:
                getNumberOfElements();
                break;
            case 6:
                deleteAllElements();
                break;
            case 7:
                return 0;
            default:
                break;
        }
    } while (1 == 1);
}