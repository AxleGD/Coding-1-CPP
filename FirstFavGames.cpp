#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cout << "What are some of your favorite video games?\n";
  bool running = true;

  vector<string> favoriteGames {"Minecraft", "Ark", "Xenoblade", "Persona"};
  cout <<"There are currently " << favoriteGames.size() << " games in the list.\n";
  
  
do {
  cout <<"What would you like to do? (add, list, quit)\n";
  string response = "";            // creates a blank variable
  getline(cin, response);         // allows person to type a "response"
  
  if(response == "list") {        // If responding with "list"
    cout <<"There are currently " << favoriteGames.size() << " games in the list.\n";
    cout << "Here is the list of games:\n";
    
    for(int i = 0; i < favoriteGames.size(); i++) {      // looping until i = size of vector
      cout << favoriteGames[i] << "\n";                // prints favorite games vector
    }
   
  }
  
  else if(response == "add") {        // If responding with "add"
    cout << "What game would you like to add?\n";
    string nameInput;
    getline(cin, nameInput);
    
    favoriteGames.push_back(nameInput);

    
    
  }

  else if(response == "quit") {        // If responding with "quit"
    cout << "Have a great day!\n";
    running = false;
  }
    
    else {
      cout << response << " wasn't one of the options.\n";
     
    }
  
  } while (running == true);
  
}