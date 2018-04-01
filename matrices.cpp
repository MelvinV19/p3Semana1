#include <iostream>
using namespace std;
int main(){
	//matriz en memoria estatica.
	int size=3;
    int matrix[size][size];
	matrix[1][1]=100;
	cout<<matrix[1][1]<<endl;

	//matriz en memoria dinamica(con apuntadores).
    int** matrix2=new int*[size];
	for(int i=0;i<size;i++){
	    matrix2[i]=new int[size];
	}
	matrix2[1][1]=500;
	cout<<matrix2[1][1]<<endl;

	//liberar memoria.
	for(int i=0;i<size;i++){
        delete[]matrix2[i];
		matrix2[i]=NULL;
	}
	delete[] matrix2;
	matrix2=NULL;
	
	return 0;

}
