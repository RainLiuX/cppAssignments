#include <iostream>
#include <cstring>

const char* monthString[] = {
	"January", "Febuary", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

const int monthDay[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const char* errorHint = "Bad Date info!\n";

class Date {
private:
	int month, day, year;
	void check(bool ok = true);
	bool isLeap(int y);
public:
	Date(): month(1), day(1), year(1900) { }
	Date(int m, int d, int y): month(m), day(d), year(y) {
		check();
	}
	Date(const char* m, int d, int y);
	Date(int d, int y);
	void show1() {
		std::cout << month <<"/" << day << "/" << year << std::endl;
	}
	void show2() {
		std::cout << monthString[month - 1] << " " << day << "," << year << std::endl;
	}
	void show3();
};

Date::Date(const char* m, int d, int y) {
	int i;
	for(i = 0; i < 12; i++)
		if(!strcmp(m, monthString[i])) {
			month = i + 1;
			break;
		}
	if(i == 12) 
		check(false);
	else {
		day = d;
		year = y;
		check();
	}
}

Date::Date(int d, int y) {
	int sum = 0, i;
	for(i = 0; i < 12; i++) {
		int preSum = sum;
		sum += monthDay[i];
		if(i == 1 && isLeap(y)) sum++;
		if(sum > d) {
			month = i + 1;
			day = d - preSum;
			break;
		}
	}
	if(i == 12)
		check(false);
	else {
		year = y;
		check();
	}
}

bool Date::isLeap(int y) {
	return !(y % 4) && (y % 100) || !(y % 400);
}
void Date::check(bool ok) {
	using namespace std;
	if(ok == false)
		cout << errorHint;
	if(month < 1 || month > 12) {
		cout << errorHint;
		ok = false;
	}
	if(month == 2) {
		if(ok && (day < 1 || day > 29)) {
			cout << errorHint;
			ok = false;
		}
	} else {
		if(ok && (day < 1 || day > monthDay[month - 1])) {
			cout << errorHint;
			ok = false;
		}
	}
	if(!ok) {
		year = 1900;
		month = 1;
		day = 1;
	}
}

void Date::show3() {
	int sum;
	for(int i = 0; i < month - 1; i++) {
		if(i == 1 && isLeap(year)) sum++;
		sum += monthDay[i];
	}
	sum += day;
	std::cout << sum << " " << year << std::endl;
}

int main() {
	Date date1;
	Date date2(6, 4, 2017);
	Date date3("June", 14, 1992);
	Date date4(61, 2008);
	date1.show1();
	date2.show2();
	date3.show2();
	date4.show3();
	date4.show2();
	return 0;
}
