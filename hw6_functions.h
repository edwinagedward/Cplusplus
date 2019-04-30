#ifndef HW6_FUNCTIONS_H
#define HW6_FUNCTIONS_H

#include <iostream>
#include <array>
#include <algorithm>


//struct for each creature
struct Creature {
  std::string name;
  int length;
  int width;
};



bool lt(Creature a, Creature b);

bool areequal(Creature a, Creature b);

bool notequal(Creature a, Creature b);

void announcement(Creature a, std::string x);

void leavemessage(int a, int b, int c);

#endif
