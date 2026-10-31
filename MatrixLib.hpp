#include <iostream>
#include <vector>		

template <typename T>


class matrix_init{
private:
	vector<vector<T>> data[0][0] ;
	matrix(int m,int n){};
	matrix(vector<vector<T>> something){ };
public:
   	//set functions
      void setMatrix(vector<vector<T>> name){};
     void setRow(int i,vector<T> val){};
    void setColumn(int i,vector<T> val){};
   void setElement(int i,int j, T val){}; 



       //get functions
	vector<vector<T>> getMatrix(){};
	vector<T> getRow(int i){};
	vector<T> getColumn(int i){};
	T getElement(int i,int j){};
};


class matrix_operations{
public:
	vector<vector<T>> addMatrix(vector<vector<T>> A,vector<vector<T>> B){};
	vector<vector<T>> multiplyMatrix(vector<vector<T>> A,vector<vector<T>> B){};	
	void invertMatrix(&vector<vector<T>>){};

}
