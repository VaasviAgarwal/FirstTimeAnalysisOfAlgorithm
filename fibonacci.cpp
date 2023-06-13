#include <iostream>
using namespace std;

int fib(int n)
{
	if(n==0||n==1)
	{
		return n;
	}
	return (fib(n-1)+fib(n-2));
}

int main()
{
	int n;
	int i;
	cout<<"Enter the number of terms in fibonacci series : ";
	cin>>n;
	cout<<"Fibonacci Series :  ";
	for(i=0;i<n;i++)
	{
		cout << " " <<fib(i);
	}
	cout<<endl;
	return 0;
}
