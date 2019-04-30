/* @Author: Edwina Edward
 * @File: Calculator.cpp
 * @Functionality: This script provides the calculator
 * functionality.
 */

#include "Calculator.h"

// Pre: This script does not take any arguments
// Post: This script outputs the menu and returns
// the user's choice
int intro(){
  int choice;
  cout << "\t OPTIONS \n";
  cout << "---------------------------\n";
  cout << "1. Factorial of x\n";
  cout << "2. Exponential of x\n";
  cout << "3. Cosine of x\n";
  cout << "4. Roots of x\n";
  cout << "5. Hyperbolic Sine of x\n";
  cout << "6. Quit";
  cout << "\n Please choose an option: ";
  cin >> choice;
  return choice;
}
//Pre: This function takes two arguments, the first int being
// the smallest number that may be given, and the second int being
// the largest.
//Post: Upon the user sucessfully selecting a number within the range,
//the function will return that number.
int verify(int smallest, int largest){
  int attempt;
  bool result = false;
  do {
    cout << "\nYou must answer between " << smallest <<
      " and " << largest << ". Please try again: ";
    cin >> attempt;
    cin.clear();
    if (attempt >= smallest && attempt <= largest) result = true;
  } while (result == false);

  return attempt;
}
/*Pre: No parameters needed for this function.
 *Post: This will prompt the user for a number between
 * 0 and 10, and upon recieving a successful number will
 * return this input.
 */
int askfactorial(){
  int answer;
  cout << "\n What number would you like to calculate the factorial?"
       << " The number must be between 0 and 10.: ";
  cin >> answer;
  if (answer < 0 | answer > 10) answer = verify(0, 10);
  return answer;
}
//Pre: This script takes a number as an argument
// Post: This script prints out the answer to the screen
// No return type.
int factorial(int number){
  int result = 1;
  if (number == 0) return 1;
  for (int i = number; i >= 1; i--){
    result *= i;
  }
  return result;
}
/*Pre: This function takes a number and it's exponent as
 * parameters.
 * Post: Returns the number to the given exponent
 */
int exponent(int num, int exp){
  int answer = num;
  if (exp == 0) return 1;
  for (int i = 1; i <= exp; i++){
    answer *= num;
  }
  return answer;
}
/*Pre: This function takes a number and the amount of terms
 * wanted to calculate the exponential.
 * Post: This function will return the result of the exponential.
 */
int exponential(int num, int terms = 8){
  double result = 0;
  int counter = 0;
  for (int i = 0; i <= num; i++){
    result += (exponent(num, i)/factorial(i));
    if (++counter >= terms) break;
  }
  return result;
}
/*Pre: This function takes no parameters
 *Post: This function prompts the user for the
 * number and terms. This returns the result
 */
int askexponential(){
  int number, terms;
  float result;
  cout << "\nPlease enter the number you'd like to calculate: ";
  cin >> number;
  cout << "\nPlease enter the number of terms: ";
  cin >> terms;

  return exponential(number, terms);
}
/*Pre: This function takes no parameters
 *Post: This function returns the cosine of the users number with the
 * accuracy chosen.
 */
int askcosine(){
  int x, acc;
  cout << "\nPlease choose a number for the cosine: ";
  cin >> x;
  cout << "\nPlease choose an accuracy between 1 and 5: ";
  cin >> acc;
  if (acc < 1 | acc > 5) acc = verify(1, 5);
  return cosine(x, acc);
}
/*Pre: Takes an integer x and an accuracy that ranges from 1 to 5.
 *Post: returns an approximate cosine of the number with the
 * declared accuracy.
 */
int cosine(int x, int acc){
  double result;
  int k = 0;
  for (int i = 2; i < 2*acc; i+=2){
    result += (exponent(x, i)/ factorial(i));
    if (++k >= acc) break;
  }
  return 1 - result;
}
/*Pre: An integer X to find the kth root of,
 * and the root they'd like to find.
 *Post: The integer to the kth root.
 */
double kthroot(int x, int root){
  int x0 = x;
  double xn = x * 1.0;
  double exp;
  int temp;
  for (int k = 2; k <= 100; k++){
    for (double i = 0.0; i <= k-1; i++){
      exp = xn;
      exp *= xn;
    } 
    temp = ((k-1)*xn + x0/exp);
    xn = (temp*1.0)/k;
}
  return xn;
}
/*Pre: No parameters
 *Post: Returns the kth root of the number
 *given by the user.
 */
double askkthroot(){
  int root;
  int x;
  cout << "What is the number you'd like the root of?: ";
  cin >> x;
  cout << "What root would you like? Enter 2 for square root,"
       << " 3 for cubed root, 4 for fourth root, and"
       << " 5 for fifth root: ";
  cin >> root;
  if (root < 2 | root > 5) root = verify(2, 5);
  return kthroot(x, root);
}
/*Pre: This script takes an integer x as input
 *Post: It returns the hyperbolic sin according to
 *the formula given.
 */
double sinh(int x){
  double result;
  double exp = exponential(x)*1.0;
  return (exp - (1/exp))/2;
}
/*Pre: No parameters
 *Post:Prompts user for an integer
 */
int asksinh(){
  int result;
  cout << "\nPlease enter an integer x for sinh(x): ";
  cin >> result;
  return result;
}
