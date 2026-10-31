#include "MatrixLib.hpp"


using namespace matrix_operations;
using namespace matrix_init;
//Constructors
matrix(m,n){data.resize(m);for(int i=0;i<m;i++){data[i].resize(n);}
matrix(something){data.swap(something);}


//set Functions
void setMatrix(vector<vector<T>> name){data.swap(name);}
void setRow( i,val){data[i].swap(val[i]);}
void setColumn(i, val){for(int k=0;k<data.size()){data[k][i]=val[k];}
void setElement(i,j,val){data[i][j]=val;}


//get Functions	
vector<vector<T>> getMatrix(){return data;}
vector<T> getRow(int i){return data[i];}
vector<T> getColumn(int i){
	vector<T> p;
	for(int k=0;k<data.size();k++){p.pushback(data[k][i]);};
	return p;
	}
T matrix_init::getElement(i,j){return data[i][j];}




