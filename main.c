/*
 * ============================================================
 *         SCIENTIFIC CALCULATOR - CSE115 Project
 *         Language  : C
 *         Features  : Arithmetic, Trigonometry, Logarithm,
 *                     Power/Root, Factorial, Permutation,
 *                     Matrix (Addition & Multiplication)
 * ============================================================
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*  UTILITY: Clear the screen (cross-platform) */

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* UTILITY: Print a decorative separator line */

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

/*SECTION 1 — BASIC ARITHMETIC OPERATIONS */

void menuArithmetic() {
    int choice;
    double a, b, result;

    printBanner();
    printf("  [ ARITHMETIC OPERATIONS ]\n\n");
    printf("   1. Addition        ( a + b )\n");
    printf("   2. Subtraction     ( a - b )\n");
    printf("   3. Multiplication  ( a * b )\n");
    printf("   4. Division        ( a / b )\n");
    printf("   5. Modulus         ( a %% b )  [integers only]\n");
    printf("   0. Back to Main Menu\n\n");
    printLine();
    printf("  Enter choice: ");
    scanf("%d", &choice);

    if (choice == 0) return;
    if (choice < 1 || choice > 5) {
        printf("\n  [!] Invalid choice.\n");
        return;
    }

    /* Modulus works with integers only */
    if (choice == 5) {
        int ia, ib;
        printf("  Enter two integers  (a b): ");
        scanf("%d %d", &ia, &ib);
        if (ib == 0) {
            printf("\n  [!] Error: Modulus by zero is undefined.\n");
        } else {
            printf("\n  Result : %d %% %d = %d\n", ia, ib, ia % ib);
        }
        return;
    }

    printf("  Enter two numbers (a b): ");
    scanf("%lf %lf", &a, &b);

    switch (choice) {
        case 1:
            result = a + b;
            printf("\n  Result : %.4lf + %.4lf = %.4lf\n", a, b, result);
            break;
        case 2:
            result = a - b;
            printf("\n  Result : %.4lf - %.4lf = %.4lf\n", a, b, result);
            break;
        case 3:
            result = a * b;
            printf("\n  Result : %.4lf * %.4lf = %.4lf\n", a, b, result);
            break;
        case 4:
            if (b == 0) {
                printf("\n  [!] Error: Division by zero is undefined.\n");
            } else {
                result = a / b;
                printf("\n  Result : %.4lf / %.4lf = %.4lf\n", a, b, result);
            }
            break;
    }
}

/*SECTION 2 — TRIGONOMETRIC OPERATIONS*/

#define PI 3.14159265358979323846
#define DEG_TO_RAD(x)  ((x) * PI / 180.0)
#define RAD_TO_DEG(x)  ((x) * 180.0 / PI)

void menuTrigonometry() {
    int choice;
    double angle, result;

    printBanner();
    printf("  [ TRIGONOMETRIC OPERATIONS ]\n");
    printf("  (Angles are entered in DEGREES)\n\n");
    printf("   1. sin(angle)\n");
    printf("   2. cos(angle)\n");
    printf("   3. tan(angle)\n");
    printf("   4. arcsin(value)  -> angle in degrees\n");
    printf("   5. arccos(value)  -> angle in degrees\n");
    printf("   6. arctan(value)  -> angle in degrees\n");
    printf("   0. Back to Main Menu\n\n");
    printLine();
    printf("  Enter choice: ");
    scanf("%d", &choice);

    if (choice == 0) return;

    switch (choice) {
        case 1:
            printf("  Enter angle (degrees): ");
            scanf("%lf", &angle);
            result = sin(DEG_TO_RAD(angle));
            printf("\n  Result : sin(%.2lf°) = %.6lf\n", angle, result);
            break;

        case 2:
            printf("  Enter angle (degrees): ");
            scanf("%lf", &angle);
            result = cos(DEG_TO_RAD(angle));
            printf("\n  Result : cos(%.2lf°) = %.6lf\n", angle, result);
            break;

        case 3:
            printf("  Enter angle (degrees): ");
            scanf("%lf", &angle);
            /* tan is undefined at 90, 270, ... */
            if (fmod(angle, 180.0) == 90.0) {
                printf("\n  [!] Error: tan(%.2lf°) is undefined.\n", angle);
            } else {
                result = tan(DEG_TO_RAD(angle));
                printf("\n  Result : tan(%.2lf°) = %.6lf\n", angle, result);
            }
            break;

        case 4:
            printf("  Enter value (must be between -1 and 1): ");
            scanf("%lf", &angle);
            if (angle < -1.0 || angle > 1.0) {
                printf("\n  [!] Error: arcsin domain is [-1, 1].\n");
            } else {
                result = RAD_TO_DEG(asin(angle));
                printf("\n  Result : arcsin(%.6lf) = %.4lf°\n", angle, result);
            }
            break;

        case 5:
            printf("  Enter value (must be between -1 and 1): ");
            scanf("%lf", &angle);
            if (angle < -1.0 || angle > 1.0) {
                printf("\n  [!] Error: arccos domain is [-1, 1].\n");
            } else {
                result = RAD_TO_DEG(acos(angle));
                printf("\n  Result : arccos(%.6lf) = %.4lf°\n", angle, result);
            }
            break;

        case 6:
            printf("  Enter value: ");
            scanf("%lf", &angle);
            result = RAD_TO_DEG(atan(angle));
            printf("\n  Result : arctan(%.6lf) = %.4lf°\n", angle, result);
            break;

        default:
            printf("\n  [!] Invalid choice.\n");
    }
}

