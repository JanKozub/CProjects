#include <stdio.h>

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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                return 0;
            default:
                break;
        }
    } while (1);
}