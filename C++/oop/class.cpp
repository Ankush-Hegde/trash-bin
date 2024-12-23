
#include<iostream>
#include<string.h>
using namespace std;

//"class" and "struct" are same but difference is struct is by default public and class is by default private i.e you cannot acess data member outside the class
class student{
	int usn;
	char name[10];

	public:
	void read(){
	       cout<<"enter the usn: "<<endl;
	       cin>>usn;
	       cout<<"enter name: "<<endl;
	       cin>>name;
	}

	void display(){
		cout<<"---------------------------------------------------"<<endl;
		cout<<"details are"<<endl<<usn<<endl;
		cout<<name<<endl;
		cout<<"---------------------------------------------------"<<endl;
	}
};

int main(){
	student s1;
	s1.read();
	s1.display();

	student s2;
	s2.read();
	s2.display();

	return 0;
}
