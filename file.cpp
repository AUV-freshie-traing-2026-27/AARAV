#include "iostream"
#include <vector>
#include "MatrixLib.hpp"


int main(){

int a; int b;
cout<<"Give Matrix Dimensions\n";
a=3;b=3;
matrix_init M(a,b);
int k=1;
for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
                cout<<"taking input for matrix ";
                M.setElement(i,j,k);k++;
        }
}
M.setElement(2,2,10);
cout<<endl<<endl;
M.display();
cout<<endl<<endl;
M.invert(M);
cout<<endl<<endl;
M.display();
return 0;
}
