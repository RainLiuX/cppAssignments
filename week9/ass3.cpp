#include <iostream>
#define PI 3.1416

class Ellipse {
public:
	void initial(int x1, int y1, int x2, int y2) {
		topLeftPoint = new Point(x1, y1);
		bottomRightPoint = new Point(x2, y2);
	}
	void getPosition(int& x1, int& y1, int& x2, int& y2) {
		x1 = topLeftPoint->x;
		y1 = topLeftPoint->y;
		x2 = bottomRightPoint->x;
		y2 = bottomRightPoint->y;
	}
	double area() {
		return PI * (bottomRightPoint->x - topLeftPoint->x) * (bottomRightPoint->y - topLeftPoint->y) / 4;
	}
private:
	struct Point {
		int x, y;
		Point(int _x, int _y): x(_x), y(_y) { }
	} *topLeftPoint, *bottomRightPoint;
};

int main() {
	using namespace std;
	Ellipse e;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	e.initial(x1, y1, x2, y2);
	cout << e.area() << endl;
	return 0;
}
