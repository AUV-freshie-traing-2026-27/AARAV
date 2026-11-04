#include "iostream"
#include <vector>
#include "MatrixLib.hpp"


int main(){

int a; int b;
cout<<"Give Matrix Dimensions\n";
cin>>a>>b;
matrix_init M(a,b);
int k=1;
for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
                cout<<"taking input for matrix ";
               double k;cin>>k;
		M.setElement(i,j,k);
	}
}
cout<<endl<<endl;
M.display();
cout<<endl<<endl;
M.invert();
cout<<endl<<endl;
M.display();
return 0;
}
