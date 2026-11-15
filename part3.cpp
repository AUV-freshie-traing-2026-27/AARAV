#include <iostream>
#include "MatrixLib.hpp"



int main(){

//matrix_init kay({ {1,1,1} , {4,3,-1} , {3,5,3} });
matrix_init kay({ {25,5,1} , {64,8,1} , {144,12,1} });
vector<double> rhs={106.8,177.2,279.2};
//vector<double> rhs={1,6,4};

kay.display();
cout<<endl;
vector<double> answer = getX(kay.getMatrix(),rhs);
for(int i=0;i<3;i++){cout<<answer[i]<<endl;}

}
