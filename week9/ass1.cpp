#include <iostream>
#include <string>

class Person {
public:
	Person(): name(""), age(0), sex('m') {
		number++;
		index = number;
	}
	void Register(std::string n, int a, char s) {
		name = n;
		age = a;
		sex = s;
	}
	void ShowMe() {
		using namespace std;
		cout << "person"  << index << ": " << name << " " << age << " "
			<< sex << endl;
	}
	static int number;
private:
	std::string name;
	int age;
	char sex;
	int index;
}; 
int Person::number = 0;

int main() {
	using namespace std;
	Person person1, person2;
	string name;
	char sex;
	int age;
	cin >> name >> age >> sex;
	person1.Register(name, age, sex);
	person2.Register("Zhang3", 19, 'm');
	person1.ShowMe();
	person2.ShowMe();
}
