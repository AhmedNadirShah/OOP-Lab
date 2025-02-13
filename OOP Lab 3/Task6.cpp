#include <iostream>
using namespace std;
class Matrix{
public:
int rows, cols, arr[10][10];
Matrix(int rows, int cols){ 
this->rows=rows; 
this->cols=cols;
for(int i=0;i<10;i++){
for(int j=0;j<10;j++){
arr[i][j]=0; 
}
}
}
int getRows(){ return this->rows; }
int getCols(){ return this->cols; }
void setMatrix(int i, int j, int value){ 
if(i>=0 && i<rows && j>=0 && j<cols){
arr[i][j]=value; 
}
else 
cout<<"Invalid index\n"; 
}
Matrix AddMatrix(Matrix other){
if(rows!=other.rows||cols!=other.cols){ 
cout<<"Matrices cannot be added\n"; 
return Matrix(0,0); 
}
Matrix result(rows,cols);
for(int i=0;i<rows;i++){
for(int j=0;j<cols;j++){
result.arr[i][j]=arr[i][j]+other.arr[i][j];
}
}
return result; 
}
Matrix MultiplyMatrix(Matrix other){
if(cols!=other.rows){ 
cout<<"Matrices cannot be multiplied\n"; 
return Matrix(0,0); 
}
Matrix result(rows,other.cols);
for(int i=0;i<rows;i++){
for(int j=0;j<other.cols;j++){
result.arr[i][j]=0; 
for(int k=0;k<cols;k++){
result.arr[i][j]+=arr[i][k]*other.arr[k][j];
}
}
}
return result; 
}
void display(){ 
for(int i=0;i<rows;i++){ 
for(int j=0;j<cols;j++){
cout<<arr[i][j]<<" "; 
}
cout<<endl; 
} 
}
};
int main(){
Matrix mat1(2,2), mat2(2,2);
mat1.setMatrix(0,0,1); 
mat1.setMatrix(0,1,2); 
mat1.setMatrix(1,0,3); 
mat1.setMatrix(1,1,4);
mat2.setMatrix(0,0,5); 
mat2.setMatrix(0,1,6); 
mat2.setMatrix(1,0,7); 
mat2.setMatrix(1,1,8);
cout<<"Matrix 1:\n"; 
mat1.display();
cout<<"Matrix 2:\n"; 
mat2.display();
cout<<"Sum of Matrices:\n"; 
mat1.AddMatrix(mat2).display();
cout<<"Product of Matrices:\n"; 
mat1.MultiplyMatrix(mat2).display();
return 0;
}