/* SECTION 3 — LOGARITHMIC OPERATIONS */

void menuLogarithm() {
    int choice;
    double val, base, result;

    printBanner();
    printf("  [ LOGARITHMIC OPERATIONS ]\n\n");
    printf("   1. log10(x)   — Common logarithm  (base 10)\n");
    printf("   2. ln(x)      — Natural logarithm (base e)\n");
    printf("   3. log_b(x)   — Logarithm with custom base b\n");
    printf("   0. Back to Main Menu\n\n");
    printLine();
    printf("  Enter choice: ");
    scanf("%d", &choice);

    if (choice == 0) return;

    switch (choice) {
        case 1:
            printf("  Enter x (x > 0): ");
            scanf("%lf", &val);
            if (val <= 0) {
                printf("\n  [!] Error: Logarithm is defined only for x > 0.\n");
            } else {
                result = log10(val);
                printf("\n  Result : log10(%.4lf) = %.6lf\n", val, result);
            }
            break;

        case 2:
            printf("  Enter x (x > 0): ");
            scanf("%lf", &val);
            if (val <= 0) {
                printf("\n  [!] Error: Logarithm is defined only for x > 0.\n");
            } else {
                result = log(val);
                printf("\n  Result : ln(%.4lf) = %.6lf\n", val, result);
            }
            break;

        case 3:
            printf("  Enter base b (b > 0, b != 1): ");
            scanf("%lf", &base);
            if (base <= 0 || base == 1) {
                printf("\n  [!] Error: Base must be > 0 and != 1.\n");
                break;
            }
            printf("  Enter x   (x > 0): ");
            scanf("%lf", &val);
            if (val <= 0) {
                printf("\n  [!] Error: x must be > 0.\n");
            } else {
                result = log(val) / log(base);
                printf("\n  Result : log_%.2lf(%.4lf) = %.6lf\n", base, val, result);
            }
            break;

        default:
            printf("\n  [!] Invalid choice.\n");
    }
}

/* SECTION 4 — POWER & SQUARE ROOT OPERATIONS */

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
                printf("\n  [!] Error: 0 raised to a negative power is undefined.\n");
            } else {
                result = pow(a, b);
                printf("\n  Result : %.4lf ^ %.4lf = %.6lf\n", a, b, result);
            }
            break;

        case 2:
            printf("  Enter x (x >= 0): ");
            scanf("%lf", &a);
            if (a < 0) {
                printf("\n  [!] Error: Square root of a negative number is not real.\n");
            } else {
                result = sqrt(a);
                printf("\n  Result : sqrt(%.4lf) = %.6lf\n", a, result);
            }
            break;

        case 3:
            printf("  Enter x: ");
            scanf("%lf", &a);
            result = cbrt(a);
            printf("\n  Result : cbrt(%.4lf) = %.6lf\n", a, result);
            break;

        case 4:
            printf("  Enter x: ");
            scanf("%lf", &a);
            printf("  Enter n (root degree, n != 0): ");
            scanf("%lf", &b);
            if (b == 0) {
                printf("\n  [!] Error: Root degree cannot be zero.\n");
            } else if (a < 0 && fmod(b, 2.0) == 0) {
                printf("\n  [!] Error: Even root of a negative number is not real.\n");
            } else {
                result = pow(a, 1.0 / b);
                printf("\n  Result : %.4lf ^ (1/%.4lf) = %.6lf\n", a, b, result);
            }
            break;

        default:
            printf("\n  [!] Invalid choice.\n");
    }
}

/*SECTION 5 — FACTORIAL & PERMUTATION / COMBINATION*/

