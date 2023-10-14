#include<iostream>
#include<stdlib.h>
#include<math.h>
#include <stack>

using namespace std;

struct Nodo{
	int long long dato;
	int valorDiv;
	Nodo *next;
};

int menu();

Nodo *expresion=new Nodo;

void insertarNodo(Nodo *&lista,int dato);
void separarCifras(int numero,Nodo *&lista);
void mostrar(Nodo *&lista);
void igualar(Nodo *&lista1,Nodo *&lista2);
void reiniciarValores(Nodo *&lista);
void agregarPila(Nodo *&pila,int dato);
void separarCifras2(int numero,Nodo *pila);
int medir(Nodo *&lista);
int revertir(Nodo *&lista);
void sumar();
void restar();
void multiplicar();
void division();

stack<int>P;

int main(){
	int op,sum;
	int num1,num2;
	cout<<"Calculadora con listas ligadas"<<endl<<endl;
	op=menu();
	
	do{
		switch(op){
			case 1:{
				cout<<"Sumar"<<endl;
				sumar();
				system("pause");
				system("cls");
				op=menu();
				break;
			}
			case 2:{
				cout<<"Restar"<<endl;
				restar();
				system("pause");
				system("cls");
				op=menu();
				break;
			}
			case 3:{
				cout<<"Multiplicar"<<endl;
				multiplicar();
				system("pause");
				system("cls");
				op=menu();
				break;
			}
			case 4:{
				cout<<"Dividir"<<endl;
				division();
				system("pause");
				system("cls");
				op=menu();
				break;
			}
			case 0:{
				break;
			}
			default: break;
		}
		
	}while(op!=0);
	
	return 0;
}

int menu(){
	int opcion;
	cout<<"Menu de opciones"<<endl<<endl;
	cout<<"1.Suma"<<endl;
	cout<<"2.Resta"<<endl;
	cout<<"3.Multiplicacion"<<endl;
	cout<<"4.Division"<<endl;
	cout<<"0.Salir"<<endl<<endl;
	cout<<"-->Ingrese una opcion:";cin>>opcion;
	
	while(opcion>4 || opcion<0){
		cout<<"\n-->Ingrese una opcion valida:";
		cin>>opcion;
	}
	
	return opcion;
}

void sumar(){
	int acumulador=0;
	int num1,num2;
	
	Nodo *lista=NULL;
	Nodo *lista2=NULL;
							
	cout<<"Ingrese un numero:";cin>>num1;
	while(num1<0){
	   cout<<"Solo se pueden ingresar numeros positivos"<<endl;
	   cout<<"-->Ingrese otro:";cin>>num1;
	}      
	cout<<"Ingrese otro numero:";cin>>num2;
	while(num2<0){
	    cout<<"Solo se pueden ingresar numeros positivos"<<endl;
		cout<<"-->Ingrese otro:";cin>>num2;
	}
	            
	separarCifras(num1,lista);
	separarCifras(num2,lista2);	
	igualar(lista,lista2);
	
	Nodo *listaResultado=NULL;
	Nodo *pointerR=lista;
	Nodo *pointer2R=lista2;

	while(pointerR!=NULL && pointer2R!=NULL){
		acumulador=pointerR->dato+pointer2R->dato;
		
		if(acumulador>=10 && pointerR->next!=NULL && pointer2R->next!=NULL){
			insertarNodo(listaResultado,acumulador%10);
			pointerR->next->dato+=acumulador/10;
		}else if(acumulador>=10 && pointerR->next==NULL && pointer2R->next==NULL){
			insertarNodo(listaResultado,acumulador%10);
			insertarNodo(listaResultado,acumulador/10);
		}
		else{
			insertarNodo(listaResultado,acumulador);
		}
	    pointer2R=pointer2R->next;
		pointerR=pointerR->next;
	}
	Nodo *pointerN=listaResultado;
	
	while(pointerN!=NULL){
		P.push(pointerN->dato);
		pointerN=pointerN->next;
	}
	//Se utiliza una pila de la libreria <stack> para mostrar el resultado
   cout<<"El resultado de la suma es:";
	while(!P.empty()){
		cout<<P.top();
		P.pop();
	}
	
	listaResultado=NULL;
    cout<<endl;
}

