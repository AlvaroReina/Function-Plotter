#include <math.h>

double linear (double num){
    return num;
}

double logarithmic (double num){
    if(num <= 0) return 0;
    else return num;
}

double squareroot (double num){
    return sqrt(num);
}

double reciprocal (double num){
    if(num == 0) return 0;
    else return 1/num;
}

double absolute (double num){
    return fabs(num);
}

double cosine (double num){
    return cos(num);
}

double sine (double num){
    return sin(num);
}

double epower (double num){
    return exp(num);
}
