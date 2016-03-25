#include <stdio.h>
#include <stdlib.h>
#include "monomial.h"
#include "functions.h"
int main()
{
    T_Polynomial poly;
    create(&poly);
    T_Polynomial temp;
    T_Polynomial temp2;
    temp = createMono();
    temp2 = createMono();
    add(&poly, &temp);
    add(&poly, &temp2);
    show(poly);
    return 0;
}
