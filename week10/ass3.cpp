#include <iostream> 
#include <cmath>

int fph(int);
int tph(int);
int main()
{
	using namespace std;
	int n;
	cin>>n;
	while (n){
		cout<<fph(n)%10000<<endl;
		cin>>n;}
	return 0;
}
int fph(int n)
{
	if(n==1)
		return 1;
	else{
		int x=0,tmp;
		for(int k=1;k<n;k++){
			tmp=2*fph(k)+tph(n-k);
			if(x==0||x>tmp)
				x=tmp;
		}
		return x;
	}
}
int tph(int n)
{
	return pow(2,n)-1;
}
