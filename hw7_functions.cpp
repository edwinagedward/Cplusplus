/******************************************************************************
Author: Edwina Edward
Date: Tuesday December 4th
File: hw7_functions.cpp
Description: Simulate a conversation between beatrice
and hans

*******************************************************************************/
#include "hw7_functions.h"



string
checkbadword (string saying)
{
  int i = 0;
  string currpunct;
  //char tempword[80], reset[80];
  string tempword, reset;
  bool existpunc;//is there a punctuation?
  bool jump = false;
  char sentence[256] = "";
  reset = "";
  bool dirty = false; // is there bad language?
  while ((saying.c_str ())[i] != '\0')
    {

      if (ispunct (saying.c_str ()[i]) && (saying.c_str ()[i+1] == '\0')
	  && existpunc == false){
        currpunct = saying.c_str ()[i];
	existpunc = true;
        //i--;
        jump = true;
        continue;
      }
      else if (ispunct (saying.c_str ()[i]) && existpunc == false){
	currpunct = saying.c_str ()[i];
	existpunc = true;
	i++;
	continue;
      } 

      else if (isspace (saying.c_str ()[i]) || jump == true)
	{//if you see the end of a word
	  //      strcat(currword.c_str(), tempword.c_str());
	  if (isupper (tempword.c_str ()[0]))
	    {//is it uppercase?
	      map < string, string >::iterator itr;
	      for (itr = badwordsupper.begin (); itr != badwordsupper.end ();
		   ++itr)
		{
		  // if you find a bad word
		  if (strcmp (itr->first.c_str (), tempword.c_str ()) == 0)
		    {
		      strcat (sentence, " ");
		      strcat (sentence, itr->second.c_str ());
		      dirty = true;
		      if (existpunc == true)
			{// check if punctuation exists
			  strcat (sentence, currpunct.c_str ());
			  strcat (sentence, " ");
			  existpunc = false;
			} else {strcat (sentence, " ");}
		      //cout << "UPPERBAD" << sentence;
		      continue;
		    }
		}
	      strcat (sentence, tempword.c_str ());
	      if (existpunc == true)
		{
		  strcat (sentence, currpunct.c_str ());
		  strcat (sentence, " ");
		  existpunc = false;
		}else if (existpunc == true && jump == true){
		strcat (sentence, currpunct.c_str ());
		strcat (sentence, " ");
		existpunc = false; 
		break;
	      }
	      else {strcat (sentence, " ");}
	      //cout << "UPPER NOBAD:" << endl;
	      //cout << sentence << endl;
	      i++;
	    }
	  else
	    {//lower
	      map < string, string >::iterator itrl;
	      for (itrl = badwords.begin (); itrl != badwords.end (); ++itrl)
		{
		  if (strcmp (itrl->first.c_str (), tempword.c_str ()) ==
		      0)
		    {
		      strcat (sentence, " ");
		      strcat (sentence, itrl->second.c_str ());
		      dirty = true;
		      if (existpunc == true)
			{
			  strcat (sentence, currpunct.c_str ());
			  strcat (sentence, " ");
			  existpunc = false;
			}
		      break;
		      // cout << "LOWERBAD:" << sentence;
		    }
		}
	      strcat (sentence, tempword.c_str ());
	      strcat (sentence, " ");
	                  
	      if (existpunc == true)
		{
		  strcat (sentence, currpunct.c_str ());
		  existpunc = false;
		}
	      //cout << "LOWER NOBAD:" << sentence;
	      i++;
	    }
	  tempword = reset;
	}

      else
	{//none of the above. just keep adding letters
	  //      strcat(tempword.c_str(), (saying.c_str())[i]);
	  tempword.push_back (saying.c_str ()[i]);
	  i++;
	}
      //    cout << i;
      //i++;
    }
  if (dirty == true){
    return sentence;}
  else {
    return saying;
  }

}
