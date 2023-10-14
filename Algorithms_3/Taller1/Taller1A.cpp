#include <iostream>
#include <cmath>
#include <stdlib.h>





using namespace std;




struct Nodo{
	int dato;
	Nodo *siguiente;
	Nodo *anterior;
}*primero,*ultimo;




void insertar1(Nodo *&,int);
void mostrar1(Nodo *);
void eliminar(Nodo *&);
void mostrar_Repetidos(Nodo *,Nodo *);
int main(){
	int cant1,cant2;
	Nodo *lista1=NULL;
	Nodo *lista2=NULL;
	cout<<"Ingrese la cantidad de elementos que desea en la 'lista A': ";cin>>cant1;
	cout<<"Ingrese la cantidad de elementos que desea en la 'lista B': ";cin>>cant2;
	insertar1(lista1,cant1);
	insertar1(lista2,cant2);
	
	
	mostrar1(lista1);
	cout<<endl;
	mostrar1(lista2);
	//eliminar(lista1);
	//eliminar(lista2);
	
	cout<<endl;
	//mostrar1(lista1);
	cout<<endl;
	//mostrar1(lista2);
	
	
	cout<<"Los numeros en la lista A que esten en la lista B:\t";
	mostrar_Repetidos(lista1,lista2);
	cout<<endl<<"Perdon, es que como no pude hacer el eliminar me evalua tambien los numeros repetidos en a y los muestra dos o mas veces. :(";
	
}






void insertar1(Nodo *&lista1,int cant1){
int i=0;
    Nodo *nuevo_nodo=new Nodo();
    if(cant1!=0){
    int a=0;
    a = rand() % 10;
    nuevo_nodo->dato=a;    
    nuevo_nodo->siguiente=NULL;
    nuevo_nodo->anterior=NULL;
    if (lista1 == NULL ){
    	lista1=nuevo_nodo;
		primero = nuevo_nodo;
		primero-> siguiente = NULL ;
		primero-> anterior = NULL ;
		ultimo = primero;
	} else {
		ultimo-> siguiente = nuevo_nodo;
		nuevo_nodo-> siguiente = NULL ;
		nuevo_nodo-> anterior = ultimo;
		ultimo = nuevo_nodo;
	}
    cant1--;
    insertar1(lista1->siguiente,cant1);
}
}


void mostrar1(Nodo *lista1){
	if(lista1->siguiente==NULL)
	{
		cout<<lista1->dato;
		
	}else{
		cout<<lista1->dato<<" ";
		mostrar1(lista1->siguiente);
	}	
	
}


void eliminar (Nodo *&lista){
	int num;
	Nodo *aux1 = lista;
	Nodo *aux2 = NULL;
	Nodo *aux3 = NULL;
	if(aux1!=NULL){
		
		num = aux1->dato;
		aux2 = aux1->siguiente;
		while(aux2 != NULL){
			if(aux2->dato == num){
				if (aux2->siguiente == NULL){
					aux3 = aux2->anterior;
					aux3->siguiente = NULL;
					delete aux2;
					break;
				}
				else{
					aux3 = aux2->anterior;
					aux3->siguiente = aux2->siguiente;
					delete aux2;
					aux2 = aux3->siguiente;
					aux2->anterior = aux3;
					aux2 = aux3;
				}
			}
			aux2 = aux2->siguiente;
		}
		eliminar(lista->siguiente);
	}
	
}


void mostrar_Repetidos(Nodo *lista1,Nodo *lista2){
	if(lista2==NULL){
		
	}else{
		while(lista1!=NULL){
			if(lista1->dato==lista2->dato){
				cout<<lista2->dato<<" ";
			}
			lista1=lista1->siguiente;
		}
		lista1=primero;
		mostrar_Repetidos(lista1,lista2->siguiente);
	}
}





