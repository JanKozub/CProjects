#include <stdio.h>
#include <math.h>

double input[3][3] = {
        {5, 3, 2},
        {1, 2, 0},
        {3, 0, 4}
};

double L[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
};

double U[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
};

void printData(double data[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%lf ", data[i][j]);
        }
        printf("\n");
    }
}

void printData2() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%lf ", input[i][j]);
        }

        printf("          ");

        for (int j = 0; j < 3; ++j) {
            printf("%lf ", L[i][j]);
        }

        printf("          ");

        for (int j = 0; j < 3; ++j) {
            printf("%lf ", U[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------------------------------\n");
}

int main() {
    printData2();

    double n;
    for (int i = 0; i < 3; ++i) {
        n = 0;
        for (int j = 1; j < 3; ++j) {
            n = n + (L[0][j] * U[j][i]);
        }
        n = (input[0][i] - n) / L[0][0];

        U[0][i] = n;
    }

    printData2();

    for (int i = 1; i < 3; ++i) {
        n = 0;
        for (int j = 0; j < 3; ++j) {
            if (j != 0) {
                n = n + (U[j][0] * L[i][j]);
            }
        }
        n = (input[i][0] - n) / U[0][0];

        L[i][0] = n;
    }

    printData2();

    for (int i = 1; i < 3; ++i) {
        n = 0;
        for (int j = 0; j < 3; ++j) {
            if (j != 1) {
                n = n + (L[1][j] * U[j][i]);
//                printf("%f * %f + ", L[1][j], U[j][i]);
            }
        }
        n = (input[1][i] - n) / L[1][1];
//        printf("%f", input[1][i]);
//        printf(" / %f", L[1][1]);

//        printf("== %f\n", n);
        U[1][i] = n;
    }

    printData2();

    for (int i = 2; i < 3; ++i) {
        n = 0;
        for (int j = 0; j < 3; ++j) {
            if (j != 1) {
                n = n + (U[j][1] * L[i][j]);
            }
        }
        n = (input[i][1] - n) / U[1][1];

        L[i][1] = n;
    }

    printData2();

    return 0;
}
