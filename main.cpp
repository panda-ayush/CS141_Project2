/*--------------------------------------------
   Program 2: Knight Escape
   The objective of this game is to get the white knight to the empty
	square in the upper right-hand corner of the board.
	
	The knight can only move in the way that it does during a traditional
	chess game. This means that a knight can only move in a valid L-shape
	(two squares in a horizontal direction, then one in a vertical direction OR 
	two squares in a vertical direction, then one in a horizontal direction).
		       
   Course: CS 141, Spring 2022
   System: MacOS using CLion
   Author: Ayush Panda
    
 ---------------------------------------------*/

#include <iostream>		// for input and output
#include <cctype>		   // for toupper()
#include <iomanip>
using namespace std;



// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = "\u2658";		// White knight character 
const string BlackKnight = "\u265E";		// Black knight character 
const string BlankPosition = " ";			// Blank position character

string playerBoard [5][5]; //intializes the board for the game

int score = 500; //initialize score to default score
int moveNumber = 1; //initialize amount of moves
bool cont = true; //boolean to help run program's while loop
char menuOption; //initialize option where user chooses menuoption


//function that tests if the positional movement is valid

bool positionValidity (int position1, int position2) {
  bool valid;
  if (position1 < 1 || position2 > 25) {
    valid = true;
  }
  else {
    valid = false;
  }
  return valid;
}
//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage() //displays the welcome message and instructions for the game
{
    cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n"
         << " \n"
         << "The objective of this puzzle is to get the white knight "
		 << "up to the empty square in the top right corner of the board. "
		 << "Use standard knight moves from a traditional chess game, "
		 << "where a knight moves in an L-shape. \n"
		 << "This means that a knight can only move either "
		 << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
		 << "2) two squares in a vertical direction, then one in a horizontal direction."
		 << " \n"
		 << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
		 << "Try to complete the puzzle with the smallest number of valid moves!"
    	 << endl;
}//end displayWelcomeMessage()

    
// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
// This function makes use of global variables p1..p25, which represent
// each of the positions on the board
void displayBoard()
{
cout << endl << "   Board          Position" << endl;
      for (int i = 0; i < 5; i++)
      {
        for (int j = 0; j < 5; j++)
        {
          cout << " " << playerBoard[i][j];
        }
        cout << "    ";
        for (int j = 0; j < 5; j++)
        {
          cout << " " << setw(2) << i * 5 + j + 1;
        }
        cout << endl;
      }
      cout << endl;
    }
 //end displayBoard()


// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {
   
  displayWelcomeMessage(); // calls the instructional function
	
	// Set board values to the default starting position
   // ...
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++) {
      playerBoard[i][j] = BlackKnight; //sets board values to default starting positions
  }
}
	
  playerBoard[0][4] = BlankPosition; // adds blank position 
  playerBoard[4][0] = WhiteKnight; //adds white knight position
  
   
  displayBoard(); // calls board function

  cout << "Current score: " << score << endl << endl;
//outputs current score

  
   // Loop that controls game play
   while(true) {
       if (score <= 0) { //if statement to check if program is valid to run
      cout << "You have run out of moves. Try to do better next time!" << endl;
      break; }//ends whiel loop
     if (cont) { //is program is good to run outputs instructions for user options
      cout << moveNumber << ". "
             << "Enter one of the following: \n"
			 << "  - M to move a knight from one position to another, \n"
			 << "  - R to reset the board back to the beginning, or \n"
			 << "  - X to exit the game. \n"
			 << "Your choice -> ";
    cin >> menuOption; //inputs user menu option
    menuOption = toupper(menuOption); // convert user input to uppercase

      
    if (menuOption == 'X') { 
    cout << "Exiting..." << endl;
      break;
      }
      // If the user entered 'X' to exit,
      // break out of this loop that controls game play
      // ...
    else if (menuOption == 'R') {
      
      cout << endl << "   *** Restarting" << endl;
        for (int i = 0; i < 5; i++){
          for (int j = 0; j < 5; j++) {
            playerBoard[i][j] = BlackKnight;
  }
}
  playerBoard[0][4] = BlankPosition;
  playerBoard[4][0] = WhiteKnight; 
      displayBoard();
      score = 500; 
      cout << "Current score: " << score << endl << endl;
      moveNumber = 1;
      cont = true;
      continue;
    }
    
      
      // If the user entered 'R' to reset,
      // reset the board back to the beginning
      // resets score
      // resets number of moves and lets the loop start again
    
    else if (menuOption == 'M') {
      int position1; //first position call
      int position2; //second position call
 

      cout << "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5): "; //gives instructions for how to call a position
      
      cin >> position1 >> position2; //inputs position
      cout << "You have chosen to move a knight from position " << position1 << " to position " << position2 << "." << endl; //outputs changes user wants

      int a = (position1 - 1) / 5;
      int b = (position1 - 1) % 5;
      int c = (position2 - 1) / 5;
      int d = (position2 - 1) % 5;

      //math used to help run game

//if statement that checks if the position requested is correct if not removes 10 from score and restarts 
      if (positionValidity(position1, position1)) {
        cont = false;
        score = score - 10;
        cout << "The source position should be a valid position on the board (1-25). Try again." <<endl;
      }

      //if statement that checks if the position requested is correct if not removes 10 from score and restarts
      else if (positionValidity(position2, position2)) {
        cont = false;
        score = score - 10;
        cout << "The destination position should be a valid position on the board (1-25). Try again." <<endl;
    }
//checks if player positon call is a legal position call
      else if (playerBoard[a][b] == BlankPosition) {
        cont = false;
        score = score - 10;
        cout << "The source position should have a knight. Try again." << endl;
    }
//checks if player position call is not a blank position
      else if (playerBoard[c][d] != BlankPosition) {
        cont = false;
        score = score - 10;
        cout << "The destination position should be empty. Try again." << endl;
      }
      //math to calculate and execute position call and updates board
      else if ((abs(a-c) == 1 && abs (b-d)==2) || (abs(a-c) == 2 && abs(b-d)== 1)) {
        cont = true;
        score = score - 5;
        playerBoard[c][d] = playerBoard[a][b];
        playerBoard[a][b] = BlankPosition;
        moveNumber++;
        displayBoard();
      }
      //else if move is not l shape restarts menu option and removes 1- from score
      else {
        cont = false;
        score = score - 10;
        cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
      }
      
    //checks if player gets the white knight in the winning position and if it does ends game
      if (playerBoard[0][4] == WhiteKnight) {
      cout << "Congratulations, you did it!" << endl;
      break;
    }
//outputs current score
    cout << "Current score: " << score << endl << endl;
    cont = true;
    continue;

   
    }

   }
   break;

   }

   cout << "Thank you for playing!" << endl;

	return 0;
}