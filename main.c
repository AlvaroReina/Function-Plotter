#include <stdio.h>
#include <stdlib.h>
#include "monomial.h"
int main()
{
    T_Polynomial poly;
    create(&poly);
    T_Polynomial temp = createMono();
    add(&poly, &temp);
    addc(&poly);
    show(poly);
    return 0;
}
