#include<iostream>
using namespace std;
int main()
{
	cout<<"enter the value "<<endl;
	int i;
	cin>>i;
	cout<<"the entered value is "<<i<<endl;
	int &ref=i;
	ref++;
	cout<<"after incrementing ref i is "<<i<<endl;
}
