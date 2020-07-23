//Miguel Ibarra
//Rock, Paper, Scissors Gane
//Header files 
#include <iostream>
#include <string>
#include <ctime>        //For time function
#include <cstdlib>      //To generate random numbers 
using namespace std;

//function prototypes
void displayGameDetails();  //
void playGame();
string getComputerChoice();
string getUserChoice();
string getChoiceAsString(int);
void displayChoices(string, string);
string findWinner(string, string);

//Start of main function
int main ()
{
  char again;
  //Call the displayGameDetails() function 
  //in order to see the rules of the game 
  //get the computer's choice for the game
  displayGameDetails();

  //Call the playGame() function find and display
  // the winner of Rock, Paper, Scissors.
  playGame();

  return 0;
}

//displayGameDetail definition 
//This function displays the rules of the game 
//Rock, Paper, Scissors
void displayGameDetails()
{
  //display the game details
  cout << "Rock, Paper, Scissors Game! \n";
  cout << "_____________________________\n\n";
  cout << "\t\t\tRules: \n\n";
  cout << "Rock smashes Scissors. Rock wins!\n";
  cout << "Paper covers Rock. Paper wins!\n";
  cout << "Scissors cuts Paper. Scissors wins!\n";
  cout << "Both players has the same choice. Play again!\n\n";
}

//playGame function definition 
//This function find and displays the winner 
//of Rock, Paper, Scissors
void playGame()
{
  //create local variables
  //these local variables only have scope 
  //for this function
  string computerChoice;
  string userChoice;
  string gameWinner;
  //Call the computerChoice() function in order 
  //to determine the computer's choice for the game
  //Store the result in the computerChoice variable
  computerChoice = getComputerChoice(); 

  //Call the function getUserChoice() in order
  //to get the user's choice for the.
  //Store the result in the local variable userChoice
  userChoice = getUserChoice();

  //Call the displayChoices() function to display the 
  //computer's choice and the user's choice for the game.
  //In this function we are going to pass out local 
  //variables computerChoice and userChoice as our arugments 
  displayChoices(computerChoice, userChoice);

  //call the findWinner() function to determine 
  //the winner of the game. Here we are also passing
  //two arguments and storing the result in the 
  //gameWinner variable.
  gameWinner = findWinner(computerChoice, userChoice);

  //Display the winner of the game 
  if (gameWinner != "")
    cout << "The winner of the game is " << gameWinner << endl;

    //end of playGame function
}

//computerChoice() function gets and returns the 
//computer's choice for the game
//getComputerChoice() function definition
string getComputerChoice()
{
  //declare local variables 
  int comp;
  string compChoice;
  
  //Get the current time 
  unsigned seedTime = time(0);

  //Call the predefined srand function to generate 
  //a random number 
  srand(seedTime);

  //Establish the boundaries to get a random number
  //between 1 and 3.
  comp = 1 + rand() % 3;

  //Call the getChoiceAsString() function to get the 
  //computer's choice as a string
  compChoice = getChoiceAsString(comp);

  //return the value of the computer's choice
  return compChoice;

  //end of getComputerChoice function.
}


//Get the user's choice by using the
//getUserChoice() function and return the user's choice
//getUserChoice() function definition
string getUserChoice()
{
  //declare your locar variables
  int user;
  string userChoice;
  
  //Display a meny for the user and prompt the user 
  //to enter the choice they desire.
  cout << "\nThe computer has its choice already...\n";
  cout << "\nNow it is time for you to choose...\n";
  cout << "1. Rock\n";
  cout << "2. Paper\n";
  cout << "3. Scissors\n\n";

  //promt the user to enter a choice
  cout << "Please enter your choice: ";
  cin >> user;

  //Verify whether the choice is either 1, 2, 3
  //use a while loop for input validation
  while (user < 0 || user > 3)
  {
    //prompt the user to enter a correct value
    cout << "Please enter 1, 2, or 3 only: ";
    cin >> user;

    //end while loop
  }

  //Call the getChoiceAsString() function to get the 
  //user's choice as a string. Store this result 
  //in the userChoice variable. Pass the user 
  //variable as an argument. 
  userChoice = getChoiceAsString(user);

  //return the user's choice 

  return userChoice;

  //end of getUserChoice
}

//The getChoiceAsString() function 
//This function returns the choice as a string
//getChoiceAsString function definition
string getChoiceAsString(int choice)
{
  //return the name of the corresponding choice
  if (choice == 1)
    return "Rock";
  else if (choice == 2)
    return "Paper";
  else 
    return "Scissors";

  //end getChoiceAsString Function
}

//displayChoices() function displays the computer's
//choice as well as the user's choice
//displayChoices() function definition
void displayChoices(string comp, string user)
{
  //display the computer choice
  cout << "\nThe computer's choice: " << comp << endl;
  
  //display the user's choice
  cout << "Your choice: " << user << endl;

  //end of displayChoices function
}

//findWinner() function determines and returns 
//the winner of the game.
//findWinner() function definition.
string findWinner(string comp, string usr)
{
  //declare local variables. 
  string computer = "the computer";
  string user = "the user";
  string winner; 

  //Find the winner of the game 
  if (comp == "Rock" && usr == "Scissor")
    winner = computer;
  else if (comp == "Rock" && usr == "Paper")
    winner = user;
  else if (comp == "Paper" && usr == "Rock")
    winner = computer;
  else if (comp == "Paper" && usr == "Scissor")
    winner = user;
  else if (comp == "Scissor" && usr == "Paper")
    winner = computer;
  else if (comp == "Scissor" && usr == "Rock")
    winner = user;
  else 
  {
    //display a message telling the user 
    //both got the same choice.
    cout << "\nThe game is drawn" << endl;
    cout << "Play again" << endl;
    cout << "___________" << endl << endl;

    //Call the playGameFunction() again to 
    //play one more time.
    playGame();
  }

  //return the winner of the game
  return winner;

  //end of findWinner Function

  //end of the program 
}