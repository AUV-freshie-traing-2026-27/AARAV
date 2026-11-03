
#include "MatrixLib.hpp"



//Constructors
matrix_init::matrix_init(int m,int n){arr.resize(m,vector<double>(n));
	cout<<"matrix size set "<<arr.size()<<"*"<<arr[0].size()<<endl;}
matrix_init::matrix_init(vcc something){arr.swap(something);}



//set Functions
void matrix_init::setMatrix(vcc name){arr.swap(name);}
void matrix_init::setRow(int i,vector<double> val){arr[i].swap(val);}
void matrix_init::setColumn(int i,vector<double> val){for(int k=0;k<arr.size();k++){arr[k][i]=val[k];}cout<<1;}
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

	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[0].size();j++){
			cout<<" "<<arr[i][j];
		}
		cout<<"\n";
	}
}
//Matrix operations

vcc addMatrix(vcc A,vcc B){
	matrix_init p(A);
       
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			p.setElement(i,j,A[i][j]+B[i][j]);
			
		}
		
	}
	return p.getMatrix();
}


vcc multiplyMatrix(vcc A,vcc B){
  vcc p(A.size(),vector<double>(B[0].size()));

 for(int i=0;i<A.size();i++){
	for(int j=0;j<B[0].size();j++){
	       double sum=0;
       		for(int k=0;k<A[0].size();k++){
	 sum=sum+A[i][k]*B[k][j];		
		}
	p[i][j]=sum;
	}
 }
return p;
}

//Convienice functions
void addVector(vector<double>& A,vector<double> B){
	if((A).size()!=B.size()){cout<<"Vector cannot be added \n";}
	else{for(int i=0;i<(A).size();i++){A[i]=(A[i]+B[i]);}}
}

void multVector(vector<double>& A,vector<double> B){
	if(A.size()!=B.size()){cout<<"Vectors cannot be multiplied";}
	else{for(int i=0;i<A.size();i++){A[i]=(A[i]*B[i]);}}

}
void multVector(vector<double>& A,double B){
	for(int i=0;i<A.size();i++){A[i]=(A[i]*B);}

}

//Matrix inversion
matrix_init matrix_init::Identity(){

if(arr.size()!=arr[0].size()){cout<<"\n matrix is not square\n ";}
else{
matrix_init p(arr.size(),arr.size());
for(int i=0;i<arr[0].size();i++){
        for(int j=0;j<arr[0].size();j++){
                if(i==j){p.setElement(i,j,1);}
                else{p.setElement(i,j,0);}
                }

        }
return p;   }
}

void matrix_init::invert(matrix_init& M){
try{    if(arr.size()!=arr[0].size()){ throw 345; }
	else{
	for(int i=0;i<arr.size();i++){
		for(int k=0;k<arr.size();k++){
			if(k<i){  }
			else if(k==i){
		 		if(arr[k][i]==0){throw 000; }
				else if(arr[k][i]!=1){multVector(arr[k],1/arr[k][i]);}		
			}
			else if(k>i){
				if(arr[k][i]!=0){
				vector<double> p=arr[i];
				multVector(p,arr[k][i]);
				multVector(p,-1);
				addVector(arr[k],p);}
				M.display();cout<<endl;
			}
	       }
	}
}
}catch(int myNum){
	cout<<"Error : "<<myNum<<endl;
	if(myNum==345){cout<<"Matrix is not square, inverse does not existi\n";}
	else{cout<<"Matirx not invertible, determinant is zero";}
	}
}









