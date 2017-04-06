#include <iostream>
using namespace std;

bool isprime(int);
int main()
{
	int n;
	while(cin>>n)
		if(isprime(n) && n) cout<<n<<' ';
}
bool isprime(int a)
{
	for(int i = 2; i < a; i++)
		if(!(a%i)) return false;
	return true;
}
