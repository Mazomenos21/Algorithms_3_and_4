#include <iostream>
#include <stdio.h>
#include <stdlib.h>




using namespace std;


struct Nodo{
	int dato;
	Nodo *siguiente;
}*primero,*ultimo;

struct Nododem{
	int dato;
	Nododem *siguientedem;
}*primerodem,*ultimodem;

struct Nodoaux{
	int dato;
	Nodoaux *siguienteaux;
}*primeroaux=NULL,*ultimoaux=NULL;


void menu();
void suma();
void resta();
void multiplicacion();
void division(int,int);
void insertarNodo(int);
void  insertarNodoDem (int );
void igualar();

int contadorn=0,contadord=0;


int main()
{
	menu();
}










void menu(){
	Nodo* nuevo = new Nodo();
	int numerador,denominador,n,d;
	cout<<"PROCURA UTILIZAR EL NUMERO CON MAS DIGITOS DE NUMERADOR,GRACIAS.\n";
	cout<<"----------INGRESE LOS DATOS------------\n";
	cout<<"ingrese el numerador: ";cin>>numerador;cout<<endl;
	cout<<"ingrese el denominador: ";cin>>denominador;cout<<endl;
	int opcion=0,i=0,s=0;
	int digito[20],digitod[20];
	
	n=numerador;
	d=denominador;
	
/*	
	for(int j=i-1;j>=0;j--)
	{
		insertarNodo(digito[j]);
	}
	
	for(int j=s-1;j>=0;j--)
	{
		insertarNodoDem(digitod[j]);
	}
	*/
	
	
	
	do{
		while(numerador>0){
		digito[i]=numerador%10;
		numerador=numerador/10;
		insertarNodo(digito[i]);
		i++;
	}
	while(denominador>0){
		digitod[s]=denominador%10;
		denominador=denominador/10;
		insertarNodoDem(digitod[s]);
		s++;
	}
	igualar();
		cout<<"-----------BIENVENIDO A LA CALCULADORA :) --------------\n";
		cout<<"1.Sumar.\n"
		<<"2.Restar.\n"
		<<"3.Multiplicar.\n"
		<<"4.Dividir.\n"
		<<"5.Salir.\n";
		
		cin>>opcion;
		
		switch(opcion){
			case 1:{
				suma();
				break;
			}
			case 2:{
				resta();
				break;
			}
			case 3:{
				multiplicacion();
				break;
			}
			case 4:{
				division(n,d);
				break;
			}
			case 5:{
				cout<<"\nGracias por utilizar el programa.\n";
				break;
			}
			default:{
				cout<<"\nHa ingresado un numero incorrecto.\n";
				break;
			}
		}
	}while(opcion!=5);
	
	
}






void  insertarNodo (int numerador){
	Nodo* nuevo = new  Nodo ();
	nuevo->dato=numerador;
	if (primero == NULL ){
		primero = nuevo;
		primero-> siguiente = NULL ;
		ultimo = nuevo;
	}else{
		ultimo-> siguiente = nuevo;
		nuevo-> siguiente = NULL ;
		ultimo = nuevo;
	}

}



void  insertarNodoDem (int numerador){
	Nododem* nuevodem = new  Nododem ();
	nuevodem->dato=numerador;
	if (primerodem == NULL ){
		primerodem = nuevodem;
		primerodem-> siguientedem = NULL ;
		ultimodem = nuevodem;
	}else{
		ultimodem-> siguientedem = nuevodem;
		nuevodem-> siguientedem = NULL ;
		ultimodem = nuevodem;
	}

}






void igualar(){
	Nodo* actualnumerador = new Nodo();
	Nododem* actualdenominador = new Nododem();
	actualnumerador=primero;
	actualdenominador=primerodem;
	
	do{
		contadorn++;
		actualnumerador=actualnumerador->siguiente;
	}while(actualnumerador!=NULL);
	
	do{
		contadord++;
		actualdenominador=actualdenominador->siguientedem;
	}while(actualdenominador!=NULL);
	
	
	if(contadorn>contadord)
	{
		while(contadorn!=contadord)
		{
			insertarNodoDem(0);
			contadord++;
		}
	}
	
	
	if(contadord>contadorn)
	{
		while(contadorn!=contadord)
		{
			insertarNodo(0);
			contadorn++;
		}
	}
	
	
}











void suma()

{                                      
	int sumaparcial=0,residuo=0,acumulado=0;
	int i=0,sumatotal[20];		
	Nodo* actualnumerador = new Nodo();
	Nododem* actualdenominador = new Nododem();
	actualnumerador=primero;
	actualdenominador=primerodem;
	do{
	acumulado=actualnumerador->dato+residuo;
	sumaparcial=acumulado+actualdenominador->dato;
	
	if(actualnumerador->siguiente==NULL)
	{
		sumatotal[i]=sumaparcial;
}else if(sumaparcial>9)
	{
		sumatotal[i]=sumaparcial%10;
		residuo=sumaparcial/10;
	}else{
		sumatotal[i]=sumaparcial;
		residuo=0;
	}
	i++;
	actualnumerador=actualnumerador->siguiente;
	actualdenominador=actualdenominador->siguientedem;
	}while(actualnumerador!=NULL);
		
		
		
	cout<<"La suma total de los datos es: ";
	for(int j=i-1;j>=0;j--)
	{
		cout<<sumatotal[j];
	}
				
	cout<<endl<<endl<<endl;
	
}



