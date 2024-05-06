#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;



int RollDie(int sides = 6){
  return rand() % sides + 1;
}
string askYesNo(string question){
  cout << question << endl;
  string input;
  cin >> input;
  bool valid = false;

  while(!valid) {
    if(input == "yes" || input == "Yes"){
      valid = true;
      return "yes";
    }
    else if (input == "no" || input == "No") {
      valid = true;
      return "no";
    }
    else {
      cout << "Invalid input, please try again." << endl;
      cin >> input;
      
    }
  }
  return 0;
}

int main() {
  srand(time(0));
  int health = 10;
  int gold = 0;
  int turns = 0;
  if(askYesNo("Would you like to go adventuring? yes/no \n") == "yes") {
    bool playing = true;
    
    while(playing) {

      turns++;
      
      cout << "An Orc is attacking you!\n";
      int attackRoll = RollDie();
      int blockRoll = RollDie();
  
      cout << "The orc attacks for " << attackRoll << " and you block for " << blockRoll << endl;
      
      if(blockRoll >= attackRoll) {
        cout << "You successfully blocked the attack!\n";
        health -= 1;
        cout << "You ran away but lost 1 health!\n";
        cout << "You now have " << health << " health!\n";
        
        int goldGained = RollDie();
        cout << "You found " << goldGained << " gold!\n";
        gold += goldGained;
        cout << "You now have " << gold << " gold!\n";
      }
      else {
        int damage = attackRoll;
        health -= damage;
        cout << "You failed to block the attack and took " << damage << " damage!\n";
        cout << "You now have " << health << " health!\n";
      }
      if(health <= 0) {
        playing = false;
      }
      else if(askYesNo("Would you like to keep adventuring?") == "no") {
        playing = false;
      }
    }
  }
    
  else {
    cout << "You decide to not go adventuring.\n";
  }
  
  if(health > 0) {
    cout << "Congrats on not dying!\n";
    cout << "You played " << turns << " turns!\n";
    cout << "You found " << gold << " gold!\n";
    if(health < 5) {
      cout << "You have " << health << " health. You should go see a doctor!\n";
    }
    
      }
  else {
    cout << "You died!\n";
    cout << "Your body was left with " << gold << " gold!\n";
  }
}