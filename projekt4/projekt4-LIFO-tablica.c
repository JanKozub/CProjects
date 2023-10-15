#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char surname[50];
    int year;
} Entry;

Entry entry;

#define MAX 100

Entry tab[MAX];
int currentIdx = -1;

void printElement(int i) {
    printf("idx: %i, imie: %s, nazwisko: %s, rok urodzenia: %i\n", i, tab[i].name, tab[i].surname, tab[i].year);
}

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
        printElement(currentIdx);
    }
}

void removeElement() {
    if (currentIdx >= 0) {
        tab[currentIdx] = entry;
        currentIdx--;
    }
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

        for (int i = 0; i <= currentIdx; ++i) {
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

        for (int i = 0; i <= currentIdx; ++i) {
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

        for (int i = 0; i <= currentIdx; ++i) {
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
    for (int i = 0; i <= currentIdx; ++i) {
        printElement(i);
    }
}

void getNumberOfElements() {
    printf("ilosc elementow: %i", currentIdx);
}

void deleteAllElements() {
    while (currentIdx >= 0) {
        tab[currentIdx] = entry;
        currentIdx--;
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