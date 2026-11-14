#include <iostream>
#include "MatrixLib.hpp"



int main(){

matrix_init kay({ {1,1,1} , {4,3,-1} , {3,5,3} });
vector<double> rhs={ 14 , 14 , 17 };
vector<double> answer = getX(kay.getMatrix(),rhs);
for(int i=0;i<3;i++){cout<<answer[i]<<endl;}

}
