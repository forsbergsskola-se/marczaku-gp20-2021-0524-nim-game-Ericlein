#include <iostream>
#include <string>
#include<limits>
using namespace std;

const int startingMatches = 24;

void printMatches(int matchesAmount) {
	for (int i = 0; i < matchesAmount; i++) {
		cout << "|";
	}
}
bool inputCheck(string value) {
	string input;
	cin >> input;
	return input == value;
}

int drawMatches(int player, int matchesLeft) {
	while (true) {
		printMatches(matchesLeft);
		cout << "\nThere is " << matchesLeft << " matches left." << endl;
		cout << "Player " + to_string(player) + ", please draw 1, 2 or 3 matches" << endl;
		int playerDraw;
		cin >> playerDraw;
		if (!cin || playerDraw > 3 || playerDraw < 1) {
			cout << "Invalid amount. Pick a number between 1 and 3 to draw." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (playerDraw > matchesLeft) {
			cout << "Invalid amount. Only " + to_string(matchesLeft) + " matches left" << endl;
		}
		else {
			return playerDraw;
		}
	}
}

int nextPlayer(int player) {
	// condition ? result 1 : result 2
	return player == 1 ? 2 : 1;
}

int aiDrawMatches(int matchesLeft) {
	int value = matchesLeft % 4;
	cout << "Player 2 picked " + to_string(value) << " matches." << endl;
	return value;
}

int main() {
	cout << "Welcome to the Game of Nim" << endl;
	cout << "Would you like to play Single player or Multiplayer?\nWrite 1 or 2" << endl;
	while (true){
		int matches = startingMatches;
		int currentPlayer = 0;
		bool singlePlayer = inputCheck("1");
		while (matches > 0) {
			currentPlayer = nextPlayer(currentPlayer);
			if (singlePlayer && currentPlayer == 2) {
				matches -= aiDrawMatches(matches);
			}
			else {
				matches -= drawMatches(currentPlayer, matches);
			}
		}
		cout << "Player " + to_string(currentPlayer) + " won!" << endl;
	}
	cout << "Thanks for playing!" << endl;
	return 0;
}