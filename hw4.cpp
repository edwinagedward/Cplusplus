/*
 * @Author: Edwina Edward
 * @Date: October 4 2018
 * @Description:
 *
 *
 *
 *
 */

#include <iostream>
using namespace std;

int options();
int steps();
int anxiety();
void print_steps(int steps);
int day();
int medication(int anxiety, int day);
void print_pills(int pills);
int verify(int smallest, int largest);
int hours_slept();
int minutes(int hrs, int steps, int pills);
void print_minutes(int minutes);
int calories(int steps);
void print_calories(int calories);
void intro();

int main(){
  string answer;
  bool quit = false;
  bool answer1 = false;
  bool answer2 = false;
  bool answer3 = false;
  bool answer4 = false;


  while (quit == false){
    int legs;
    int anxiety1;
    int day1;
    int hours1;
    int calories1;
  
    intro();

    switch (options()){

    case 1:
      answer1 = true;
      print_steps(steps());
      
      break;
      
    case 2:
      answer2 = true;
      anxiety1 = anxiety();
      day1 = day();
      print_pills(medication(anxiety1, day1));
      break;
      
    case 3:
      if ((answer1 == false) | (answer2 == false)) {
	cout << "\nWe cannot continue because"
	     << " previous steps are not finished!"
	     << "\n BREAKING. \n\n";
	break;
      }
      hours1 = hours_slept();
      answer3 = true;
      print_minutes(minutes(hours1, answer1, answer2));
      break;
      
    case 4:
      if (answer1 == false | answer2 == false | answer3 == false) {
	cout << "\nWe cannot continue because"
	     << " previous steps are not finished!"
	     << "\nBREAKING. \n\n";
	break;
      }
      answer4 = true;
      calories1 = calories(answer1);
      print_calories(calories1);
      break;
      
    case 5:
      quit = true;
      break;
    }
  }

  return 0;
}

void intro(){
  cout << "\n\nWelcome to the Hans-O-Matic Program!\n"<<endl;
}

int anxiety(){
  int attempt;
  cout << "\nWhat is your anxiety?: ";
  cin >> attempt;
  if (attempt < 1 | attempt > 10) attempt = verify(1, 10);
  return attempt;
}
int day(){
  int attempt;
  cout << "\nWhat day is it?: ";
  cin >> attempt;
  if (attempt < 1 | attempt > 7)  attempt = verify(1, 7);
  return attempt;
}

int medication(int anxiety, int day){
  int num_pills;
  num_pills = anxiety - day;
  if (num_pills < 0) num_pills = 0;
  return num_pills;
}

void print_pills(int pills) {
  cout << "\nThe number of pills you need is: "
       << pills;
}

int verify(int smallest, int largest){
  int attempt;
  bool result = false;
  do {
    cout << "\nYou must answer between " << smallest <<
      "and " << largest << ". Please try again: ";
    cin >> attempt;
    cin.clear();
    if (attempt >= smallest && attempt <= largest) result = true;
  } while (result == false);
  
      return attempt;
}

int hours_slept(){
  int hours;
  cout << "\nHow many hours did you sleep?: ";
  cin >> hours;
  return hours;
}

int minutes(int hrs, int steps, int pills){
  int pill;
  int minutes;
  
  if (pills == 0) pill = 1;

  minutes = hrs + (steps / pill);
  return minutes;
		  
}

void print_minutes(int minutes){
  cout << "\nYou can take a nap for "
       << minutes << " minutes.";
}

int calories(int steps){
  int height;
  int weight;
  float temp;
  float calories;

  cout << "\nWhat is your weight?: ";
  cin >> weight;
  if (weight < 10 | weight > 800){ weight = verify(10, 800); }
  
  cout << "\nWhat is your height?: ";
  cin >> height;
  if (height < 1 | height > 1000){ height = verify(1, 1000);}

  cout << "\nWhat is the room temperature?: ";
  cin >> temp;
  if (temp < 1 | temp > 200) { temp = verify(1, 200); }

  calories = 6 * weight + 2 * height + (1/temp) + steps;

  return calories;
}

void print_calories(int calories){
  cout << "\nYour caloric intake max is: "
       << calories << " calories.";
  return;
}

int steps(){
  int legs;
  cout << "\nHow many legs do you want?: ";
  cin >> legs;
  return legs;
  
}

void print_steps(int legs){
  int result = legs;
  for (int i = 1; i < legs; i++){
    result *= i;
  }
  cout << "You may take "
       << result << "steps.";
  return;
}

int options(){
  int answer;
  cout << "Health-o-Matic Options"<<endl;
  cout << "-----------------------"<< endl;
  cout << "1. Taking a Walk!"<<endl;
  cout << "2. Your Medications"<<endl;
  cout << "3. Nap Time!!"<<endl;
  cout << "4. Caloric Intake"<<endl;
  cout << "5. Quit"<<endl;
  cout << "\n Please enter an option: ";
  cin >> answer;
  return answer;
}
