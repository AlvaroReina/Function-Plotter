#include <stdio.h>
#include <stdlib.h>
#include "monomial.h"
#include "functions.h"

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
    temp->funct = &squareroot;
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
        printf(" + %fx", current->multiplier);
        printf("^%f", current->degree);
        current = current->next;
    }
}

void pruebaFunct(double(*functionPtr)(double)){
    double i = 5;
    printf("Resultado: %f",(*functionPtr)(i));

}

void calcPoint(int x, double(*functionPtr)(double)){

}
