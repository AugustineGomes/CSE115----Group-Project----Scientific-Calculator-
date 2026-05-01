#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printLine() {
    printf("  ================================================\n");
}

/* UTILITY: Print the main banner / header */
void printBanner() {
    clearScreen();
    printLine();
    printf("  ||    SCIENTIFIC CALCULATOR  ||  CSE115       ||\n");
    printLine();
    printf("\n");
}

/*SECTION 5 — POWER & ROOT OPERATIONS*/

void menuPowerRoot() {
    int choice;
    double a, b, result;

    printBanner();
    printf("  [ POWER & ROOT OPERATIONS ]\n\n");
    printf("   1. Power       x ^ y\n");
    printf("   2. Square Root sqrt(x)\n");
    printf("   3. Cube Root   cbrt(x)\n");
    printf("   4. Nth Root    x ^ (1/n)\n");
    printf("   0. Back to Main Menu\n\n");
    printLine();
    printf("  Enter choice: ");
    scanf("%d", &choice);

    if (choice == 0) return;

    switch (choice) {
        case 1:
            printf("  Enter base x and exponent y: ");
            scanf("%lf %lf", &a, &b);
            if (a == 0 && b < 0) {
                printf("\n Error: Undefined.\n");
            } else {
                result = pow(a, b);
                printf("\n  Result = %.6lf\n", a, b, result);
            }
            break;

        case 2:
            printf("  Enter x (x >= 0): ");
            scanf("%lf", &a);
            if (a < 0) {
                printf("\n Error: Square root of a negative number is not real.\n");
            } else {
                result = sqrt(a);
                printf("\n  Result = %.6lf\n", result);
            }
            break;

        case 3:
            printf("  Enter x: ");
            scanf("%lf", &a);
            result = cbrt(a);
            printf("\n  Result = %.6lf\n", result);
            break;

        case 4:
            printf("  Enter x: ");
            scanf("%lf", &a);
            printf("  Enter square root - n - value: ");
            scanf("%lf", &b);
            if (b == 0) {
                printf("\n Error: Root degree cannot be zero.\n");
            } else if (a < 0 && fmod(b, 2.0) == 0) {
                printf("\n Error: Even root of a negative number is not real.\n");
            } else {
                result = pow(a, 1.0 / b);
                printf("\n  Result = %.6lf\n", result);
            }
            break;

        default:
            printf("\n  [!] Invalid choice.\n");
    }
}

/* SECTION 6 — MATRIX OPERATIONS */

#define MAX_SIZE 10

/* Read a matrix from user input */
void readMatrix(double mat[MAX_SIZE][MAX_SIZE], int rows, int cols, char name) {
    printf("\n  Enter elements of Matrix %c (row by row):\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("    %c[%d][%d] = ", name, i + 1, j + 1);
            scanf("%lf", &mat[i][j]);
        }
    }
}

/* Print a matrix in a neat grid format */
void printMatrix(double mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("  | ");
        for (int j = 0; j < cols; j++) {
            printf("%9.4lf ", mat[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

/* HELPER: Validate matrix dimensions (1..MAX_SIZE) */
int validDim(int d) {
    return (d >= 1 && d <= MAX_SIZE);
}

/* OPERATION: Matrix Addition  ( A + B ) */
void matrixAddition() {
    double A[MAX_SIZE][MAX_SIZE];
    double B[MAX_SIZE][MAX_SIZE];
    double C[MAX_SIZE][MAX_SIZE];
    int rA, cA, rB, cB;

    printBanner();
    printf("  [ MATRIX ADDITION  —  A + B ]\n\n");

    printf("  Enter dimensions of Matrix A:\n");
    printf("    Rows    : ");  scanf("%d", &rA);
    printf("    Columns : ");  scanf("%d", &cA);

    if (!validDim(rA) || !validDim(cA)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf("\n  Enter dimensions of Matrix B:\n");
    printf("    Rows    : ");  scanf("%d", &rB);
    printf("    Columns : ");  scanf("%d", &cB);

    if (!validDim(rB) || !validDim(cB)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    if (rA != rB || cA != cB) {
        printf("\n  [!] Error: Matrix addition requires identical dimensions.\n");
        printf("      Matrix A is %dx%d but Matrix B is %dx%d.\n", rA, cA, rB, cB);
        return;
    }

    readMatrix(A, rA, cA, 'A');
    readMatrix(B, rB, cB, 'B');

    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cA; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("\n  Matrix A:");
    printMatrix(A, rA, cA);
    printf("  Matrix B:");
    printMatrix(B, rB, cB);
    printLine();
    printf("  Result  —  A + B  ( %dx%d ):", rA, cA);
    printMatrix(C, rA, cA);
}

/* OPERATION: Matrix Multiplication  ( A x B ) */
void matrixMultiplication() {
    double A[MAX_SIZE][MAX_SIZE];
    double B[MAX_SIZE][MAX_SIZE];
    double C[MAX_SIZE][MAX_SIZE];
    int rA, cA, rB, cB;

    printBanner();
    printf("  [ MATRIX MULTIPLICATION  —  A x B ]\n");
    printf("  Note: Columns of A must equal Rows of B.\n\n");

    printf("  Enter dimensions of Matrix A:\n");
    printf("    Rows    : ");  scanf("%d", &rA);
    printf("    Columns : ");  scanf("%d", &cA);

    if (!validDim(rA) || !validDim(cA)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    printf("\n  Enter dimensions of Matrix B:\n");
    printf("    Rows    : ");  scanf("%d", &rB);
    printf("    Columns : ");  scanf("%d", &cB);

    if (!validDim(rB) || !validDim(cB)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    if (cA != rB) {
        printf("\n  [!] Error: Incompatible dimensions for multiplication.\n");
        printf("      Columns of A (%d) must equal Rows of B (%d).\n", cA, rB);
        return;
    }

    readMatrix(A, rA, cA, 'A');
    readMatrix(B, rB, cB, 'B');

    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\n  Matrix A  ( %dx%d ):", rA, cA);
    printMatrix(A, rA, cA);
    printf("  Matrix B  ( %dx%d ):", rB, cB);
    printMatrix(B, rB, cB);
    printLine();
    printf("  Result  —  A x B  ( %dx%d ):", rA, cB);
    printMatrix(C, rA, cB);
}

/* MENU: Matrix Operations */
void menuMatrix() {
    int choice;

    printBanner();
    printf("  [ MATRIX OPERATIONS ]\n\n");
    printf("   1. Matrix Addition         ( A + B )\n");
    printf("   2. Matrix Multiplication   ( A x B )\n");
    printf("   0. Back to Main Menu\n\n");
    printLine();
    printf("  Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: matrixAddition();
            break;
        case 2: matrixMultiplication();
            break;
        case 0:
             break;
        default:
            printf("\n  [!] Invalid choice.\n");
    }
}


void printMainMenu() {
    printBanner();
    printf("  Select a category:\n\n");
    printf("   1.  Power & Root    ( x^y, sqrt, cbrt, nth-root )\n");
    printf("   2.  Matrix          ( A+B, AxB )\n");
    printf("   0.  Exit\n\n");
    printLine();
    printf("  Enter choice: ");
}

int main() {
    int choice;

    do {
        printMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                menuPowerRoot();
                break;
            case 2:
                menuMatrix();
                break;
            case 0:
                printf("\n  Goodbye! Thank you for using the calculator.\n\n");
                break;
            default:
                printf("\n  [!] Invalid option. Please try again.\n");
        }

        if (choice != 0) {
            printf("\n  Press ENTER to return to the main menu...");
            getchar();
            getchar();
        }

    } while (choice != 0);

    return 0;
}
