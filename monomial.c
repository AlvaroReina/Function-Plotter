#include <stdio.h>
#include <stdlib.h>
#include "monomial.h"

void create(T_Polynomial* poly){
    T_Polynomial temp = malloc(sizeof (T_Polynomial));
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
    T_Polynomial temp = malloc(sizeof(T_Polynomial));
    double aux;
    printf("Enter multiplier: ");
    scanf("%lf", &aux);
    temp->multiplier = aux;
    printf("Enter degree: ");
    scanf("%lf", &aux);
    temp->degree = aux;
    return temp;
}

void addc(T_Polynomial* poly){
    T_Polynomial temp = createMono();
    add(poly, &temp);
}

void show(T_Polynomial poly){
    T_Polynomial current;
    T_Polynomial next;
    current = poly;
    next = poly;
    printf("Expression: \n");
    do{

        current = next;
        if(next->multiplier != 0){
            printf(" + %fx",next->multiplier);
            printf("^%f",next->degree);
        }
        if(current->next != NULL){
        next = current->next;
        }
    }while (current->next != NULL);
}
