#ifndef MATRIXLIB_H
#define MATRILIB_H

#include <iostream>
#include <vector>		

using namespace std;
using vcc =vector<vector<double>>;
//Matrix operations and COnvenience functions
	vcc addMatrix(vcc A,vcc B);
	vcc multiplyMatrix(vcc A,vcc B);	
	void addVector(vector<double>& A, vector<double> B);
	void multVector(vector<double>& A,vector<double> B);
	void multVector(vector<double>& A,double B);

class matrix_init{
public:
	vcc arr ;
	//constructors
	matrix_init(int m,int n);
	matrix_init(vcc something);

   	//set functions
      void setMatrix(vcc name);
     void setRow(int i,vector<double> val);
    void setColumn(int i,vector<double> val);
   void setElement(int i,int j, double val); 



       //get functions
	vcc getMatrix();
	vector<double> getRow(int i);
	vector<double> getColumn(int i);
	double getElement(int i,int j);
	void display();

	//matrix operations
	matrix_init operator+ (const matrix_init rhs) 
	{
	 return matrix_init(addMatrix(arr,rhs.arr));
	}

	matrix_init operator* (const matrix_init rhs)
	{
	return matrix_init(multiplyMatrix(arr,rhs.arr));
	}

//Inverse
vcc Identity();
void invert();
};

#endif