void restar(){
	int num1,num2;
	Nodo *lista=NULL;
	Nodo *lista2=NULL;
	Nodo *listaResultado=NULL;
	int acumulador;
	
	cout<<"Ingrese el primer numero:";cin>>num1;
	separarCifras(num1,lista);
	
	cout<<"Ingrese el segundo numero:";cin>>num2;
	while(num2>num1){
		cout<<"El segundo numero debe ser menor o igual al primero"<<endl;
		cout<<"-->Ingrese otro:";cin>>num2;
	}
	separarCifras(num2,lista2);
	
	igualar(lista,lista2);
	
	Nodo *pointerR=lista;
	Nodo *pointer2R=lista2;
	
	while(pointerR!=NULL && pointer2R!=NULL){
	  
	  if(pointerR->dato>=pointer2R->dato){
	  	acumulador=pointerR->dato-pointer2R->dato;
	  	insertarNodo(listaResultado,acumulador);
	  }else{
	  	pointerR->dato+=10;
	  	Nodo *pointerI=pointerR->next;
	  	while(pointerI->dato==0){
	  		pointerI->dato=9;
	  		pointerI=pointerI->next;
		  }
		  pointerI->dato-=1;
		  acumulador=pointerR->dato-pointer2R->dato;
		  insertarNodo(listaResultado,acumulador);
	  }
	  pointerR=pointerR->next;
	  pointer2R=pointer2R->next;	
	}
	
	Nodo *pointerN=listaResultado;
	
	while(pointerN!=NULL){
		P.push(pointerN->dato);
		pointerN=pointerN->next;
	}
	
	cout<<"\nEl resultado de la resta es:";
	while(!P.empty()){
		cout<<P.top();
		P.pop();
	}
	cout<<endl;	
}

void multiplicar(){
	int long long num1,num2,i=0;
	int long long numR=0;
	Nodo *pointer1,*pointer2;
	Nodo *lista=NULL;
	Nodo *lista2=NULL;
	Nodo *listaResultado=NULL;
	int long long acumulador=0,acumulador2=0;
	
	cout<<"Ingrese el primer numero:";cin>>num1;
	while(num1<0){
		cout<<"No se pueden ingresar numeros negativos"<<endl;
		cout<<"-->Ingrese otro numero:";cin>>num1;
	}
	cout<<"Ingrese el segundo numero:";cin>>num2;
	while(num2<0){
		cout<<"No se pueden ingresar numeros negativos"<<endl;
		cout<<"-->Ingrese otro numero:";cin>>num2;
	}
	
	if(num1>num2){
		separarCifras(num1,lista);
		separarCifras(num2,lista2);
	}else{
		separarCifras(num2,lista);
		separarCifras(num1,lista2);
	}
	
	igualar(lista,lista2);
	
	pointer1=lista;
	pointer2=lista2;
	while(pointer2!=NULL){
		Nodo *pointerI=lista;
		while(pointerI!=NULL){
			acumulador=pointerI->dato*pointer2->dato;
			
			if(pointerI->valorDiv>0){
				acumulador+=pointerI->valorDiv;
			}
			
			if(acumulador>=10 && pointerI->next!=NULL){
				insertarNodo(listaResultado,acumulador%10);
				pointerI->next->valorDiv=acumulador/10;
			}else if(acumulador>=10 && pointerI->next==NULL){
				insertarNodo(listaResultado,acumulador%10);
				insertarNodo(listaResultado,acumulador/10);
			}
			else{
				insertarNodo(listaResultado,acumulador);
			}
			pointerI=pointerI->next;
		}
		numR=revertir(listaResultado);
		numR*=(pow(10,i));
		acumulador2+=numR;
		reiniciarValores(lista);
		listaResultado=NULL;
		i++;
		pointer2=pointer2->next;
	}
	cout<<"Resultado de la multiplicacion:"<<acumulador2<<endl;
}

