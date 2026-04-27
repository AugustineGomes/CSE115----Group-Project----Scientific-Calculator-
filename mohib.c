/*
 * ============================================================
 *         SCIENTIFIC CALCULATOR - CSE115 Project
 *         Language  : C
 *         Features  : Arithmetic, Trigonometry, Logarithm,
 *                     Power/Root, Factorial, Permutation,
 *                     Matrix (Addition & Multiplication)
 * ============================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// for clear screen

void clearscreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// for line

void printline(){
    printf("  ================================================\n");
}

void printbanner(){
    clearscreen();
    printline();
    printf("  ||      SCIENTIFIC CALCULATOR || CSE 115     ||\n");
    printline();
    printf("\n");
}

void menuarithmetic(){
    int choice;
    double a,b,result;

    printbanner();
    printf(" Arithmetic operation                            \n ");
    printf(" 1. addition       (a + b)                       \n ");
    printf(" 2. substraction   (a - b)                       \n ");
    printf(" 3. multipication  (a * b)                       \n ");
    printf(" 4. division       (a / b)                       \n ");
    printf(" 5. modulus       (a %% b) [integers only]       \n ");
    printf(" 0. back to menu                                \n\n");

    printline();

    printf("enter choice : ");
    scanf("%d", &choice);

    if(choice == 0){
        return;
    }

    if(choice < 1 || choice > 5){
        printf("invalid operation !!");
        return;
    }

    // for module
    if(choice == 5){
        int a,b;
        printf("enter two integer (a,b) : ");
        scanf("%d%d",&a,&b);

        if(b==0){
            printf("Error: Modulus by zero is undefined.\n");
        }
        else {
            printf("\n  Result : %d %% %d = %d\n", a, b, a % b);
        }
        return;
    }

    printf("enter two numbers (a,b) : ");
    scanf("%lf %lf",&a,&b);

    switch(choice){

      case 1 :
             result = a + b;
             printf("the addition is %lf + %lf = %lf",a,b,result);
             break;

      case 2 :
             result = a - b;
             printf("the substraction is %lf - %lf = %lf",a,b,result);
             break;

      case 3 :
             result = a * b;
             printf("the multipication is %lf * %lf = %lf",a,b,result);
             break;

      case 4 :
             if(b==0){
                printf("denominator cannot be 0\n");
             }
             else {
                result = a / b;
                printf("the division is %lf / %lf = %lf",a,b,result);
             }
             break;
    }
}

void mainmenu(){
    printbanner();
    printf("  Select a category:\n\n");
    printf("   1.  Basic Arithmetic      ( +  -  *  /  %% )\n");
    printf("   2.  Trigonometry          ( sin, cos, tan, arc )\n");
    printf("   3.  Logarithm             ( log, ln, log_b )\n");
    printf("   4.  Power & Square Root   ( x^y, sqrt, cbrt )\n");
    printf("   5.  Factorial & Perm/Comb ( n!, P(n,r), C(n,r) )\n");
    printf("   6.  Matrix Operations     ( A+B, AxB )\n");
    printf("   0.  Exit\n\n");
    printline();
    printf("  Enter choice: ");
}

int main()
{
    int choice;

    do{
        mainmenu();
        scanf("%d",&choice);

        switch(choice){

        case 1 :
            menuarithmetic();
            break;

        case 0 :
            printf("thank you for using the calculator !!");
            break;

        default :
            printf("invalid option !! ");
        }

        if (choice != 0) {
            printf("\n  Press ENTER to return to the main menu");
            getchar();
            getchar();
        }

    }while(choice != 0);

    return 0;
}
