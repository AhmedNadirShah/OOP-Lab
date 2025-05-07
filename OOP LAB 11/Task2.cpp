#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Matrix {
protected:
	int rows;
	int cols;
	T** matrix;
public:
	Matrix(int r,int c):rows(r),cols(c){
    matrix = new T*[rows];
    for(int i = 0; i < rows; ++i)
        matrix[i] = new T[cols];		
	}
	void add(){
		cout<<"Enter the matrix values\n";
		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
				cin>>matrix[i][j];
			}
		}
	}
	void display(){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	Matrix operator +(Matrix& obj) {
		if(rows==obj.rows && cols==obj.cols) {
			Matrix result(rows,cols);
			for(int i=0; i<rows; i++) {
				for(int j=0; j<cols; j++) {
					result.matrix[i][j]=matrix[i][j]+obj.matrix[i][j];
				}
			}
			return result;
		} 
		else
			throw"Dimensions mismatch";
	}
	Matrix operator -(Matrix& obj) {
		if(rows==obj.rows && cols==obj.cols) {
			Matrix result(rows,cols);
			for(int i=0; i<rows; i++) {
				for(int j=0; j<cols; j++) {
				    result.matrix[i][j]=matrix[i][j]-obj.matrix[i][j];
				}
			}
			return result;
		} 
		else
			throw"Dimensions mismatch";
	}
};
int main() {
	try{
	Matrix<int> a(2,2);
	a.add();
	Matrix<int> b(2,3);
	b.add();
	Matrix<int> c = a+b;
	Matrix<int> d = a-b;
	c.display();
	d.display();
}
catch(const char* c){
	cout<<"Error: "<<c<<endl;
}
	return 0;
}