void division(){
	int num1,num2;
	Nodo *pila,*pila2;
	
	cout<<"Ingrese el primer numero:";cin>>num1;
	while(num1<0){
		cout<<"No se pueden ingresar numeros negativos"<<endl;
		cout<<"-->Ingrese otro numero:";cin>>num1;
	}
	cout<<"Ingrese el segundo numero:";cin>>num2;
	while(num2>num1 || num2<=0){
		cout<<"Numero invalido (n1>n2) y (n2!=0)"<<endl;
		cout<<"-->Ingrese otro numero:";cin>>num2;
		cout<<endl;
	}
	
	separarCifras2(num1,pila);
	separarCifras2(num2,pila2);
	igualar(pila,pila2);
	
	Nodo *pointer1;
	Nodo *pointer2;
	
	pointer1=pila;
	pointer2=pila2;
	
	int cociente,acumulador;
	while(pointer1!=NULL && pointer2!=NULL){
		
		if(pointer1->dato>pointer2->dato){
			
		}else if(pointer1->dato<pointer2->dato){
			acumulador=(pointer1->dato*10)+(pointer1->next->dato);
			acumulador=acumulador/pointer2->dato;
		}
		
		pointer1=pointer1->next;
		pointer2=pointer2->next;
	}
}

void insertarNodo(Nodo *&lista,int dato){
   Nodo *nuevoNodo=new Nodo();
   nuevoNodo->dato=dato;
   if(lista==NULL){
   	  lista=nuevoNodo;
   }else{
   	 Nodo *pointer=lista;
   	 while(pointer->next!=NULL){
   	 	pointer=pointer->next;
	}
	pointer->next=nuevoNodo;
   }
}

void reiniciarValores(Nodo *&lista){
	Nodo *pointer=lista;
	while(pointer!=NULL){
		pointer->valorDiv=0;
		pointer=pointer->next;
	}
}

void separarCifras(int numero,Nodo *&lista){
	int i=0;
	int dato=0;

	while(numero>0){
		dato=numero%10;
		insertarNodo(lista,dato);
		numero=numero/10;
		dato=0;
		i+=1;
	}
}

void mostrar(Nodo *&lista){
	Nodo *pointer=lista;
	
	while(pointer->next!=NULL){
		cout<<pointer->dato;
		pointer=pointer->next;
	}
	cout<<pointer->dato<<endl;
}

int medir(Nodo *&lista){
	int i=0;
	Nodo *pointer=lista;
	while(pointer!=NULL){
		i++;
		pointer=pointer->next;
	}
	return i;
}

void igualar(Nodo *&lista1,Nodo *&lista2){
	int i=0,j=0;
	int diferencia=0;
	
	i=medir(lista1);
	j=medir(lista2);
	
	if(i>j){
		diferencia=i-j;
		for(int k=0;k<diferencia;k++){
			insertarNodo(lista2,0);
		}
	}else if(j>i){
		diferencia=j-i;
		for(int l=0;l<diferencia;l++){
			insertarNodo(lista1,0);
		}
	}	
}

int revertir(Nodo *&lista){
	Nodo *pointer=lista;
	int dato=0,i=0;
	
	while(pointer!=NULL){
		dato+=pointer->dato*pow(10,i);
		pointer=pointer->next;
		i++;
	}
	return dato;
}

void agregarPila(Nodo *&pila,int dato){
	Nodo *nuevoNodo=new Nodo();
	nuevoNodo->dato=dato;
	nuevoNodo->next=pila;
	pila=nuevoNodo;
}

void separarCifras2(int numero,Nodo *pila){
	int i=0;
	int dato=0;

	while(numero>0){
		dato=numero%10;
		agregarPila(pila,dato);
		numero=numero/10;
		dato=0;
		i+=1;
	}
}
