#include <stdio.h>

#define SIZE 4

//double input[3][3] = {
//        {5, 3, 2},
//        {1, 2, 0},
//        {3, 0, 4}
//};

double input[4][4] = {
        {5, 3, 2, 2},
        {1, 2, 0, 4},
        {3, 0, 4, 8},
        {1, 9, 3, 2}
};

//double input[SIZE][SIZE] = {
//        {8, 9, 3},
//        {6, 5, 1},
//        {7, 4, 2}
//};

double L[SIZE][SIZE];

double U[SIZE][SIZE];


void printData2() {
    for (int i = 0; i < SIZE; ++i) {
        if(i == 0) {
            printf("LU: ");
        } else {
            printf("    ");
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

void initL(){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i == j) {
                L[i][j] = 1;
            } else if(j < i) {
                L[i][j] = -1;
            } else {
                L[i][j] = 0;
            }
        }
    }
}

void initU() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            U[i][j] = j < i ? 0 : -1;
        }
    }
}

int main() {
    initL();
    initU();
    printData2();

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
        printData2();

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
        printData2();
    }

    return 0;
}
