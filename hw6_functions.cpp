/* @Author: Edwina Edward
 * @File: hw6.cpp
 * @Description: Functions needed for hw6.cpp
 */

#include "hw6_functions.h"
using namespace std;

//Overload the < operator.
//Pre: Enter two card objects (creature objects)
//Post: This will return whether the card can be stacked

bool lt(Creature a, Creature b) {
  return ((a.length < b.length) && (a.width < b.width)); // KF: I moved it here
}//KF: ; this semicolon shouldn't be here.

bool areequal(Creature a, Creature b){
  return ((a.length == b.length) && (a.width == b.width));
}

bool notequal(Creature a, Creature b){
  return (a.name != b.name);
}


//Pre: gets the creature object and string to be said
//Post: Prints the creature's name and what they said.
void announcement(Creature a, string x){
  cout << a.name << " has said ... " << x
       << " ... And handed you a card!" << endl;
  return;
}

//Pre: gets the sizes of the deck, stacked cards, and
//     distinct visitors, respectively.
//Post: Prints out the reasons why Hans can/van not leave.
void leavemessage(int a, int b, int c){
  std::array<std::string, 3> reasons;
  std::array<bool, 3> options = {false};

  if (a >= 150) options[0] = true;
  if (b >= 6) options[1] = true;
  if (c >= 14) options[2] = true;

  // KF: You cannot assign values to your array this way. This can be done
  // only to initialize your array.
  //reasons = ["Actually, I can't leave. I've hit my max of 150 cards.",
	//     "I stacked 6 cards, woohoo!",
	//     "I've gotten distinct cards from 14 creatures!"];

  // KF: Changed that to these
  reasons[0] = "Actually, I can't leave. I've hit my max of 150 cards.";
  reasons[1] = "I stacked 6 cards, woohoo!";
  reasons[2] = "I've gotten distinct cards from 14 creatures!";

  cout << "I CAN LEAVE FOR THE FOLLOWING REASONS:"<< endl;

  for (int i = 0; i <= 3; i++){
    if (options[i] == true) cout << reasons[i] << endl;
  }
  return;
}
