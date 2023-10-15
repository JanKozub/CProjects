#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char surname[50];
    int year;
} Entry;

Entry entry;

#define MAX 100

Entry tab[MAX];
int s = 0, e = -1;

void printElement(int i) {
    printf("idx: %i, imie: %s, nazwisko: %s, rok urodzenia: %i\n", i, tab[i].name, tab[i].surname, tab[i].year);
}

void addElement() {
    if (e >= MAX) {
        printf("Nie ma juz miejsca\n");
    } else {
        printf("Podaj imie, nazwisko i rok urodzenia studenta\n");

        char name[50], surname[50];
        int year;
        int ret = scanf("%s%s%i", name, surname, &year);
        if (ret != 3) printf("Blad wczytywania\n");

        e++;
        strcpy(tab[e].name, name);
        strcpy(tab[e].surname, surname);
        tab[e].year = year;

        printf("Dodano wpis:\n");
        printElement(e);
    }
}

void removeElement() {
    if (s == e) return;

    tab[s] = entry;
    s++;
}

void FindElementByField() {
    printf("Wybierz pole po ktorym chcesz szukac\n");
    printf("1. Imie\n");
    printf("2. Nazwisko\n");
    printf("3. Rok urodzenia\n");

    int typeOfSearch;
    int ret = scanf("%i", &typeOfSearch);
    if (ret != 1) printf("Blad wczytywania\n");

    if (typeOfSearch == 1) {
        printf("Podaj imie\n");
        char value[50];
        int ret2 = scanf("%s", value);
        if (ret2 != 1) printf("Blad wczytywania\n");

        for (int i = s; i <= e; ++i) {
            if (strcmp(tab[i].name, value) == 0) {
                printElement(i);
                return;
            }
        }

        printf("Nie znaleziono\n");
        return;
    }
    if (typeOfSearch == 2) {
        printf("Podaj nazwisko\n");
        char value[50];
        int ret2 = scanf("%s", value);
        if (ret2 != 1) printf("Blad wczytywania\n");

        for (int i = s; i <= e; ++i) {
            if (strcmp(tab[i].surname, value) == 0) {
                printElement(i);
                return;
            }
        }
        return;
    }
    if (typeOfSearch == 3) {
        printf("Podaj rok urodzenia\n");
        int value;
        int ret2 = scanf("%i", &value);
        if (ret2 != 1) printf("Blad wczytywania\n");

        for (int i = s; i <= e; ++i) {
            if (tab[i].year == value) {
                printElement(i);
                return;
            }
        }
        return;
    }
    printf("Wybrano zla wartosc\n");
}

void getAllElements() {
    for (int i = s; i <= e; ++i) {
        printElement(i);
    }
}

void getNumberOfElements() {
    printf("ilosc elementow: %i", e - s);
}

void deleteAllElements() {
    for (int i = s; i <= e; ++i) {
        tab[i] = entry;
        s++;
    }
}

int main() {
    do {
        printf("1. Dodaj element\n");
        printf("2. Usun element\n");
        printf("3. Wyszukaj element po polu\n");
        printf("4. Wypisz wszystkie elementy\n");
        printf("5. Sprawdz liczbe elementow w strukturze\n");
        printf("6. Usuniecie wszystkich elementow ze struktury\n");
        printf("7. Zakonczenie programu\n");

        int res = 0;
        int ret = scanf("%i", &res);
        if (ret != 1) printf("Blad wczytywania\n");

        switch (res) {
            case 1:
                addElement();
                break;
            case 2:
                removeElement();
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
                exit(0);
            default:
                break;
        }
    } while (1);
}