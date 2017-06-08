#include <iostream>
#include <iomanip>
#define PI 3.1416

class Point {
private:
	int x, y;
public:
	Point(): x(0), y(0) { }
	Point(int _x, int _y): x(_x), y(_y) { }
	void setPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void print() { std::cout << "x: " << x << " y: " << y << std::endl; }
};

class Circle {
private:
	Point center;
	float radius;
public:
	Circle(): center(Point()), radius(0.0f) { }
	Circle(Point point, float r): center(point), radius(r) { }
	Circle(int x, int y, float r): center(Point(x, y)), radius(r) { }
	void setRadius(float r) { radius = r; }
	void setCenter(Point point) { center = point; }
	float getRadius() { return radius; }
	Point getCenter() { return center; }
	float area() { return PI * radius * radius; }
	void print() {
		std::cout << "radius: " << radius << " ";
		center.print();
	}
};

int main() {
	using namespace std;
	Circle circle(100, 90, 15);
	circle.print();
	cout << fixed << setprecision(3) << circle.area() << endl;
	return 0;
}
