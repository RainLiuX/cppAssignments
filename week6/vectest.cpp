#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

struct coor {
		int * x;
		int y;
		coor(int * x_, int y_) {
			x = x_;
			y = y_;
		}
	};
void func(vector<coor> *);
bool less_than(coor & c, coor & d);
int main () {
	vector<coor> * vec = new vector<coor>;
	func(vec);
	int a[1000] = { 0 };
	cout << "x " << (*vec)[0].x[2] << " y " << (*vec)[0].y << endl;
	sort(vec->begin(), vec->end(), less_than);
	cout << (*vec)[0].y << " " << (*vec)[1].y;
} 
void func(vector<coor> * vec) {
	int x[300000] = {0, 1, 2};
	coor c(x, 6);
	vec->push_back(c);
	int y[3] = {1, 2, 3};
	coor d(y, 4);
	vec->push_back(d);
	for (int i = 0; i < 5; i++)
		vec->push_back(c);
}

bool less_than(coor & c, coor & d) {
	return c.y <= d.y;
}
