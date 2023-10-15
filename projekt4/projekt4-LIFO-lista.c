#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char name[50];
    char surname[50];
    int year;
} Entry;

typedef struct Node {
    Entry entry;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Queue;

void printNode(char name[], char surname[], int year) {
    printf("imie: %s, nazwisko: %s, rok urodzenia: %i\n", name, surname, year);
}

void insert(Queue *q, Entry entry) {
    if (!q->head) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        q->head = newNode;
        q->head->entry = entry;
        q->head->next = NULL;
    } else {
        Node *temp = q->head;

        while (temp->next) {
            temp = temp->next;
        }

        Node *newNode = (Node *) malloc(sizeof(Node));
        temp->next = newNode;
        temp->next->entry = entry;
        temp->next->next = NULL;
    }
}

int delete(Queue *q) {
    if (!q->head) {
        return 0;
    } else {
        Node *temp = q->head;

        if(temp->next) {
            while (temp->next->next) {
                temp = temp->next;
            }

            free(temp->next);
            temp->next = NULL;
        } else {
            free(q->head);
            q->head = NULL;
        }
        return 1;
    }
}

void display(Queue *q) {
    if (q->head) {
        Node *temp = q->head;
        while (temp) {
            printNode(temp->entry.name, temp->entry.surname, temp->entry.year);
            temp = temp->next;
        }
    }
}

void clear(Queue *q) {
    int status;
    do {
        status = delete(q);
    } while (status == 1);
}

void addEntry(Queue *q) {
    printf("Podaj imie, nazwisko i rok urodzenia studenta\n");

    Entry entry;
    int ret = scanf("%s%s%i", entry.name, entry.surname, &entry.year);
    if (ret != 3) printf("Blad wczytywania\n");

    insert(q, entry);
}

void getNumberOfEntries(Queue *q) {
    int counter = 0;
    if (q->head) {
        Node *temp = q->head;
        while (temp) {
            counter++;
            temp = temp->next;
        }
    }
    printf("Liczba elementow w strukturze: %i\n", counter);
}

void findEntry(Queue *q) {
    if (!q->head) {
        printf("Struktura jest pusta\n");
        return;
    }

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

        Node *temp = q->head;
        while (temp) {
            if (strcmp(temp->entry.name, value) == 0) {
                printNode(temp->entry.name, temp->entry.surname, temp->entry.year);
                return;
            }
            temp = temp->next;
        }

        printf("Nie znaleziono\n");
        return;
    }
    if (typeOfSearch == 2) {
        printf("Podaj nazwisko\n");
        char value[50];
        int ret2 = scanf("%s", value);
        if (ret2 != 1) printf("Blad wczytywania\n");

        Node *temp = q->head;
        while (temp) {
            if (strcmp(temp->entry.surname, value) == 0) {
                printNode(temp->entry.name, temp->entry.surname, temp->entry.year);
                return;
            }
            temp = temp->next;
        }

        printf("Nie znaleziono\n");
        return;
    }
    if (typeOfSearch == 3) {
        printf("Podaj rok urodzenia\n");
        int value;
        int ret2 = scanf("%i", &value);
        if (ret2 != 1) printf("Blad wczytywania\n");

        Node *temp = q->head;
        while (temp) {
            if (temp->entry.year == value) {
                printNode(temp->entry.name, temp->entry.surname, temp->entry.year);
                return;
            }
            temp = temp->next;
        }

        printf("Nie znaleziono\n");
        return;
    }
    printf("Wybrano zla wartosc\n");
}

int main() {
    Queue entries;
    entries.head = NULL;

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
                addEntry(&entries);
                break;
            case 2:
                delete(&entries);
                break;
            case 3:
                findEntry(&entries);
                break;
            case 4:
                display(&entries);
                break;
            case 5:
                getNumberOfEntries(&entries);
                break;
            case 6:
                clear(&entries);
                break;
            case 7:
                exit(0);
            default:
                break;
        }
    } while (1);
}