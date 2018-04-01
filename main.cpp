#include <iostream>

using namespace std;
//prototipos
//funcion menu lee y valida la entrada.
int menu();

//reserva memoria dinamica para un arreglo de enteros, recibe de parametro el size del arreglo.
int* createArray(int);

// libera la memoria del arreglo.
void clearArray(int*&);

//imprime el contenido del arreglo
void printArray(int*,int);

//Leer size del arreglo
int getSize();

//dar valores al arreglo.
int* writeArray(int*,int);

int main(){

   
    int*array=NULL;
    int size=0;
    int op=0;

    while(op!=5){
      switch(op=menu()){
        case 1:
	   //crear el arreglo
	   size=getSize();
           //cin>>size;
	   //evitar memory leaks
	   if(array==NULL){
              array=createArray(size);
           }else{
              clearArray(array);
	      array=createArray(size);
	    }	   
           break;
	case 2:
            array=writeArray(array,size);
	   break;
	case 3:
	   clearArray(array);
	   //array=NULL;
	   size=0;
	   break;
	case 4:
	   printArray(array,size);
	   break;   
	case 5:
         //salir del programa
	 if(array!=NULL){
	     clearArray(array);
             break;	     
	 }	 
	    
      }	      
    }	    
    return 0;
}


//Dar valores al arreglo
int* writeArray(int*array,int size){	
    for (int i=1;i<=size;i++){
       cout<<"Ingrese "<<i<<" valor: ";
       cin>> array[i];   
    }	    
 return array;
}	

//Leer size del arreglo.
int getSize(){
    int size;
    while(true){
    cout<<"Ingrese size del arreglo";
    cin>>size;
    if(size>=0)
        return size;
    else
	cout<<"Ingrese un valor positivo mayor a 1."<<endl;
    }//fin del while

}	
//muestra un menu y valida la entrada.
int menu(){
 int bandera=0;
 while(bandera==0){
    int num;	 
    cout<<"**********Menu***********"<<endl;
    cout<<"1.Crear un arreglo"<<endl;
    cout<<"2.Llenar el arreglo"<<endl;
    cout<<"3.Limpiar el espacio en memoria"<<endl;
    cout<<"4.Imprimir el arreglo"<<endl;
    cout<<"5.Salir del programa"<<endl;
    cout<<"Ingrese numero de opcion que desea:";
    cin>>num;
    return num;    

 }
} 
//reserva memoria dinamica para un arreglo.

int*createArray(int size){
    int*retValue=new int[size];
    return retValue;
//alternativa return new int[size];.
}

//libera memoria del arreglo.
void clearArray(int*& array){
    delete[]array;
    array=NULL;
}

//imprimir contenido del arreglo.
void printArray(int*array,int size){
    for(int i=0;i<size;i++){
        cout<<" "<<array[i];  
    }
    cout<<endl;
}


