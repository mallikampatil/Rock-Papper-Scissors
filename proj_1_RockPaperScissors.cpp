/* ------------------------------------------------
   prog1RockPaperScissors.cpp
 
   Program #1: Play the game of Paper / Rock / Scissors against the computer.
   Class: CS 141, Spring 2019.  Tues 9am Lab
   Author: Mallika Patil
	 
	 See the program description page on the course web site at bit.ly/cs141
	 Within Codio you can run the solution by doing the following steps:
   1. Select the Tools / Terminal menu option
	 2. Within the terminal window, type in:  ./solution

   Grading Rubric:
		 55 Execution points
						  Option 1: (Computer always chooses R) and:
					 2		 User input of X immediately exits program
					 3		 User input of x (lower case) immediately exits program
				  10		 Program handles both lower and upper case user input (e.g. 'r' and 'R'); also
					          move number increments each move
				  15		 Score updates correctly for all user inputs: r, p, s
						  Option 2: Computer's move is random and:
					 7		 Predetermined input sequence correctly leads to computer win
				   8		 Predetermined input sequence correctly leads to human win
		         Option 3: 
           2     Correctly displays and updates the graphical score
		       8     Correctly displays and updates the graphical score, with assessment results hidden

		 45 Programming Style (Given only if program runs substantially correctly)
					10 Meaningful identifier names
					10 Comments: Has header.  Comments on each block of code.
					15 Appropriate data and control structures.  Code duplication is avoided.
					10 Code Layout: Appropriate indentation and blank lines.
 
   Having sample program output is not required within this header of your program, though it is helpful.
	 
	 
*/

/***
 * Mallavarapu: Very good
 * ***/

#include <iostream>    // For cin and cout
#include <cstdlib>     // For rand()
using namespace std;


//-----------------------------------------------------------------------------------------
int main()
{
    // Display Instructions
    cout << "CS 141 Program #1: Rock/Paper/Scissors                                \n"
         << endl
         << "Welcome to the game of Rock/Paper/Scissors where you play against     \n"
         << "the computer.  On each move the computer will choose R, P, or S, then \n"
         << "the user will be prompted for their choice, and then the score will   \n"
         << "be updated.  P beats R, R beats S, and S beats P. The score starts    \n"
         << "at 0.  Add one if the person wins, subtract one if the computer wins. \n"
         << "The game ends if the score reaches -5 or + 5.                         \n"
         << "User input of 'x' or 'X' causes the game to exit.                     \n"
         << endl
         << "Here we go!  \n"
         << endl;
    
    int computerChoiceVersion;
    cout << "Select how the computer chooses its move: \n"
         << "1. Always choose Rock \n"
         << "2. Random guess \n"
         << "3. Random guess with graphical score \n"
         << "Enter your choice: ";
    cin >> computerChoiceVersion;
    cout << endl;

    // Variable declarations
    char userResponse = ' '; 
    char computerChoice = ' ';
    int score = 0;
    int moveCounter = 0; 
  
    // Main loop should go here, with the indented sections below inside the main loop
    while (score > -5 && score < 5){
      
       // Prompt for and get the user's choice       
       moveCounter++; 
       cout << moveCounter << ". " << "Your move:";
       cin >> userResponse;           
      
       // Convert user response to upper case
       userResponse = toupper(userResponse);
      
       // Exit program if x pressed
       if (userResponse == 'X'){
          cout << "Exiting Program..." << endl;
          break; 
       }

       // Computer choice for game version 1                     
       if (computerChoiceVersion == 1){
          computerChoice = 'R';
       }

       // Computer choice needs to be randomized for game version 2 and 3
       else if ((computerChoiceVersion == 2) || (computerChoiceVersion == 3)){    
          int randNum;   // Declared for storing randomized number 
          randNum = rand() % 3;
          if (randNum == 0){
             computerChoice = 'R';       
          }
          else if (randNum == 1){
             computerChoice = 'P';       
          }
          else{
             computerChoice = 'S';
          }
       }       
      
       // Display Computer choice
       cout << "   Computer chose " << computerChoice << endl;
      
       // Update score depending on winner
       if ((computerChoice == 'R' && userResponse == 'R') || 
           (computerChoice == 'S' && userResponse == 'S') ||
           (computerChoice == 'P' && userResponse == 'P')){
          cout << "   Tie. ";
       }
       else if ((computerChoice == 'R' && userResponse == 'P') || 
                (computerChoice == 'S' && userResponse == 'R') ||
                (computerChoice == 'P' && userResponse == 'S')){
          score++;
          cout << "   User's point. "; 
       }
       else if ((computerChoice == 'R' && userResponse == 'S') ||
                (computerChoice == 'S' && userResponse == 'P') ||
                (computerChoice == 'P' && userResponse == 'R')){
          score--;
          cout << "   Computer's point. "; 
       }
      
       // Display score after updating, depending on game version
       if (computerChoiceVersion == 2 || computerChoiceVersion == 1){
          cout << "Score: " << score << endl;
       }
       else if (computerChoiceVersion == 3){
          cout << endl; 
          cout << "    -5 -4 -3 -2 -1  0  1  2  3  4  5 \n"
               << "   ----------------------------------\n";
          cout << "   ";
          int count;   // Counter for displey loop 
          int numTimes = score + 5;   // Calculating how '...' to print
          for(count = 0; count < numTimes ; count++ ){ 
             cout << "...";
          }   
          cout << "..^" << endl;
       }
       cout << endl;
    }
  
    // Display final message, depending on the score
    if (score == 0){
       cout << "Tie game!" << endl;
    }
    else if (score > 0){
       cout << "User wins!" << endl;
    }
    else if (score < 0){
       cout << "Computer wins!" << endl;
    }
    cout << endl;
    cout << "Ending program..." << endl;
    return 0;   // Keep C++ happy
}//end main()