double factorial(int n) {
    if (n < 0)  return -1;   /* signal: invalid */
    if (n == 0) return 1;
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

void menuFactorialPerm() {
    int choice, n, r;
    double fact, perm, comb;

    printBanner();
    printf("  [ FACTORIAL & PERMUTATION / COMBINATION ]\n\n");
    printf("   1. Factorial     n!\n");
    printf("   2. Permutation   P(n, r) = n! / (n-r)!\n");
    printf("   3. Combination   C(n, r) = n! / (r! * (n-r)!)\n");
    printf("   0. Back to Main Menu\n\n");
    printLine();
    printf("  Enter choice: ");
    scanf("%d", &choice);

    if (choice == 0) return;

    switch (choice) {
        case 1:
            printf("  Enter n (n >= 0): ");
            scanf("%d", &n);
            if (n < 0) {
                printf("\n  [!] Error: Factorial is not defined for negative numbers.\n");
            } else {
                fact = factorial(n);
                printf("\n  Result : %d! = %.0lf\n", n, fact);
            }
            break;

        case 2:
            printf("  Enter n and r (n >= r >= 0): ");
            scanf("%d %d", &n, &r);
            if (r < 0 || n < 0 || r > n) {
                printf("\n  [!] Error: Requires n >= r >= 0.\n");
            } else {
                perm = factorial(n) / factorial(n - r);
                printf("\n  Result : P(%d, %d) = %.0lf\n", n, r, perm);
            }
            break;

        case 3:
            printf("  Enter n and r (n >= r >= 0): ");
            scanf("%d %d", &n, &r);
            if (r < 0 || n < 0 || r > n) {
                printf("\n  [!] Error: Requires n >= r >= 0.\n");
            } else {
                comb = factorial(n) / (factorial(r) * factorial(n - r));
                printf("\n  Result : C(%d, %d) = %.0lf\n", n, r, comb);
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

/* ────────────────────────────────────────────────
   HELPER: Validate matrix dimensions (1..MAX_SIZE)
   ──────────────────────────────────────────────── */
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

    /* --- Get dimensions of Matrix A --- */
    printf("  Enter dimensions of Matrix A:\n");
    printf("    Rows    : ");  scanf("%d", &rA);
    printf("    Columns : ");  scanf("%d", &cA);

    if (!validDim(rA) || !validDim(cA)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    /* --- Get dimensions of Matrix B --- */
    printf("\n  Enter dimensions of Matrix B:\n");
    printf("    Rows    : ");  scanf("%d", &rB);
    printf("    Columns : ");  scanf("%d", &cB);

    if (!validDim(rB) || !validDim(cB)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    /* --- Compatibility check --- */
    if (rA != rB || cA != cB) {
        printf("\n  [!] Error: Matrix addition requires identical dimensions.\n");
        printf("      Matrix A is %dx%d but Matrix B is %dx%d.\n", rA, cA, rB, cB);
        return;
    }

    /* --- Input matrices --- */
    readMatrix(A, rA, cA, 'A');
    readMatrix(B, rB, cB, 'B');

    /* --- Perform addition --- */
    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cA; j++)
            C[i][j] = A[i][j] + B[i][j];

    /* --- Display result --- */
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

    /* --- Get dimensions of Matrix A --- */
    printf("  Enter dimensions of Matrix A:\n");
    printf("    Rows    : ");  scanf("%d", &rA);
    printf("    Columns : ");  scanf("%d", &cA);

    if (!validDim(rA) || !validDim(cA)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    /* --- Get dimensions of Matrix B --- */
    printf("\n  Enter dimensions of Matrix B:\n");
    printf("    Rows    : ");  scanf("%d", &rB);
    printf("    Columns : ");  scanf("%d", &cB);

    if (!validDim(rB) || !validDim(cB)) {
        printf("\n  [!] Error: Dimensions must be between 1 and %d.\n", MAX_SIZE);
        return;
    }

    /* --- Compatibility check --- */
    if (cA != rB) {
        printf("\n  [!] Error: Incompatible dimensions for multiplication.\n");
        printf("      Columns of A (%d) must equal Rows of B (%d).\n", cA, rB);
        return;
    }

    /* --- Input matrices --- */
    readMatrix(A, rA, cA, 'A');
    readMatrix(B, rB, cB, 'B');

    /* --- Perform multiplication (dot product) --- */
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            C[i][j] = 0.0;                        /* initialise cell */
            for (int k = 0; k < cA; k++) {
                C[i][j] += A[i][k] * B[k][j];    /* accumulate dot product */
            }
        }
    }

    /* --- Display result --- */
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
        case 1: matrixAddition();       break;
        case 2: matrixMultiplication(); break;
        case 0:                         break;
        default:
            printf("\n  [!] Invalid choice.\n");
    }
}

/* MAIN MENU */

void printMainMenu() {
    printBanner();
    printf("  Select a category:\n\n");
    printf("   1.  Basic Arithmetic      ( +  -  *  /  %% )\n");
    printf("   2.  Trigonometry          ( sin, cos, tan, arc )\n");
    printf("   3.  Logarithm             ( log, ln, log_b )\n");
    printf("   4.  Power & Square Root   ( x^y, sqrt, cbrt )\n");
    printf("   5.  Factorial & Perm/Comb ( n!, P(n,r), C(n,r) )\n");
    printf("   6.  Matrix Operations     ( A+B, AxB )\n");
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
            case 1: menuArithmetic();    break;
            case 2: menuTrigonometry();  break;
            case 3: menuLogarithm();     break;
            case 4: menuPowerRoot();     break;
            case 5: menuFactorialPerm(); break;
            case 6: menuMatrix();        break;
            case 0:
                printf("\n  Goodbye! Thank you for using the calculator.\n\n");
                break;
            default:
                printf("\n  [!] Invalid option. Please try again.\n");
        }

        if (choice != 0) {
            printf("\n  Press ENTER to return to the main menu...");
            getchar(); /* consume leftover newline */
            getchar(); /* wait for user */
        }

    } while (choice != 0);

    return 0;
}
