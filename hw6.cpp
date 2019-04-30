/* @Author: Edwina Edward
 * @File: hw6.cpp
 * @Description: Simulate Hans retreiving
 * cards from the creatures of atlantis
 */

#include "hw6_functions.h"
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool operator<(const Creature &a, const Creature &b){
  return ((a.length < b.length) && (a.width < b.width));
}

//array of all stackable cards
vector<Creature> stackable_cards(6);


//deck of cards
std::array<Creature, 150> deck = {};

string sayings[]= {"Whazzup?", 
"Duuude, totally love the horse head and human body combo!",
    "Looking for a card (shark)?", "Are you someone famous?",
    "You look fishy to me; or are you horsing around?", 
    "Don't trust the salmon!!!", 
    "Here's some advice: the shark wants you to be his chum!",
    "Better take some paper towels if you visit the blobfish.", 
    "Hey man, got any sea-weed?", "Don't be so crabby!",
    "Let me give you my card...my phone number is on the back.",
    "I'd gladly pay you Tuesday for a lobster roll today.", 
    "Just keep swimming, swimmin, swimming, ...",
    "You just keep sinking, sinking, sinking,..."};

int main(){
//Initializing the creatures.
Creature wwalrus;
wwalrus.name = "Wanda Walrus";
wwalrus.length = 2;
wwalrus.width = 6;

Creature ssardine;
ssardine.name = "Stanley Sardine";
ssardine.length = 3;
ssardine.width = 1;

Creature sseahorse;
sseahorse.name = "Sylvia Seahorse";
sseahorse.length = 4;
sseahorse.width = 2;

Creature jjellyfish;
jjellyfish.name = "Janie Jellyfish";
jjellyfish.length = 1;
jjellyfish.width = 10;

Creature ddolphin;
ddolphin.name = "Doris Dolphin";
ddolphin.length = 8;
ddolphin.width = 4;

Creature bblobfish;
bblobfish.name = "Bob Blobfish";
bblobfish.length = 1;
bblobfish.width = 4;

Creature sshark;
sshark.name = "Sammy Shark";
sshark.length = 8;
sshark.width = 4;

Creature wwhale;
wwhale.name = "Walter Whale";
wwhale.length = 6;
wwhale.width = 2;

Creature ssalmon;
ssalmon.name = "Stevie Salmon";
ssalmon.length = 2;
ssalmon.width = 3;

Creature sshellfish;
sshellfish.name = "Sheila Shellfish";
sshellfish.length = 1;
sshellfish.width = 3;

Creature doctopus;
doctopus.name = "Daniel Octopus";
doctopus.length = 3;
doctopus.width = 7;

Creature mherrings;
mherrings.name = "Mark Herrings";
mherrings.length = 9;
mherrings.width = 5;

Creature btuna;
btuna.name = "Bernie Tuna";
btuna.length = 3;
btuna.width = 5;

Creature otilapia;
otilapia.name = "Oscar Tilapia";
otilapia.length = 5;
otilapia.width = 3;

Creature creatures[14]= 
             {wwalrus, ssardine, sseahorse, jjellyfish,
	     ddolphin, bblobfish, sshark, wwhale, ssalmon, sshellfish,
	      doctopus, mherrings, btuna, otilapia};

std::array<Creature,14> visited = {};


  //Set the seed to 37
  srand(37);
  Creature current;
  std::string announce;
  int distinct = 0;
  int sizev = 0;
  int sizes = 0;
  int sized = 0;
  int index;
  
  while ((sized != 150) && (sizes != 6) && 
	 (distinct != 14)){

    current = creatures[rand()%14];
    
    //if hans visited anyone before
    if (sizev > 0){
      bool match = false;
      for (int i = 0; i < visited.size(); i++){
	if (!notequal(current, visited[i])) {match = true;}
	if (notequal(current, visited[i]) && (i == visited.size()-1) && (match == false)){
	  visited[sizev++] = current;
	  distinct++;
	  break;
	}
      }
    } else{
      visited[0] = current;
      
      sizev++;
      distinct++;
    }

    index = rand()%14;
    announce = sayings[index];
    
    //the creature says their saying
    announcement(current, announce);
    
    //check for stackable cards
    if (sizes > 0){
      for (int i = 0; i < stackable_cards.size(); i++){
	// if its smaller than any middle card
	if (lt(current, stackable_cards[i]) && 
	    lt(stackable_cards[i-1], current) && (i > 0)){
	  //add current to the stackable cards
	  stackable_cards.push_back(current);
	  //add current to the deck
	  deck[sized++] = current;
	  sizes++;
	  //sort the deck
	  sort(stackable_cards.begin(), stackable_cards.end());
	  break;
	  // if its smaller than the first card
	} else if ((i == 0) && (current < stackable_cards[i])){
	  //stackable_cards[sized++] = current;
	  stackable_cards.push_back(current);
	  deck[sized++] = current;
	  sort(stackable_cards.begin(), stackable_cards.end());
	  sizes++;
	  break;
	  //if its larger than the last card
	} else if ((i == stackable_cards.size()-1) && 
		   lt(stackable_cards[i], current)){
	  //stackable_cards[sized++] = current;
	  stackable_cards.push_back(current);
	  deck[sized++] = current;
	  sort(stackable_cards.begin(), stackable_cards.end());
	  sizes++;
	  break;
	  //if its smaller than the last card (didnt fit any criterion)
	} else if ((i == stackable_cards.size()-1) && 
		   lt(current, stackable_cards[i])){
	  deck[sized++] = current;
	  break;
	}
      }
      // if this is the first card
    } else {
      stackable_cards[0] = current;
      deck[0] = current;
      sized++;
      sizes++;
  }
 }
  cout << "SizeD: " << sized << " Sizes: " << sizes << " Distinct: " << distinct<< endl; 
  leavemessage(sized, sizes, distinct);

  return 0;
}
