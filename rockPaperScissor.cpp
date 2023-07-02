#include <iostream>
#include <string>
#include <random>

void printInstructions();
int getRandomMove();
std::string* knowMove(int);
std::string* getResult(std::string*, std::string*);
void printResult(std::string*);

int main(){
  printInstructions();
  //Getting User's Input
  int userMove;
  std::cout << "Enter Your Move(In Number): ";
  std::cin >> userMove;

  //Getting random computer move.
  int computerMove = getRandomMove();

  //Convert numbers to actual play name(strings).
  std::string* userMoveS;
  std::string* computerMoveS;
  userMoveS = knowMove(userMove);
  computerMoveS = knowMove(computerMove);

  //Comare user and computer's play.
  std::string* result;
  result = getResult(computerMoveS, userMoveS);

  printResult(result); //Print Output.

  return 0;
}
/*Formatted Instructions*/
void printInstructions(){
  std::cout << "*******************************************" << "\n";
  std::cout << "************Rock_Paper_Scissor*************" << "\n";
  std::cout << "*******************************************" << "\n";
  std::cout << "Enter Your Move(numbers):"<< "\n";
  std::cout << "1 = Rock" << "\n";
  std::cout << "2 = Paper" << "\n";
  std::cout << "3 = Scissor" << "\n";
  std::cout << "You will be playing against computer!" << std::endl;
}
/*
  Using Generator & Distribution method create random number 1-3
*/
int getRandomMove(){
  std::random_device rd; // Random Generator.
  std::uniform_int_distribution<int> dist(1,3); // Range from 1-3.
  return dist(rd);
}

/*
  Finds out the move(rock or paper or scissor) from respective numbers(1-3)
*/
std::string* knowMove(int move){
  std::string* moveName = new std::string("");
  switch (move) {
    case 1:
      *moveName = "rock";
      break;
    case 2:
      *moveName = "paper";
      break;
    case 3:
      *moveName = "scissor";
      break;
    default:
      *moveName = " ";
      std::cout << "Invalid Move" << "\n";
      break;
  }
  return moveName;
}

/*
  Compares computer & user input and gives result as string pointer.
*/
std::string* getResult(std::string* moveComputer, std::string* movePerson){
  std::string* result = new std::string(" ");

  std::string win = "You Win, Computer chose " + *moveComputer + "!";
  std::string lose = "You Lose, Computer Win: It chose " + *moveComputer + "!";

  //Possible moves Comparison.
  if (*moveComputer == "rock" && *movePerson == "paper") {
    *result = win;
  }else if(*moveComputer == "paper" && *movePerson == "rock"){
    *result = lose;
  }else if(*moveComputer == "scissor" && *movePerson == "paper"){
    *result = lose;
  }else if(*moveComputer == "paper" && *movePerson == "scissor"){
    *result = win;
  }else if(*moveComputer == "rock" && *movePerson == "scissor"){
    *result = lose;
  }else if(*moveComputer == "paper" && *movePerson == "rock"){
    *result = win;
  }else{
    *result = "Match is Draw!!!";
  }

  //Free Memory
  delete moveComputer;
  delete movePerson;

  return result;
}

/*Formatted Printing*/
void printResult(std::string* result){
  std::cout << "\n" << "*******************************************" << "\n";
  std::cout << "Processing..." << "\n";
  std::cout << *result << "\n";
  std::cout << "Feel Free To Play Again! Just Run the file Again:)" << std::endl;

  delete result; //Free Memory.
}
