#include <stdio.h>

#define SIZE 3

double input[SIZE][SIZE] = {
        {6, -2, 0},
        {9, -1, 1},
        {3, 7, 5}
};

double L[SIZE][SIZE];
double D[SIZE][SIZE];
double U[SIZE][SIZE];
double U1[SIZE][SIZE];

void printData() {
    for (int i = 0; i < SIZE; ++i) {
        if(i == 0) {
            printf("LDU: ");
        } else {
            printf("     ");
        }

        for (int j = 0; j < SIZE; ++j) {
            printf("%.2f ", input[i][j]);
        }

        if(i == 0) {
            printf(" L: ");
        } else {
            printf("    ");
        }

        for (int j = 0; j < SIZE; ++j) {
            printf("%.2f ", L[i][j]);
        }

        if(i == 0) {
            printf(" D: ");
        } else {
            printf("    ");
        }

        for (int j = 0; j < SIZE; ++j) {
            printf("%.2f ", D[i][j]);
        }

        if(i == 0) {
            printf(" U: ");
        } else {
            printf("    ");
        }

        for (int j = 0; j < SIZE; ++j) {
            printf("%.2f ", U[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------------------------------\n");
}

void initArrays(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i == j) {
                L[i][j] = 1;
                D[i][j] = -1;
                U1[i][j] = 1;
            } else if(j < i) {
                L[i][j] = -1;
                D[i][j] = 0;
                U[i][j] = 0;
                U1[i][j] = 0;
            } else {
                L[i][j] = 0;
                D[i][j] = 0;
                U[i][j] = -1;
                U1[i][j] = -1;
            }
        }
    }
}

int main() {
    initArrays();
    printData();

    double n;
    for (int k = 0; k < SIZE; ++k) {
        for (int i = k; i < SIZE; ++i) {
            n = 0;
            for (int j = 0; j < SIZE; ++j) {
                if (j != k) {
                    n = n + (L[k][j] * U[j][i]);
                }
            }
            n = (input[k][i] - n) / L[k][k];

            U[k][i] = n;
        }
        printData();

        for (int i = k + 1; i < SIZE; ++i) {
            n = 0;
            for (int j = 0; j < SIZE; ++j) {
                if (j != k) {
                    n = n + (U[j][k] * L[i][j]);
                }
            }
            n = (input[i][k] - n) / U[k][k];

            L[i][k] = n;
        }
        printData();
    }

    double x = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(j == i) {
                x = U[i][j] / U1[i][j];
                D[i][j] = x;
            } else if(j > i) {
                U1[i][j] = U[i][j] / x;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            U[i][j] = U1[i][j];
        }
    }

    printData();

    return 0;
}
