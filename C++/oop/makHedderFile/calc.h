#include <iostream>
using namespace std;

int add(int a,int b){
	return (a+b);
}

int add(int a,int b,int c){
	return (a+b+c);
}

double add(double a,double b=0,double c=0){
	return (a+b+c);
}

int sub(int a,int b){
	return(a-b);
}

int sub(int a,int b,int c){
	return(a-b-c);
}

double sub(double a,double b=0,double c=0){
	return(a-b-c);
}

/*int mul(int a,int b){
	return(a*b);
}*/

int mul(int a,int b=1,int c=1){
	return(a*b*c);
}

double mul(double a,double b=1,double c=1){
	return (a*b*c);
}

double div(double a,double b){
	return(a/b);
}
