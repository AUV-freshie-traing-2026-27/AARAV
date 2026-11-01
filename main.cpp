#pragma once
#include <iostream>
#include <vector>
#include "MatrixLib.hpp"

int main(){

int a; int b;
cin>>a>>b;
matrix_init M1(a,b);

for(int i=0;i<a;a++){
	for(int j=0;j<b;j++){
		double p;
		cin>>p;
		M1.setElement(i,j,p);
	}
}
M1.display();
return 0;
}

