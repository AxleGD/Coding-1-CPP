#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

// Global Variables go at the top so that all of the functions can see the variables
// dangerous because everyone can see and edit. don't do this unless you have to
//vector<string> colors = {"Red", "Green", "Blue", "Yellow"}; 

// create a function named triple that returns an int that has been tripled


int Triple(int givenNumber) {
  return givenNumber * 3;
}

// variable scope = variables only exist in the code block they are created in.
void DisplayVec(vector<string> vec) {
 // vector<string>colors = {"black", "brown", "pruce", "gray"}
  for(int i =0; i < vec.size(); i++) {
    cout << vec[i] << ".\n";
  }
}

// function named add to vector "addtovector" return type is void, accepts 2 parameters
// a vector of strings, and a string to add.

vector<string> AddToVector(vector<string> vec, string newItem) {
  vec.push_back(newItem);
  return vec;
}

// pass by copy/value, versus passing by reference
void RefAddToVector(vector<string>& rVec, string newItem) {
  rVec.push_back(newItem);
}

  bool PasswordCheck(string user, string pass) {
    if(user == "Brian") {
      if(pass == "Green") {
        cout << "Hello Professor!\n";
          return true;
      } else {
          cout << "Wrong Password, Imposter!.\n";
        return false;
      }
    }
    else if(user == "admin" || pass == "admin") {
      cout << "Speak friend and enter.\n";
      return true;
      
    }
    else if(user == "Harry" && pass == "Potter") {
      cout << "Welcome, Mr. Potter.\n";
      return true;
    }
    else {
      cout << "Unrecognized User.\n";
      return false;
    }
  }

int main() {
  cout << "Hello World!\n";

  cout << "triple of 5 is " << Triple(5) << ".\n";

  vector<string> colors = {"Red", "Green", "Blue", "Yellow"}; 
  vector<string> names = {"Rex", "Shulk", "Glimmer", "Nikol"}; 
  RefAddToVector(colors, "Magenta");
  
  DisplayVec(colors);
  DisplayVec(names);

  cout << "OH, I really like tourmaline, let's add that to the vector of colors.\n";
  colors = AddToVector(colors, "Tourmaline");

  cout << "Here's our colors: \n";
  DisplayVec(colors);
}
