#include <iostream>
#include <vector>		

using namespace std;
using vcc =vector<vector<double>>;

	vcc addMatrix(vcc A,vcc B);
	vcc multiplyMatrix(vcc A,vcc B);	
	void invertMatrix(vcc A);


class matrix_init{
public:
	vcc arr ;
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


	matrix_init operator+ (const matrix_init rhs) 
	{
	 return matrix_init(addMatrix(arr,rhs.arr));
	}

	matrix_init operator* (const matrix_init rhs)
	{
	return matrix_init(multiplyMatrix(arr,rhs.arr));
	}
};


