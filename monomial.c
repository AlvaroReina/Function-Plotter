#include <stdio.h>
#include <stdlib.h>
#include "monomial.h"
#include "functions.h"
#include <math.h>

void create(T_Polynomial* poly){
    T_Polynomial temp = malloc(sizeof (struct T_Mono));
    temp->degree = 0;
    temp->funct = NULL;
    temp->multiplier = 0;
    temp->next = NULL;
    *poly = temp;
}

void destroy(T_Polynomial* poly){
    T_Polynomial current = *poly;
    T_Polynomial next;
    while (current->next != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *poly = NULL;
}

void add(T_Polynomial* poly, T_Polynomial* mono){
    (*mono)->next = *poly;
    *poly = *mono;
}

T_Polynomial createMono(){
    T_Polynomial temp = malloc(sizeof(struct T_Mono));
    double aux;
    printf("Enter multiplier: ");
    fflush(stdin);
    scanf("%lf", &aux);
    temp->multiplier = aux;
    printf("Enter degree: ");
    fflush(stdin);
    scanf("%lf", &aux);
    temp->degree = aux;
    temp->funct = selectFunction();
    return temp;
}

void addc(T_Polynomial* poly){
    T_Polynomial temp = createMono();
    add(poly, &temp);
}

void show(T_Polynomial poly){
    T_Polynomial current;
    current = poly;
    printf("Expression: \n");
    while(current != NULL){
        if(current->multiplier != 0){
        printf(" + %f", current->multiplier);

        printfunction(current->funct);
        printf("^%f", current->degree);
        }
        current = current->next;
    }
    printf("\n");
}


void plot(int minRange, int maxRange, T_Polynomial* poly){
    if(minRange > maxRange){
        int swap = minRange;
        minRange = maxRange;
        maxRange = swap;
    }
    double i = minRange;
    T_Polynomial current;
    double res = 0;
    double temp;
    while(i <= maxRange){
        current = *poly;
        while(current != NULL){
            if(current->funct != NULL){
            temp = calcPoint(i,current->funct);
            temp = pow(temp,current->degree);
            temp = temp * (current->multiplier);
            res = res + temp;
            }
            current = current->next;
        }
        printf("X: %f   |   Y: %f\n", i, res);
        res = 0;
        i++;
    }
}

double calcPoint(double x, functiontype funct){
    return (*funct)(x);
}

functiontype selectFunction(){
    int num;
    functiontype res = NULL;
    printf("Enter function('0' for help): ");
    fflush(stdin);
    scanf("%d", &num);
    while (num > 8 || num < 0){
        printf("case not recognized\n");

        printf("Enter function('0' for help): ");
        fflush(stdin);
        scanf("%d", &num);
    }
    switch(num) {

    case 0 :
            printf("'1' for Linear\n");
            printf("'2' for Logarithmic\n");
            printf("'3' for SquareRoot\n");
            printf("'4' for Reciprocal\n");
            printf("'5' for Absolute\n");
            printf("'6' for Cosine\n");
            printf("'7' for Sine\n");
            printf("'8' for Exponential\n");

            res = selectFunction();
            break;

    case 1 :
                res =  &linear;
                break;

    case 2 :    res = &logarithmic;
                break;

    case 3 :    res = &squareroot;
                break;

    case 4 :    res = &reciprocal;
                break;

    case 5 :    res = &absolute;
                break;

    case 6 :    res = &cosine;
                break;

    case 7 :    res = &sine;
                break;

    case 8 :    res = &epower;
                break;


    }
    return res;
}

void printfunction(functiontype funct){
   if(funct == &squareroot) printf("sqrt(x)");
   else if (funct == &logarithmic) printf("log(x)");
   else if (funct == &reciprocal) printf("1/(x)");
   else if (funct == &absolute) printf("abs(x)");
   else if (funct == &cosine) printf("cos(x)");
   else if (funct == &sine) printf("sin(x)");
   else if (funct == &epower) printf("exp(x)");
   else printf("x");
}
