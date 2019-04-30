#ifndef HW7_FUNCTIONS_H
#define HW7_FUNCTIONS_H

#include <iostream>
#include <cmath>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <map>
#include <string>
#include <iterator>
#include <cctype>
using namespace std;

extern std::map < string, string > badwords;
extern std::map < string, string > badwordsupper;
std::string checkbadword (std::string temp);

#endif
