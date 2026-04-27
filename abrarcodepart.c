#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/* SECTION 3 — LOGARITHMIC OPERATIONS */
void printBanner();
void clearScreen();
void printLine();
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
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}