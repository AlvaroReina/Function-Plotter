#include <stdio.h>
#include <stdlib.h>
#include "monomial.h"
#include "functions.h"
int main()
{
    char control = 'y';
    T_Polynomial poly;
    int min;
    int max;
    create(&poly);
    while(control != 'N' && control != 'n') {
        addc(&poly);
        show(poly);
        printf("Create a new node?(Y/N)");
        fflush(stdin);
        scanf("%c", &control);
    }
    printf("Enter range. From: ");
    scanf("%d", &min);
    printf("To: ");
    scanf("%d", &max);
    plot(min, max,&poly);
    return 0;

}
