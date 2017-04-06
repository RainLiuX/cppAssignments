#include <iostream>

void myswap(int a[10][3], int b[10][3]);
int main()
{
	using namespace std;
	int grades[10][3];
	int n;
	cin>>n;
	for(int i =0; i<n; i++)
	{
		cin>>grades[i][0]>>grades[i][1]>>grades[i][2];
	}
	int subject;
	cin>>subject;
	for (int i = 0; i <n-1; i++)
		for(int j = n-1; j>i; j --)
			if (grades[j][subject] > grades[j-1][subject])
				myswap(grades+j, grades+j-1);
				
	for(int i=0; i<n; i++)
	{
		cout<<grades[i][0]<<" "<<grades[i][1]<<" "<<grades[i][2]<<endl;
	}
}

void myswap(int a[10][3], int b[10][3])
{
	int temp[3];
	for(int i =0; i<3; i++)
	{
		temp[i] = a[0][i];
		a[0][i] = b[0][i];
		b[0][i] = temp[i];
	}
}
