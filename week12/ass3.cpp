#include <iostream>
#include <cstring>
#include <string>
#define BOARD_SIZE 20
#define MAX_INSTRUCTION 64
#define MIN(a, b) (a > b) ? b : a
#define MAX(a, b) (a > b) ? a : b
const char splash[] = 
	"Turtle\n"
	"Author: Randolph Liu 2017/06/03\n"
	"###############################\n"
	"Command: \n1 pen up \n2 pen down \n3 turn right \n4 turn left \n5 n move forward n step"
	"\n6 display \n9 end command\n"
	"###############################\n"
	"Display: \n¡ð turtle with pen up \n¡ñ turtle with pen down \n¡ö trace \n¡õ empty board\n"
	"###############################\n";

class Turtle {
public:
	Turtle(): x(0), y(0), direction(right) { }
	void turnLeft() {
		direction = Direction(direction == 0 ? 3 : direction - 1);
	}
	void turnRight() {
		direction = Direction((direction + 1) % 4);
	}
	int getX() { return x; }
	int getY() { return y; }
	void go(int dist);
private:
	int x;
	int y;
	enum Direction { up, right, down, left } direction;
};

void Turtle::go(int dist) {
	int preX = x, preY = y;
	switch(direction) {
		case up:
			y -= dist;
			break;
		case right:
			x += dist;
			break;
		case down:
			y += dist;
			break;
		case left:
			x -= dist;
			break;
	}
	if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
		std::cout << "Bad command!" << std::endl;
		x = preX;
		y = preY;
	}
}

class Canvas {
public:
	Canvas(): pen(up) {
		memset(board, 0, sizeof(board));
		turtle = new Turtle;
	}
	void penUp() {
		pen = up;
	}
	void penDown() {
		pen = down;
	}
	void begin(int command);
private:
	int board[BOARD_SIZE][BOARD_SIZE];
	enum Pen{ up, down} pen;
	Turtle* turtle;
	void display();
};

void Canvas::begin(int command) {
	switch(command) {
		case 1:
			penUp();
			break;
		case 2:
			penDown();
			break;
		case 3:
			turtle->turnRight();
			break;
		case 4:
			turtle->turnLeft();
			break;
		case 5: {
				int distance;
				std::cin >> distance;
				int preX = turtle->getX(), preY = turtle->getY();
				turtle->go(distance);
				int x = turtle->getX(), y = turtle->getY();
				int minX = MIN(preX, x), maxX = MAX(preX, x), minY = MIN(preY, y), maxY = MAX(preY, y);
				if (pen) {
					for(int j = minY; j <= maxY; j++)
						for (int k = minX; k <= maxX; k++)
							board[j][k] = 1;
			}
			break;
		}
		case 6:
			display();
			break;
		default:
			std::cout << "Bad command!" << std::endl;
	}
}

void Canvas::display() {
	using namespace std;
	int x = turtle->getX(), y = turtle->getY();
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (i == y && j == x)
				if(pen) cout << "¡ñ";
				else cout << "¡ð";
			else if (board[i][j]) cout << "¡ö";
			else cout << "¡õ";
		} 
		cout << endl;
	}
}

int main() {
	using namespace std;
	cout << splash;
	Canvas canvas;
	while(1) {
		int command;
		cin >> command;
		if(!cin.good()) {
			cout << "Bad command!" << endl;
			cin.clear();
			cin.sync();
		} else if(command == 9)
			return 0;
		else
			canvas.begin(command);
	}
}
