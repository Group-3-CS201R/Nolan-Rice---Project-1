//Nolan Rice project 1
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int diceRoll() {   //generates a number 1-6
	return int((rand() % 6) + 1);
}

int playerTurn(int userScore) {   //player turn, gives chance to reroll or hold, then and adds pot to the player score
	int roll = 0;
	int pot = 0;
	char playerChoice = 'r';
	
	cout << "Player's Turn" << endl;
	while (playerChoice == 'r') {
		roll = diceRoll();
		if (roll == 1) {
			cout << "Die Roll : BUST" << endl;
			pot = 0;
			break;
		}
		else {
			pot += roll;
			cout << "Die Roll : " << roll << "     Pot : " << pot;
			if ((userScore + pot) >= 50) break;
			cout << "\t(R)oll again or (H)old? ";
			cin >> playerChoice;
			playerChoice = tolower(playerChoice);
			while ((playerChoice != 'h') && (playerChoice != 'r')) {
				cout << "You must enter R or H" << endl << "\t(R)oll again or (H)old? ";
				cin >> playerChoice;
				playerChoice = tolower(playerChoice);
			}
		}
		if (playerChoice == 'h') break;
	}
	userScore += pot;
	cout << endl << endl;
	return userScore;
}

int aiTurn(int aiScore) {   //ai turn, runs until pot is 20 or greater or busts, adds pot to the ai score
	int roll = 0;
	int pot = 0;
	char playerChoice;

	cout << "AI's Turn" << endl;
	while ((roll != 1) && (pot < 20)) {
		roll = diceRoll();
		if (roll == 1) {
			cout << "Die Roll : BUST" << endl;
			pot = 0;
		}
		else {
			pot += roll;
			cout << "Die Roll : " << roll << "     Pot : " << pot << endl;
			if ((aiScore + pot) >= 50) break;
		}
	}
	aiScore += pot;
	cout << endl << endl;
	return aiScore;
}

void printScore(int userScore, int aiScore) {  //prints of the scores of the player and ai
	cout << "Score\tYou : " << userScore << "\tAI: " << aiScore << endl << endl;
}

int main() {
	srand(time(NULL));
	int play = 1;
	int userScore = 0;
	int aiScore = 0;
	char keepPlay;

	while (play == 1) {
		printScore(userScore, aiScore);
		userScore = playerTurn(userScore);   //the user score is added after the turn is ran 

		if (userScore >= 50) {   //if a player wins they will be declared the winner and asked to play again
			printScore(userScore, aiScore);
			cout << "You are the winner!" << endl << "Would you like to play again (Y or N)?";
			cin >> keepPlay;
			keepPlay = tolower(keepPlay);
			while ((keepPlay != 'y') && (keepPlay != 'n')) {
				cout << "You must enter Y or N" << endl << "\tDo you want to play again (Y or N)? ";
				cin >> keepPlay;
				keepPlay = tolower(keepPlay);
			}
			userScore = 0;
			aiScore = 0;
			if (keepPlay == 'n') break;
			cout << endl;
		}

		printScore(userScore, aiScore);
		aiScore = aiTurn(aiScore);   //the ai score is added after the turn is ran

		if (aiScore >= 50) {   //if the ai wins they will be declared the winner and asked to play again
			printScore(userScore, aiScore);
			cout << "AI is the winner!" << endl << "Would you like to play again (Y or N)?";
			cin >> keepPlay;
			keepPlay = tolower(keepPlay);
			while ((keepPlay != 'y') && (keepPlay != 'n')) {
				cout << "You must enter Y or N" << endl << "\tDo you want to play again (Y or N)? ";
				cin >> keepPlay;
				keepPlay = tolower(keepPlay);
			}
			userScore = 0;
			aiScore = 0;
			if (keepPlay == 'n') break;
			cout << endl;
		}
	}

	return 0;
}
