#include <iostream>
using namespace std;

char gameBoard[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';
int fullBoard;

void PrintBoard(){
	system("cls");
	cout << "Welcome to Tic Tac Toe" << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << gameBoard[i][j] << " ";
		}
		cout << endl;
	}
}

void TogglePlayer(){
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

void movePlayer(){
	int playerInput;
	cout << "It's " << player << " turn. " << "Please pick a slot: ";
	cin >> playerInput;

	if (playerInput == 1){
		if (gameBoard[0][0] == '1')
			gameBoard[0][0] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 2){
		if (gameBoard[0][1] == '2')
			gameBoard[0][1] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 3){
		if (gameBoard[0][2] == '3')
			gameBoard[0][2] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 4){
		if (gameBoard[1][0] == '4')
			gameBoard[1][0] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 5){
		if (gameBoard[1][1] == '5')
			gameBoard[1][1] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 6){
		if (gameBoard[1][2] == '6')
			gameBoard[1][2] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 7){
		if (gameBoard[2][0] == '7')
			gameBoard[2][0] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 8){
		if (gameBoard[2][1] == '8')
			gameBoard[2][1] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
	else if (playerInput == 9){
		if (gameBoard[2][2] == '9')
			gameBoard[2][2] = player;
		else{
			cout << "Slot is already in use try again!" << endl;
			movePlayer();
		}
	}
}

char CheckWin(){
	if (gameBoard[0][0] == 'X' && gameBoard[0][1] == 'X' && gameBoard[0][2] == 'X')
		return 'X';
	if (gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X')
		return 'X';
	if (gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X')
		return 'X';

	if (gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X')
		return 'X';
	if (gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X')
		return 'X';
	if (gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X')
		return 'X';

	if (gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X')
		return 'X';
	if (gameBoard[2][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[0][2] == 'X')
		return 'X';

	if (gameBoard[0][0] == 'O' && gameBoard[0][1] == 'O' && gameBoard[0][2] == 'O')
		return 'O';
	if (gameBoard[1][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[1][2] == 'O')
		return 'O';
	if (gameBoard[2][0] == 'O' && gameBoard[2][1] == 'O' && gameBoard[2][2] == 'O')
		return 'O';

	if (gameBoard[0][0] == 'O' && gameBoard[1][0] == 'O' && gameBoard[2][0] == 'O')
		return 'O';
	if (gameBoard[0][1] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][1] == 'O')
		return 'O';
	if (gameBoard[0][2] == 'O' && gameBoard[1][2] == 'O' && gameBoard[2][2] == 'O')
		return 'O';

	if (gameBoard[0][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O')
		return 'O';
	if (gameBoard[2][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[0][2] == 'O')
		return 'O';

	return '/';
}
int main(){
	fullBoard = 0;
	PrintBoard();
	while (true){
		fullBoard++;
		movePlayer();
		PrintBoard();
		if (CheckWin() == 'X'){
			cout << "X wins!" << endl;
			break;
		}
		else if (CheckWin() == 'O'){
			cout << "O wins!" << endl;
			break;
		}
		else if (CheckWin() == '/' && fullBoard == 9){
			cout << "It's a draw!" << endl;
			break;
		}
		TogglePlayer();
	}
	return 0;
}