#include <iostream>

class SavingsAccount {
private:
	float savingBalance;
public:
	SavingsAccount();
	SavingsAccount(float b): savingBalance(b) { };
	float calculateMonthlyInterest() {
		return savingBalance += annualInterestRate * savingBalance / 12;
	}
	static float annualInterestRate;
	static void modifyInterestRate(float r) {
		annualInterestRate = r;
	}
}; 
float SavingsAccount::annualInterestRate;

int main() {
	using namespace std;
	SavingsAccount saver1(2000.0), saver2(3000.0);
	SavingsAccount::modifyInterestRate(0.04);
	cout << saver1.calculateMonthlyInterest() << " " << saver2.calculateMonthlyInterest() << endl;
	SavingsAccount::modifyInterestRate(0.05);
	cout << saver1.calculateMonthlyInterest() << " " << saver2.calculateMonthlyInterest() << endl;
	return 0;
}
