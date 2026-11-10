#include "MatrixLib.hpp"

//arr[k][i] k changes row i changes column

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
			cout<<arr[i][j]<<"\t";
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


void matrix_init::invert(){
//Identity Matrix
vcc arrcopy=arr;
vcc Iden(arr.size(),vector<double>(arr.size()));
try{
if(arr.size()!=arr[0].size()){cout<<"\n matrix is not square\n ";throw 345;}
else{
for(int i=0;i<arr[0].size();i++){
        for(int j=0;j<arr[0].size();j++){
                if(i==j){Iden[i][j]=1;}
                else{Iden[i][j]=0;}
                }

        }
}

//Row echelon form
    if(arr.size()!=arr[0].size()){arr=arrcopy;throw 345; }
	else{
	for(int i=0;i<arr.size();i++){ 
		for(int k=0;k<arr.size();k++){
			 if(k==i){
			if(arr[k][i]==0&&k==(arr.size()-1)){arr=arrcopy;throw 000; }      //if last diagonal elemnt is 0(others have been set 1)
			else if(arr[k][i]==0){int p=0;while(arr[p][i]==0){p++;} addVector(arr[k],arr[p]);}   //if diagonal element is zero
			else if(arr[k][i]!=1){double val=arr[k][i];multVector(arr[k],1/val);multVector(Iden[k],1/val);}
			}
			else if (k>i){
				if(arr[k][i]!=0){
				vector<double> p=arr[i];vector<double> s=Iden[i];
				multVector(p,arr[k][i]);multVector(s,arr[k][i]);
				multVector(p,-1);multVector(s,-1);
				addVector(arr[k],p);addVector(Iden[k],s);}
			}
/*	//Printing Between Changes              //Here
for(int i=0;i<arr.size();i++){
cout<<endl;
for(int j=0;j<arr.size();j++){cout<<arr[i][j]<<"\t";}
cout<<" | ";
for(int j=0;j<arr.size();j++){cout<<Iden[i][j]<<" ";}
}
//BaS IDHAR TAK                                //Here*/
		 }
	}
}

//Reduced Row echelon
for(int i=arr.size()-1;i>=0;i--){
	for(int k=0;k<arr.size();k++){
		if(k<i&&arr[k][i]!=0){
		vector<double> p=arr[i];vector<double> s=Iden[i];
		multVector(p,arr[k][i]);multVector(s,arr[k][i]);
		multVector(p,-1);multVector(s,-1);
		addVector(arr[k],p);addVector(Iden[k],s);
		 }	
	}
}
cout<<endl<<endl<<endl<<endl;
swap(arr,Iden);
}catch(int myNum){
	cout<<"Error : "<<myNum<<endl;
	if(myNum==345){cout<<"Matrix is not square, inverse does not existi\n";}
	else{cout<<"Matirx not invertible, determinant is zero\n";}
	}

}



                                                   //Linear Algebra


vector<double> getX(vcc A,vcc B)
{
try{
    if(A.size()!=A[0].size()){throw 000;}
    if(A.size()!=B.size()){throw 001;}
int l=A.size();
vcc L(l,vector<double> (l) );vector<double> X(l);vcc Acopy=A;


//initalise L
for(int i=0;i<l;i++){
	for(int k=0;k<l;k++){
	if(k<i){L[k][i]=0;}
	else if(k==i){L[k][i]=1;}
	}
}



    for(int i=0;i<A[0].size();i++){
    	for(int k=0;k<l;k++){
		 if(k==i){
			if(A[k][i]==0&&k==(l-1)){A=Acopy;throw 000; }      //if last diagonal elemnt is 0(others have been set 1)
			else if(A[k][i]==0){int p=0;while(A[p][i]==0&&p<l){p++;if(p==l){throw 002;}} addVector(A[k],A[p]);}//ifdiagonalelement is0
			}
 		else if(k>i)
		{
		vector<double> p=A[i];
		multVector(p,1/A[i][i]);
		double a=A[k][i];
		multVector(p,-a);
		L[k][i]=a;
		addVector(A[k],p);
		}
	}
    }
   }
catch(int myNum){
	if(myNum==000){cout<<"A is not square";}
	else if(myNum==001){cout<<"\n A and B dont have same rows\n";}
	
            }
}



