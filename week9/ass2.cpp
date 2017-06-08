#include <iostream>
#include <iomanip>
#define PI 3.1416

class Point {
public:
	void setPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void print() {
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
private:
	int x, y;
};

class Circle {
public:
	void setRadius(int r) { radius = r; }
	void setCenter(Point c) { center = c; }
	double getRadius() { return radius;}
	Point getCenter() { return center; }
	double area() { return PI * radius * radius; }
	void print() {
		std::cout << "center: ";
		center.print();
		std::cout << "radius: " << radius << std::endl;
	}
private:
	double radius;
	Point center;
};

int main() {
	using namespace std;
	Circle c1;
	int x, y;
	double r;
	cin >> x >> y >> r;
	Point c;
	c.setPoint(x, y);
	c1.setCenter(c);
	c1.setRadius(r);
	c1.print();
	cout << setiosflags(ios::fixed) << setprecision(3) << c1.area() << endl;
}
