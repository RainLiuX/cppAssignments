#include <iostream>
using namespace std;

class Test {
public:
	static int num;
	static void showNum() {
		cout << ++num << endl;
	}
	void incNum() {
		num++;
	}
};
int Test::num = 0;

int main() {
	for (int i = 0; i < 10; i++)
		Test::showNum();
	cout << Test::num;
	return 0;
} 
