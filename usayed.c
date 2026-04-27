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

#define PI 3.14159265358979323846
#define DEG_TO_RAD(x) ((x)* PI/180.0)
#define RAD_TO_DEG(x) ((x)* 180.0/PI)

void menuTrigonometry() {

    int choice;
    double angle,result;

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

if(choice == 0) {
    return;
}

switch(choice) {

    case 1:
    printf("Enter angle (degrees): ");
    scanf("%lf",&angle);
    result = sin(DEG_TO_RAD(angle));
    printf("\n Result: sin(%.2lf°) = %.6lf\n",angle,result);
    break;

    case 2:
    printf("Enter angle(degrees): ");
    scanf("%lf",angle);
    result = cos(DEG_TO_RAD(angle));
    printf("\n Result: cos(%.2lf°) = %.6lf\n",angle,result);
    break;

    case 3:
    printf("Enter angle(degrees): ");
    scanf("%lf",&angle);
    if(fmod(angle,180.0) == 90) {
        printf("\n [!] Error: tan(%.2lf°) is undefined.\n",angle);
    }
    else {
        result = tan(DEG_TO_RAD(angle));
        printf("\n Result: tan(%.2lf°) = %.6lf\n",angle,result);
    }
    break;

    case 4:
    printf("Enter value(must be between -1 and 1): ");
    scanf("%lf",&angle);
    if(angle < -1 || angle > 1) {
        printf("\n [!] Error: arcsin domain is [-1,1].\n");
    }
    else {
        result = RAD_TO_DEG(asin(angle));
        printf("\n Result: arcsin(%.6lf) = %.4lf°\n",angle,result);
    }
    break;

    case 5:
    printf("Enter value(must be between -1 and 1): ");
    scanf("%lf",&angle);
    if(angle < -1 || angle > 1) {
        printf("\n [!] Error: arccos domain is [-1,1]\n");
    }
    else {
        result = RAD_TO_DEG(acos(angle));
        printf("\n Result: arccos(%.6lf) = %.4lf° \n",angle,result);
    }
    break;

    case 6:
    printf("Enter value: ");
    scanf("%lf",&angle);
    result = RAD_TO_DEG(atan(angle));
    printf("\n Result: arctan(%.6lf) = %.4lf°. \n",angle,result);
    break;

    default:
    printf("\n [!] Invalid Choice! \n");
    break;
}

}

int main() {

menuTrigonometry();

return 0;    
}