#include <stdio.h>

//https://www.youtube.com/watch?v=YhNrGmgZ9tw
//https://pl.wikipedia.org/wiki/Metoda_LU

double L[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
};

double U[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
};

double D[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
};

void printData(double data[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%lf ", data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double data[4][4] = {
            {1.0, 1.0, 1.0, 1.0},
            {1.0, 1.0, 1.0, 1.0},
            {1.0, 1.0, 1.0, 1.0},
            {1.0, 1.0, 1.0, 1.0}
    };
    printData(data);

    printf("Test");

    return 0;
}