void resta(){
	Nodo* actualnumerador = new Nodo();
	Nododem* actualdenominador = new Nododem();
	actualnumerador=primero;
	actualdenominador=primerodem;
	int restaparcial=0,residuo=0,acumulado=0;
	int restatotal[20],i=0;
	
	do{
	
		
		if(actualnumerador->dato<actualdenominador->dato)
		{
			actualnumerador->dato=actualnumerador->dato+10;
			actualnumerador->siguiente->dato=actualnumerador->siguiente->dato-1;
			restatotal[i]=actualnumerador->dato-actualdenominador->dato;
		}else{
			restatotal[i]=actualnumerador->dato-actualdenominador->dato;
		}
		i++;
		actualnumerador=actualnumerador->siguiente;
		actualdenominador=actualdenominador->siguientedem;
	}while(actualnumerador!=NULL);
	
	
	cout<<"La resta de los datos es: ";
	
	for(int j=i-1;j>=0;j--)
	{
		cout<<restatotal[j];
	}
	
	
	cout<<endl<<endl;
}




void multiplicacion(){
	int s=contadorn+contadord;
	int sw=0;
	int i=0,multi=0,acumulado=0,acumuladosuma=0,suma=0,j=0;
	int llenaraux=contadorn+contadord,l[20],full[30];
	Nodo* actualnumerador = new Nodo();
	Nododem* actualdenominador = new Nododem();
	actualdenominador=primerodem;
	
	for(int j=0;j<s;j++)
	{
		full[j]=0;
	}
	
	
	
	do{
		
		actualnumerador=primero;
		i=0;
		do{
					
			
			if(sw==1)
			{
				if(j>i)
				{
					while(i!=j)
					{
						i++;
					}	
				}
				multi=(actualnumerador->dato*actualdenominador->dato)+acumulado;
				if(actualnumerador->siguiente==NULL)
				{
					suma=(multi%10)+full[i]+acumuladosuma;
					if(suma>9)
					{
						full[i]=suma%10;
						full[i+1]=full[i+1]+(suma/10)+(multi/10);
						acumuladosuma=0;
					}else{
						full[i]=suma;
						full[i+1]=multi/10;
						acumuladosuma=0;
					}
					acumulado=0;			
				}else if(multi>9)
				{
					suma=(multi%10)+full[i]+acumuladosuma;
					acumulado=multi/10;
					if(suma>9)
					{
						full[i]=suma%10;
						acumuladosuma=suma/10;
					}else{
						full[i]=suma;
						acumuladosuma=0;
					}
					
				}else{
					suma=full[i]+multi+acumuladosuma;
					
					if(suma>9)
					{
						full[i]=suma%10;
						acumuladosuma=suma/10;
					}else{
						full[i]=suma;
						acumuladosuma=0;
					}
					
				}
			}
			if(i==0 && actualdenominador==primerodem)
			{
				multi=actualnumerador->dato*actualdenominador->dato;
				if(actualnumerador->siguiente==NULL)
				{
					full[i]=multi%10;
					full[i+1]=multi/10;
					acumulado=0;
				}
				if(multi>10)
				{
					full[i]=multi%10;
					acumulado=multi/10;
				}else if(multi<10 && actualnumerador->siguiente!=NULL){
					full[i]=multi;
					acumulado=0;
				}
				sw=1;
			}
			i++;
			actualnumerador=actualnumerador->siguiente;
		}while(actualnumerador!=NULL);
		j++;
		actualdenominador=actualdenominador->siguientedem;
	}while(j<contadord-1);
	
	cout<<s<<endl;
	int m=0;
	
	cout<<"El resultado es: ";
	if(contadorn<2)
	{
		for(int j=(s-1);j>=0;j--)
	{
		cout<<full[j];
	}	
	}else if(contadorn>1){
		for( m=(s-1);m>=0;m--)
		{
		cout<<full[m];
		}
	}
	cout<<endl<<endl;
}






void division(int,int){
	Nodo* actualnumerador = new Nodo();
	Nododem* actualdenominador = new Nododem();
	actualdenominador=primerodem;
	actualnumerador=primero;
	int divi[20],aux2;
	
	int a=0,b=0,i=0,s=0;
	int temporal;
	cout<<"El resultado es: ";
	while(actualnumerador|| actualdenominador ){
		if(actualnumerador){
			a=a*10 + actualnumerador->dato;
			
		}
		if(actualdenominador){
			b= b*10+ actualdenominador->dato;
			
		}
		if(actualnumerador)
		actualnumerador= actualnumerador->siguiente;
		if(actualdenominador)
		actualdenominador= actualdenominador->siguientedem;
	}
	
	if(a>b){
	temporal=a/b;
	while(temporal){
	cout<<temporal%10;
	temporal /= 10;
}
}else{
	temporal=b/a*-1;
	while(temporal){
	cout<<temporal%10;
	temporal /= 10;
}

}
	
	cout<<endl<<endl;
}





