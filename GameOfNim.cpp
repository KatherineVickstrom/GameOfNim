#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main()
{
	srand(time(0));
	char mode;
	char playAgain;
	int numStones = 0;
	int playerNum = 0;
	int computerNum = 0;
	int firstPlayer = 0;

	do																					// This do-while loop is for being able to play the game again.
	{
		cout << "***********************THE GAME OF NIM***********************\n\n";
		cout << "Rules of the game:\n";
		cout << "* Each player can remove 1, 2, or 3 stones from the pile.\n";
		cout << "* The player who makes the last move loses.\n\n";
		cout << "Choose mode:\n";
		cout << "Easy Mode (e) or Hard Mode (h): ";
		cin >> mode;

		while ((mode != 'e') && (mode != 'h'))						// This while loop is to ensure the player chooses either easy mode or hard mode.
		{
			cout << "Error! Must enter e or h.\n";
			cout << "Choose mode:\n";
			cout << "Easy Mode (e) or Hard Mode (h): ";
			cin >> mode;
		}

		if (mode == 'e')								// This if statement is just for what needs to be said in the beginning
		{										// (what mode was chosen, initial number of stones, who goes first) but
			cout << "You chose the easy mode.\n\n";					// doesn't need to be repeated every turn.
			numStones = ((rand() % 12) + 10);
			cout << "The initial number of stones is " << numStones << endl;
			cout << "Now let's roll the dice to see who goes first..." << endl;
			Sleep(2000);
			firstPlayer = (rand() % 2);
			if (firstPlayer == 0)
			{
				cout << "You go first!\n\n";
			}
			else
			{
				cout << "The computer goes first.\n\n";
			}
			do																				// This do-while loop is for the game itself.
			{
				if (firstPlayer == 0)						// This if statement is what will happen when it's the player's turn.
				{
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}
					numStones = numStones - playerNum;
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << numStones << " stone(s) remaining.\n\n";
					firstPlayer = 1;					// When firstPlayer is 1, it's the computer's turn.
				}
				else if (firstPlayer == 1)					// This else statement is what will happen when it's the computer's turn.
				{
					cout << "The computer is choosing a move...\n";
					Sleep(2000);
					if (numStones > 3)
					{
						computerNum = ((rand() % 3) + 1);
					}
					else if (numStones == 2)
					{
						computerNum = 2;
					}
					else
					{
						computerNum = 1;
					}
					numStones = numStones - computerNum;
					cout << "The computer removed " << computerNum << " stone(s) from the pile.\n";
					cout << "There are " << numStones << " stone(s) remaining.\n\n";
					firstPlayer = 0;	// When firstPlayer is 0, it's the player's turn.							
				}
			} while (numStones > 0);
		}

		else if (mode == 'h')								// This if statement is just for what needs to be said in the beginning
		{										// (what mode was chosen, initial number of stones, who goes first) but
			cout << "You chose the hard mode.\n\n";					// doesn't need to be repeated every turn.
			numStones = ((rand() % 12) + 10);
			cout << "The initial number of stones is " << numStones << endl;
			cout << "Now let's roll the dice to see who goes first..." << endl;
			Sleep(2000);
			firstPlayer = (rand() % 2);
			if (firstPlayer == 0)
			{
				cout << "You go first!\n\n";
			}
			else
			{
				cout << "The computer goes first.\n\n";
			}
			do
			{
				if (firstPlayer == 0)						// This if statement is what will happen when it's the player's turn.
				{
					cout << "Enter the number of stones you want to remove: ";
					cin >> playerNum;
					while ((playerNum > 3) || (playerNum < 1))
					{
						cout << "Error! Must enter a number between 1 and 3: ";
						cin >> playerNum;
					}
					numStones = numStones - playerNum;
					cout << "You removed " << playerNum << " stone(s) from the pile.\n";
					cout << "There are " << numStones << " stone(s) remaining.\n\n";
					firstPlayer = 1;
				}

				else if (firstPlayer == 1)					// This else statement is what will happen when it's the computer's turn.
				{
					cout << "The computer is choosing a move...\n";
					Sleep(2000);
					if ((numStones % 4 == 1) || (numStones % 4 == 2))	// If the number of stones is a multiple of four plus 1 the computer has no winning
					{							// strategy so it will only remove 1 stone. When the remainder of the number of stones
						computerNum = 1;				// divided by 4 is either 1 or 2, then the number is a multiple of 4 + 1.
					}
					else if (numStones % 4 == 3)				// If the remainder of the number of stones divided by 4 is 3 then taking away 2
					{							// stones will leave a multiple of four plus 1 stones.
						computerNum = 2;
					}
					else if (numStones % 4 == 0)				// TIf the remainder of the number of stones divided by 4 is 0 then taking away 3
					{							// stones will leave a multiple of four plus 1 stones.
						computerNum = 3;
					}
					numStones = numStones - computerNum;
					cout << "The computer removed " << computerNum << " stone(s) from the pile.\n";
					cout << "There are " << numStones << " stone(s) remaining.\n\n";
					firstPlayer = 0;
				}
			} while (numStones > 0);
		}

		if (firstPlayer == 0)
		{
			cout << "You win!\n\n";							// If the game ends on the players turn it mean the computer took the last stone
		}										// so the player wins.

		else										// If the game ends on the players turn it mean the player took the last stone
		{										// so the computer wins.
			cout << "You lose...\n\n";
		}

		cout << "Would you like to play again? (y or n): ";
		cin >> playAgain;
		cout << endl << endl;

	} while (playAgain == 'y');
	cout << "Thanks for playing!\n\n";

	return 0;
}
