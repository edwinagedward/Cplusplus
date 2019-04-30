/******************************************************************************
Author: Edwina Edward
Date: Tuesday December 4th
File: hw6.cpp
Description: Simulate a conversation between beatrice
and hans

*******************************************************************************/
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
#include "hw7_functions.h"
using namespace std;

map < string, string > badwords;
map < string, string > badwordsupper;


int
main ()
{

  badwords.insert (pair < string, string > ("shit", "poop"));
  badwords.insert (pair < string, string > ("idiot", "mean person"));
  badwords.insert (pair < string, string > ("dammit", "darn it"));
  badwords.insert (pair < string, string > ("crap", "poopie"));
  badwords.insert (pair < string, string > ("damn", "hoot"));

  badwordsupper.insert (pair < string, string > ("Shit", "Poop"));
  badwordsupper.insert (pair < string, string > ("Idiot", "Mean person"));
  badwordsupper.insert (pair < string, string > ("Dammit", "Darn it"));
  badwordsupper.insert (pair < string, string > ("Crap", "Poopie"));
  badwordsupper.insert (pair < string, string > ("Damn", "Hoot"));

  ifstream bin;//beatrice sayings
  ifstream hin;//hans sayings
  ofstream convo("Conversation.dat"); //output
  bin.open ("BeatriceSayings.dat");
  hin.open ("HansSayings.dat");
  //  convo.open ("Conversation.dat");
  int counter = 0;//keeps track of conversation

  int bcount, hcount;//number of sayings each
  //  getline(bin, bcount, '\n');
  //  getline(hin, hcount, '\n');
  bin >> bcount;
  hin >> hcount;
  cout << bcount;
  cout << hcount;

  string harr[hcount];
  string barr[bcount];
  int i = 0;

 
  // fill bsayings array
  while (!bin.eof () && (i < bcount))
    {
      getline (bin, barr[i++], '\n');
      //    bin >> barr[i++];
    }//1

  // fill hsayings array
  int x = 0;
  while (!hin.eof () && (x < hcount))
    {
      //hin.clear();
      getline (hin, harr[x++], '\n');
      // hin >> harr[x++];
    }
  srand (37);    
  //actual conversation
  while (convo.is_open()){
    convo<< "Hans: Hello?";
    convo<< "Beatrice: Hello.";
    while (counter++ < 20)
    {
 
      string hcurrsaying;
      hcurrsaying = harr[rand () % (hcount - 1)];// choose random saying
      string bcurrsaying;
      bcurrsaying = barr[rand () % (bcount - 1)];
      string temp;
      //parse for bad words
      //    cout << bcurrsaying;

      hcurrsaying = checkbadword(hcurrsaying);
      bcurrsaying = checkbadword(bcurrsaying);
      convo << "Hans: " << hcurrsaying << endl;
      convo << "Beatrice: " << bcurrsaying << endl;
      //temp = checkbadword (bcurrsaying);
    }
  convo<< "Hans: " << "Goodbye.";
  convo<< "Beatrice: "<< "Goodbye.";
  convo.flush();
  bin.close();
  hin.close();
  convo.close();
    
  return 0;
}
}
