#include <iostream>
#include <vector>
#include "MatrixLib.hpp"
#include <string>
using namespace std;
int main(){
cout<<"int main has started \n";
       
//set up first matrix
cout<<"Matrix1 name: ";
string name1;
cin>>name1;
cout<<endl;
int a1; int b1;
cout<<"Give "<<name1<<" Dimensions\n";
cin>>a1>>b1;
matrix_init M1(a1,b1);

for(int i=0;i<a1;i++){
	for(int j=0;j<b1;j++){
		cout<<"taking input for "<<name1<<" ";
		double p;
		cin>>p;
		M1.setElement(i,j,p);
	}
}

//set up second matrix
cout<<"Matrix2 name: ";
string name2;
cin>>name2;
cout<<endl;
int a2; int b2;
cout<<"Give "<<name2<<" Dimensions\n";
cin>>a2>>b2;
matrix_init M2(a2,b2);

for(int i=0;i<a2;i++){
	for(int j=0;j<b2;j++){
	cout<<"taking input for "<<name2<<" ";
		double p;
		cin>>p;
		M2.setElement(i,j,p);
	}
}


//Executing operations
if(a1==a2&&b1==b2){
cout<<endl<<"performing operation addition"<<endl<<endl;
matrix_init out1=M1+M2;
out1.display();
}
else{cout<<"\n addition not possible";}

if(b1==a2){
cout<<endl<<"performing operation multiplication"<<endl<<endl;
matrix_init out2=M1*M2;
out2.display();
}
else{cout<<"multiplication not possible";}
return 0;
}

