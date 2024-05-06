// declaring and defining a function
//calling a function
// returning types and returning values
// input parameters

//functions are reusable blocks of code that can be called in another function

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// return type function, function name, (input parameters) { code }
void SayHello(){
  cout << "Hello.\n";
}

// return type, functionName, (input parameters) { code }
void Say(string givenText) {
  cout << givenText << "\n";
}

// return type, functionName
int AddTwoNumbers(int firstNum, int secondNum) {
  int sum = firstNum + secondNum;

  return sum;
}

// return type
bool AskYN(string question) {
  do{
    cout << question << " (y/n)\n";
    char input;
    cin >> input;

    if(input == 'y') {
      return true;
    }
    if(input == 'n') {
      return false;
    }

    cout << "You need to type a lowercase 'y' or 'n'.\n";

  }while (true);
}

// dice roll returns a number between 1 and 6 (inclusive)
// int DiceRoll() {
//   return rand() % 6 + 1;
// }

// function overloading means declaring and defining another function with the same name
int DiceRoll(int sides = 6) {
  if(sides < 1) {
    sides = 2;
    
  }
  if(sides > 100) {
    sides = 100;
  }
  return rand() % sides + 1;
}


// create a CastDamage() function that returns an int. 
// accepts two input parameters min and max
// creates a int damage that is random in a range from min to max.
// rolls a d6 for a critical chance (if d6 =6, double the damage.)
// then returns the damage
// use default values
// in main(), call this function 10 times using a for loop
int CastDamage(int min = 1, int max = 10) {
  int damage = rand() % (max - min) + min;
  if(DiceRoll() == 6) {
    damage += damage;
  }

  return damage;
}





int main() {
  srand(time(0));                    // seed the random number generator
cout << "Your roll is " << DiceRoll() << ".\n";
  cout << "Your D20 roll is " << DiceRoll(20) <<".\n";
cout << "Your D-14 roll is " << DiceRoll(-14) << ".\n";

  // for(int i = 5; i < 10; i++) {
  //   cout << "Enemy does " << CastDamage(12,24) << "!!\n";
  // }


int playerHealth = 100;
  cout << "Here we go adventuring!\n";
  
  
  do {
    int damageTaken = CastDamage(6,7);
    playerHealth -= damageTaken;
    cout << "Oh no! We stubbed our toe! We lost << " << damageTaken << "     health.\n";

    if(playerHealth <= 0) break;

    cout << "We now have " << playerHealth << " health.\n";
    
    if(AskYN("Do you want to keep adventuring?")) {
      cout << "Cool!\n";
      
    } else {
      cout << "We're done!\n";
      break;
    }
}while(true);
  
  
  SayHello();          // this calls the function
  SayHello();
  Say("How are you today?");
  Say("My name is Gerald.");
  cout << "4 + 5 = " << AddTwoNumbers(4, 5) <<".\n";
  if(AskYN("Do you want to keep playing?")) {
    cout << "Too bad. This is the end.\n";
  } else {
    cout << "Thanks for playing!\n";
  }

 
}


// int main() {
//   // create a vector of least favorite foods
//   cout << "Hello World!\n";

//   vector<string> unlikeableFoods = {Brussel Sprouts, Blueberries, Eggs, Meatballs, tuna};

//   // use a for loop to display them
//   for(int i = 0; i < unlikeableFoods.size(); i++){
//     cout << unlikeableFoods[i] << "\n";
//  }
//}