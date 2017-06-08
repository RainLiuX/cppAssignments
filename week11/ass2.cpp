#include <iostream>
#include <cstring>
#include <cstdio>

class TicTacToe {
private:
	int board[3][3];
	int turn;
	void changeSide();
	bool check(int x, int y);
	bool isWin();
	void display();
public:
	TicTacToe();
	void down(int x, int y);
	void init();
}; 

TicTacToe::TicTacToe(): turn(2) {
	memset(board, 0, sizeof(board));
}

void TicTacToe::init() {
	using namespace std;
	do {
		display();
		changeSide();
		int x, y;
		while(1) {
			cin >> x >> y;
			if(!check(x, y)) {
				down(x, y);
				break;
			} else {
				cout << "Invalid!" << endl;
			}
		}
	} while(!isWin());
	display();
	cout << turn << ", You win!" << endl;
}

void TicTacToe::display() {
	printf("\n%d | %d | %d\n", board[0][0], board[0][1], board[0][2]);
	printf("----------\n");
	printf("%d | %d | %d\n", board[1][0], board[1][1], board[1][2]);
	printf("----------\n");
	printf("%d | %d | %d\n\n", board[2][0], board[2][1], board[2][2]);
}

void TicTacToe::changeSide() {
	turn = turn == 1 ? 2 : 1;
}

bool TicTacToe::check(int x, int y) {
	return board[y - 1][x - 1] || !(x > 0 && x < 4) || !(y > 0 && y < 4);
}

void TicTacToe::down(int x, int y) {
	board[y - 1][x - 1] = turn;
}

bool TicTacToe::isWin() {
	for(int i = 0; i < 3; i++) {
		bool hasInLine = 0;
		for(int j = 0; j < 3; j++) {
			hasInLine = hasInLine || board[i][j];
		}
		if(!hasInLine) return 0;
	}
	for(int i = 0; i < 3; i++) {
		bool hasInLine = 0;
		for(int j = 0; j < 3; j++) {
			hasInLine = hasInLine || board[j][i];
		}
		if(!hasInLine) return 0;
	}
	return 1;
}

int main() {
	TicTacToe t;
	t.init();
	return 0;
}
