/*
 *@Author: Edwina Edward
 *@Date: October 11 2018
 *@Description:
 *This script will provide a menu in order to 
 *allow the user to utilize mathematical formulas.
 */
#include <iostream>
#include "Calculator.h"
using namespace std;

int main(){
  bool quit = false;
  int choice;
  string temp = "Your result is: ";
  // This loop will continue until the user
  // declares that they want to quit
  while (quit == false){
    int a;
    float x;
    switch (intro()){
    case 1:
      //factorial of a number
      a = factorial(askfactorial());
      cout << temp << a; 
      break;
    case 2:
      //exponential of a number
      a = askexponential();
      cout << temp << a;
      break;
    case 3:
      // Cosine of a number
      x = askcosine();
      cout << temp << x; 
      break;
    case 4:
      //kth root
      x = askkthroot();
      cout << temp << x;
      break;
    case 5:
      //hyperbolic sine of x
      x = sinh(asksinh());
      cout << temp << x;
      break;
    case 6:
      quit = true;
  }
      
}
  return 0;
}

