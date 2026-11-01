#include "MatrixLib.hpp"



//Constructors
matrix_init::matrix_init(int m,int n){arr.resize(m,vector<double>(n));}
matrix_init::matrix_init(vcc something){arr.swap(something);}


//set Functions
void matrix_init::setMatrix(vcc name){arr.swap(name);}
void matrix_init::setRow(int i,vector<double> val){arr[i].swap(val);}
void matrix_init::setColumn(int i,vector<double> val){for(int k=0;k<arr.size();k++){arr[k][i]=val[k];}}
void matrix_init::setElement(int i,int j,double val){arr[i][j]=val;}


//get Functions	
vcc matrix_init::getMatrix(){return arr;}
vector<double> matrix_init::getRow(int i){return arr[i];}
vector<double> matrix_init::getColumn(int i){
	vector<double> p;
	for(int k=0;k<arr.size();k++){p.push_back(arr[k][i]);}
	return p;
	}
double matrix_init::getElement(int i,int j){return arr[i][j];}
void matrix_init::display(){
	for(vector<double> x : arr){
		for(double y:x){
			cout<<y<<",";
		}
		cout<<"}\n{";
	}
}


/*vcc matrix_operations::addMatrix(vcc A,vcc B){
	vcc p;
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			p[i][j]=A[i][j]+B[i][j];
		}
	}
	return p;
}


vcc matrix_operations::multiplyMatrix(vcc A,vcc B){*/
	




