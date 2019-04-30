#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
using namespace std;

int intro();
int askfactorial();
int factorial(int number);
int verify(int smallest, int largest);
int power(int num, int exp);
int exponential(int num, int terms);
int askexponential();
int askcosine();
int cosine(int x, int acc);
double kthroot(int x, int root);
double askkthroot();
double sinh(int x);
int asksinh();

#endif
