/* @Author: Edwina Edward
 * @Description: Simulate the walks
 * that hans will take on the way to the dentist
 */
#include <iostream>
#include <cmath>
using namespace std;

struct Hans {
  int x;
  int y;
};

int distance(int i, int walk);
float distbtwn(int x, int y, int x2, int y2);

int main(){
  Hans man;

  int firstfeet = 20;
  int walks = 0;
  int steps = 19;
  while (walks < 250){
    int decisionpoints = 0;
    walks++;
    int dist = 0; //current distance from formula
    int step = 0;
    char prev = 'y'; // did i last do x or y
    char prevt = 'r'; // did i last go right or left
    int total = 0; //total feet travelled per walk
    man.x = 0;
    man.y = 0;
    steps++;
    // each walk has up to 400 decision points
    while (decisionpoints <= 400){
      step++;
      decisionpoints++;
      if (steps == 20){
        dist = 20;
    } else {
        dist = distance(steps, step);
    }
    //  cout << dist << " DISTANCE"<<endl;
      //7th decision point, turn left
      if ((step % 7 == 0) && (prev == 'y') ){ //left
        man.x -= dist;
        total+= dist;
        prev = 'x';
      } else if ((step % 7 == 0) && (prev == 'x')){ //left
        man.y -= dist;
        total += dist;
        prev = 'y';
      } else if ((step % 7 == 0) && (prev == 'x')){ //left
        man.y -= dist;
        total += dist;
        prev = 'y';
      } else if ((step % 7 == 0) && (prev == 'x')){ //left
        man.y -= dist;
        total += dist;
        prev = 'y';
      } else if ((step % 7 != 0) && (prev == 'y')){ //right
        man.x += dist;
        total+= dist;
        prev = 'x';
      } else if ((step % 7 != 0) && (prev == 'x')){ //right
        man.y += dist;
        total+= dist;
        prev = 'y';
      }
      //cout << man.x << " " << man.y << endl;
      //if you're 500 feet from nick's office...
      float distnick, disthome;
      distnick = distbtwn(man.x, man.y, 1000, 1000);
      disthome = distbtwn(man.x, man.y, 0, 0);

      //cout << "\t" << distnick << " " << disthome << endl;
      if (distnick <= 500.0){

        if (total / 5280.0 >= 1.0){
          std::cout << "Dr.Nick\t" << total << " "
          << "(" << distnick/5280.0  << ")" << endl;
        } else {
          std::cout << "Dr.Nick\t" << total << endl;
        }
        break;
      }

      //if youre less than or eq to 50 feet from home w/ at least 5 moves...
      if (disthome <= 50.0 && decisionpoints >= 5){
        
        if (total / 5280.0 > 1.0){
          std::cout << "Home\t" << total << " "
          << "(" << disthome/5280.0  << ")" << endl;
        }else {
          std::cout << "Home\t" << total << endl;
        }
        //break out while loop
        break;
      }

      //last decision point
      if (decisionpoints == 400){

        std::cout << "Lost\t" << total << endl;
        //break out while loop
        break;

      }
    }
  }

  std::cout << "Completed 250 walks.";
  return 0;
}

/* Pre: This function will recieve the number walk
* that this is, (ith walk)
* Post: returns the distance moved
*/
int distance(int i, int walk){
  int dist;
  for (int j = 0; j <= walk; j++){
    if (j == 0){
      dist = (((i * 124985 + 1367892) % 1654872235) % 300) + 21;
    }else{
      dist = (((dist * 124985 + 1367892) % 1654872235) % 300) + 21;
    }
  }
  return dist;
}

float distbtwn(int x, int y, int x2, int y2){
  return sqrt(pow(x2-x, 2)+pow(y2-y, 2));
}
