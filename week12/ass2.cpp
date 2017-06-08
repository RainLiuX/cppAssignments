#include <iostream>

class Account {
public:
	Account(): balance(0.0f) { }
	Account(float b) {
		setBalance(b);
	}
	void setBalance(float b);
	virtual void credit(float a);
	virtual void debit(float a);
	inline float getBalance() { return balance; }
private:
	float balance;
}; 

void Account::setBalance(float b) {
	if (b < 0.0f) {
		std::cout << "Invalid negtive initial balance!" << std::endl;
		balance = 0.0f;
	} else {
		balance = b;
	}
}

void Account::credit(float a) {
	balance += a;
}

void Account::debit(float a) {
	float tmp = balance - a;
	if (tmp < 0.0f) {
		std::cout << "Debit amount exceed account balance" << std::endl
			<< "Dibit refused!" << std::endl;
	} else {
		balance = tmp;
	}
}

class SavingsAccount: public Account {
public:
	SavingsAccount();
	SavingsAccount(float b, float i):
		Account(b), interest(i) { }
	inline float calculateInterest() {
		return interest * getBalance();
	}
private:
	float interest;
};

class CheckingAccount: public Account {
public:
	CheckingAccount();
	CheckingAccount(float b, float p):
		Account(b), procedure(p) { }
	void credit(float a);
	void debit(float a);	
private:
	float procedure;
};

void CheckingAccount::credit(float a) {
	float tmp = getBalance() + a - procedure;
	if (tmp < 0.0f) {
		std::cout << "Procedule cost exceed account balance" << std::endl
			<< "Credit refused!" << std::endl;
	} else {
		setBalance(tmp);
	}
}

void CheckingAccount::debit(float a) {
	float tmp = getBalance() - a - procedure;
	if (tmp < 0.0f) {
		std::cout << "Debit or procedule cost exceed account balance" << std::endl
			<< "Dedit refused!" << std::endl;
	} else {
		setBalance(tmp);
	}
}

int main() {
	using namespace std;
	
	Account *acc[3];
	acc[0] = new Account(31.3);
	acc[1] = new SavingsAccount(6000.0, 0.025);
	acc[2] = new CheckingAccount(250.25, 11.5);
	cout << "acc0 is an Account with initial balance " << acc[0]->getBalance() << "$" << endl;
	cout << "acc1 is a SavingsAccount with initial balance " << acc[1]->getBalance() << "$" << " and interest 0.025" << endl;
	cout << "acc2 is a CheckingAccount with initial balance " << acc[2]->getBalance() << "$" << " and procedure cost 11.5$" << endl;
	
	cout << endl << "Crediting each account..." << endl;
	acc[0]->credit(1000.0);
	acc[1]->credit(50.0);
	acc[2]->credit(88.8);
	cout << "credit acc0 with 1000.0$\n"
		"credit acc1 with 50.0$\n"
		"credit acc2 with 88.8$\n";
	cout << "acc0 now has a balance of " << acc[0]->getBalance() << "$" << endl;
	cout << "acc1 now has a balance of " << acc[1]->getBalance() << "$" << endl;
	cout << "acc2 now has a balance of " << acc[2]->getBalance() << "$" << endl;
	
	cout << endl << "Debiting each account..." << endl;
	acc[0]->debit(2000.0);
	acc[1]->debit(50.0);
	acc[2]->debit(100.0);
	cout << "debit acc0 with 2000.0$\n"
		"debit acc1 with 50.0$\n"
		"debit acc2 with 100.0$\n";
	cout << "acc0 now has a balance of " << acc[0]->getBalance() << "$" << endl;
	cout << "acc1 now has a balance of " << acc[1]->getBalance() << "$" << endl;
	cout << "acc2 now has a balance of " << acc[2]->getBalance() << "$" << endl;
	
	cout << endl << "Checking acc1's interest..." << endl;
	cout << "acc1 has an interest of " << ((SavingsAccount*)acc[1])->calculateInterest() << "$" << endl;
	
	cout << endl << "Trying to initiate acc4 with negtive balance..." << endl;
	Account* acc4 = new Account(-0.1);
	return 0;
}
