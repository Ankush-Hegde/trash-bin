#include <iostream>
#include "calc.h"
using namespace std;
int main()
{
	int a,b;
	double c,d;
	cout<<"1.add \n 2.sub \n 3.mul \n 4.div \n";
	cout<<"select the option\n"<<endl;
	cin>>a;
	switch (a){
		case 1:int ea;
cout<<"----------------------------------------------------------------------\n";
		       cout<<"1.add two intigers\n2.add three intigers\n3.add doubles\n";
		       cout<<"----------------------------------------------------------------------\n";
		       cout<<"enter your choice\n";
		       cin>>ea;
		       switch (ea){
			       case 1:
			       cout<<"----------------------------------------------------------------------\n";
			              cout<<"enter two numbers\n";
				      int p,q;
				      cin>>q>>p;
				      cout<<add(p,q)<<endl;
				      cout<<"----------------------------------------------------------------------\n";
				break;
			       case 2:
			       cout<<"---------------------------------------------------------------------\n";			 
			       cout<<"enter three numbers\n";
			int x,y,z;
			cin>>x>>y>>z;
			cout<<add(x,y,z)<<endl;
			cout<<"----------------------------------------------------------------------\n";
			break;
			       case 3:
			       cout<<"----------------------------------------------------------------------\n";
			       cout<<"enter doubles\n";
				      double n,o,r;
				      cin>>n>>o;
				      cout<<add(n,o)<<endl;
				      cin>>r;
				      cout<<add(n,o,r)<<endl;
				      cout<<"----------------------------------------------------------------------\n";
				      break;
			       default:cout<<"invalid choice\n";
				      break;
		       }
		       break;
		  case 2:int eb;
		  cout<<"----------------------------------------------------------------------\n";
  	          cout<<"1.sub two intigers\n2.sub three intigers\n3.sub doubles\n";
  	          cout<<"enter your choice\n";
     	          cin>>eb;
   	          switch (eb){
	          case 1:
	          cout<<"----------------------------------------------------------------------\n";
	          cout<<"enter two numbers\n";
				      int f,g;
				      cin>>f>>g;
				      cout<<sub(f,g)<<endl;
				      cout<<"----------------------------------------------------------------------\n";
				break;
			       case 2:
			       cout<<"----------------------------------------------------------------------\n";
			       cout<<"enter three numbers\n";
			int h,i,j;
			cin>>h>>i>>j;
			cout<<sub(h,i,j)<<endl;
			cout<<"----------------------------------------------------------------------\n";
			break;
			       case 3:
			       cout<<"----------------------------------------------------------------------\n";
			       cout<<"enter doubles\n";
				      double k,l,m;
				      cin>>k,l;
				      cout<<sub(k,l)<<endl;
				      cin>>m;
				      cout<<sub(k,l,m)<<endl;
				      cout<<"----------------------------------------------------------------------\n";
				      break;
			       default:cout<<"invalid choice\n";
				       break;
		  } 
		  break;
	    case 3:int ec;
	    cout<<"----------------------------------------------------------------------\n";
		       cout<<"1.mul two intigers\n2.mul three intigers\n3.mul doubles\n";
		       cout<<"enter your choice\n";
		       cin>>ec;
		       switch (ec){
			       case 1:
			       cout<<"----------------------------------------------------------------------\n";
			       cout<<"enter two numbers\n";
				      int s,t;
				      cin>>s>>t;
				      cout<<mul(s,t)<<endl;
				      cout<<"----------------------------------------------------------------------\n";
				break;
			       case 2:
			       cout<<"----------------------------------------------------------------------\n";
			       cout<<"enter three numbers\n";
			int u,v,w;
			cin>>u>>v>>w;
			cout<<mul(u,v,w)<<endl;
			cout<<"----------------------------------------------------------------------\n";
			break;
			       case 3:
			       cout<<"----------------------------------------------------------------------\n";
			       cout<<"enter doubles\n";
				      double x1,y1,z1;
				      cin>>x1>>y1;
				      cout<< mul(x1,y1)<<endl;
				      cin>>z1;
				      cout<<mul(x1,y1,z1)<<endl;
				      cout<<"----------------------------------------------------------------------\n";
				      break;
			       default:"invalid choice\n";
		       }
		       break;

		case 4:
		cout<<"----------------------------------------------------------------------\n";
		cout<<"enter first number\n";
		       cin>>c;
		       cout<<"enter second number\n";
		       cin>>d;
		       if(d=0)
			       cout<<"enter a non zero number\n";
		       else
			       cout<<div(c,d)<<endl;
			       cout<<"----------------------------------------------------------------------\n";
		       break;
		default:"enter a valid option\n";
			break;
	}

}
