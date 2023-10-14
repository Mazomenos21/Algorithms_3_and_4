#include<iostream>
#include <stdio.h>
#include <stdlib.h>



using namespace std;



struct Nodo{
	int dato;
	int Lista_fila;
	int Lista_columna;
	Nodo *siguiente;	 	
}*primero,*ultimo;




void ordena_lista();
void Ingresar(Nodo *&,int,int);
void Mostrar(int, int);
void Modificar(int,int);
void Eliminar(int,int);
void Buscar(int,int);
void Informes(int,int);
void menu();











int main(){
	menu();
}







void menu(){
	Nodo *lista=NULL;
	int filas,columnas,opcion_menu=0;
	cout<<"INGRESE LA CANTIDAD DE FILAS QUE DESEA TENER: \n";
	cin>>filas;
	cout<<"\nINGRESE LA CANTIDAD DE COLUMNAS QUE DESEA TENER: \n";
	cin>>columnas;
	
	
	
	do
	{
		cout<<"\n====================================";
		cout<<"\n|\t   Bienvenido           |";
		cout<<"\n====================================";
		cout<<"\n|1. Ingresar Elemento.             |";
		cout<<"\n|2. Modificar Elemento.            |";
		cout<<"\n|3. Eliminar Elemento.             |";
		cout<<"\n|4. Buscar Elemento.               |";
		cout<<"\n|5. Mostrar La matriz.             |";
		cout<<"\n|6. Informes.                      |";
		cout<<"\n|7. Salir.                         |";
		cout<<"\n====================================";
		cout<<"\nIngresa tu opcion deseada: ";
		cin>>opcion_menu;
		
		
		
		
		switch(opcion_menu)
		{
			
			case 1:{
				Ingresar(lista,filas,columnas);
				break;
			}
			case 2:{
				Modificar(filas,columnas);
				break;
			}
			case 3:{
				Eliminar(filas,columnas);
				break;
			}
			case 4:{
				Buscar(filas,columnas);
				break;
			}
			case 5:{
				Mostrar(filas,columnas);
				break;
			}
			case 6:{
				Informes(filas,columnas);
				break;
			}
			case 7:{
				cout<<"\nGRACIAS POR UTILIZAR EL PROGRAMA\n";
				break;
			}
			default:{
				cout<<"\nHA INGRESADO UN NUMERO ERRONEO\n";
				break;
			}
			
			
		}
		
		
		
		
		
		
		
		
	}while(opcion_menu!=7);

}

























void Ingresar(Nodo *&lista,int filas,int columnas){
	Nodo* nuevo= new Nodo();
	Nodo* actual = new Nodo();
	actual=primero;
	cout<<"Ingrese la fila: ";
	cin>>nuevo->Lista_fila;cout<<endl;
	cout<<"Ingrese la columna: ";
	cin>>nuevo->Lista_columna;cout<<endl;
	if(nuevo->Lista_fila>filas || nuevo->Lista_fila==0){
		cout<<"Ha ingresado una fila erronea.\n";
	}else if(nuevo->Lista_columna>columnas || nuevo->Lista_columna==0)
	{
		cout<<"Ha ingresado una columna erronea.\n";
	}else{
		cout<<"Ingrese el dato que va a ingresar en la posicion ["<<nuevo->Lista_fila<<"]["<<nuevo->Lista_columna<<"]: ";
		cin>>nuevo->dato;
		cout<<endl;	
		if(primero==NULL)
		{
			primero = nuevo;
			primero->siguiente=primero;
			ultimo=primero;
		}else{
			ultimo->siguiente=nuevo;
			nuevo->siguiente=primero;
			ultimo=nuevo;
			}
		cout<<"\nHA SIDO INGRESADO CORRECTAMENTE\n";
	}
	ordena_lista();
}




void ordena_lista()
{
    int n,f,c;
    Nodo *actual, *siguiente;
    actual = primero;

    if(primero != NULL)
    {
        do
        {
        	int suma1=0,suma2=0;
        	suma1=actual->Lista_fila+actual->Lista_columna;
            siguiente = actual->siguiente;
            suma2=siguiente->Lista_fila+siguiente->Lista_columna;
            while(siguiente != primero)
            {
                if(suma1 > suma2)
                {
                    n = siguiente->dato;
                    f = siguiente->Lista_fila;
                    c = siguiente->Lista_columna;
                    
                    
                    siguiente->dato = actual->dato;
                    siguiente->Lista_fila = actual->Lista_fila;
                    siguiente->Lista_columna = actual->Lista_columna;
                    
                    
                    actual->dato = n;
                    actual->Lista_fila=f;
                    actual->Lista_columna=c;
                }
                if(suma1==suma2)
                {
                	if(actual->Lista_fila>siguiente->Lista_fila)
                	{
					n = siguiente->dato;
                    f = siguiente->Lista_fila;
                    c = siguiente->Lista_columna;
                    
                    
                    siguiente->dato = actual->dato;
                    siguiente->Lista_fila = actual->Lista_fila;
                    siguiente->Lista_columna = actual->Lista_columna;
                    
                    
                    actual->dato = n;
                    actual->Lista_fila=f;
                    actual->Lista_columna=c;
					}
				}
                siguiente = siguiente->siguiente;
            }
            actual = actual->siguiente;
            siguiente = actual->siguiente;
        }
        while(siguiente != primero);
    }
}










void Modificar(int filas,int columnas){
	int modFila,modColumna;
	cout<<"Ingrese la fila del dato que quiere modificar: \n";
	cin>>modFila;
	cout<<"Ingrese la columna del dato que quiere modificar: \n";
	cin>>modColumna;
	
	Nodo* actual = new Nodo();
	actual=primero;
	if(modFila>filas || modFila==0){
		cout<<"Ha ingresado una fila erronea o esta no existe.\n";
	}else if(modColumna>columnas || modColumna==0)
	{
		cout<<"Ha ingresado una columna erronea o esta no existe.\n";	
	}else{
	if(primero!=NULL)
	{
		do{
			if(actual->Lista_fila==modFila && actual->Lista_columna==modColumna){
				cout<<"Ingrese el dato que quiere modificar en la posicion ["<<actual->Lista_fila<<"]["<<actual->Lista_columna<<"]: ";
				cin>>actual->dato;
				cout<<endl;	
			}
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		cout<<"\n La lista se encuentra vacía\n";
	}
	}
}









void Eliminar(int filas,int columnas)
{
	int modFila,modColumna;
	cout<<"Ingrese la fila del dato que quiere eliminar: \n";
	cin>>modFila;
	cout<<"Ingrese la columna del dato que quiere eliminar: \n";
	cin>>modColumna;
	
	
	Nodo* actual = new Nodo();
	actual=primero;
	Nodo* anterior = new Nodo();
	anterior=NULL;
	
	if(modFila>filas || modFila==0){
		cout<<"Ha ingresado una fila erronea o esta no existe.\n";
	}else if(modColumna>columnas || modColumna==0)
	{
		cout<<"Ha ingresado una columna erronea o esta no existe.\n";	
	}else{
	if(primero!=NULL)
	{
		do{
			if(actual->Lista_fila==modFila && actual->Lista_columna==modColumna){
				cout<<"El dato que se eliminara en la posicion ["<<actual->Lista_fila<<"]["<<actual->Lista_columna<<"] es: "<<actual->dato;
				cout<<endl;
				if(actual==primero){
					primero=primero->siguiente;
					ultimo->siguiente=primero;
				}else if(actual==ultimo){
					anterior->siguiente=primero;
					ultimo=anterior;
				}else{
					anterior->siguiente=actual->siguiente;
				}
			}
			anterior=actual;
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		cout<<"\n La lista se encuentra vacía\n";
	}	
	}
}













void Buscar (int filas,int columnas)
{
	int modFila,modColumna;
	cout<<"Ingrese la fila del dato que quiere buscar: \n";
	cin>>modFila;
	cout<<"Ingrese la columna del dato que quiere buscar: \n";
	cin>>modColumna;
	
	
	
	
	Nodo* actual = new Nodo();
	actual=primero;
	
	if(modFila>filas || modFila==0){
		cout<<"Ha ingresado una fila erronea o esta no existe.\n";
	}else if(modColumna>columnas || modColumna==0)
	{
		cout<<"Ha ingresado una columna erronea o esta no existe.\n";	
	}else{
	if(primero!=NULL)
	{
		do{
			if(actual->Lista_fila==modFila && actual->Lista_columna==modColumna){
				cout<<"El dato que se encuentra en la posicion ["<<actual->Lista_fila<<"]["<<actual->Lista_columna<<"] es: "<<actual->dato;
				cout<<endl;
			}
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		cout<<"\n La lista se encuentra vacía\n";
	}		
	}
		
}







void Mostrar(int filas,int columnas)
{
	int mat[filas][columnas];
	Nodo* actual = new Nodo();
	actual=primero;
	
	if(primero!=NULL)
	{
		do{
			cout<<"["<<actual->Lista_fila<<"]["<<actual->Lista_columna<<"] : "<<actual->dato<<endl;
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		cout<<"\n La lista se encuentra vacía\n";
	}
	    
    
    
    
    for(int i=1;i<=filas;i++)
    {
    	for(int j=1;j<=columnas;j++)
    	{
    		if(i==actual->Lista_fila && j==actual->Lista_columna){
    			mat[i][j]=actual->dato;
    			actual=actual->siguiente;
			}else{
				mat[i][j]=0;	
			}
		}
	}
	
	
	   for(int i=1;i<=filas;i++)
    {
    	for(int j=1;j<=columnas;j++)
    	{
    		cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
    
}







void Informes(int filas,int columnas){
		int menu_informes=0;
		Nodo* actual = new Nodo();
		actual=primero;
		int suma[20];
		do{
		cout<<"----------------------------MENU INFORMES---------------------------"<<endl;
        cout<<"1. Suma x Filas"<<endl;
        cout<<"2. Suma x Columnas"<<endl;
        cout<<"3. Buscar un numero y diga en que posición esta"<<endl;
        cout<<"4. Cuente cuantas veces se repite un número"<<endl;
        cout<<"5. Imprima la suma de la matriz"<<endl;
        cout<<"6. Muestre el numero Mayor y su posición en la matriz"<<endl;
        cout<<"7. Muestre el numero Menor y su posición en la matriz"<<endl;
        cout<<"8. Muestre los números Pares"<<endl;
        cout<<"9. Muestre los números Impares"<<endl;
        cout<<"10. Volver al Menu Principal"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Digite la Opción <<1-2-3-4-5-6-7-8-9-10>>:"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
		
		cin>>menu_informes;
		
		
		
		switch(menu_informes)
		{
			case 1:{

			for(int i=1;i<=filas;i++){
				for(int j=1;j<=columnas;j++){
					if(i==actual->Lista_fila){
						suma[i]+=actual->dato;
					}
					actual=actual->siguiente;
				}	
			}
			for(int i=1;i<=filas;i++)
			{
				cout<<"\nLa suma de la fila "<<i<<" es: "<<suma[i]<<endl;
			}
				break;
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			case 2:{
			for(int i=1;i<=filas;i++){
				for(int j=1;j<=columnas;j++){
					if(j==actual->Lista_columna){
						suma[j]+=actual->dato;
					}
					actual=actual->siguiente;
				}	
			}
				for(int j=1;j<=columnas;j++)
				{
					cout<<"\nLa suma de la columna "<<j<<" es: "<<suma[j]<<endl;
				}
				break;
			}
			
			
			
			
			
			
			
			
			
			
			
			
			case 3:{
				int dato;
				cout<<"ingrese el dato a buscar: ";cin>>dato;cout<<endl;
				
				if(primero!=NULL)
					{
				do{
					if(actual->dato==dato)
					{
					cout<<"El dato se encuentra en la posicion ["<<actual->Lista_fila<<"]["<<actual->Lista_columna<<"] : "<<endl;	
					}
					actual=actual->siguiente;
				}while(actual!=primero);
				}
				break;
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			case 4:{
				int dato,contador=0;
				cout<<"ingrese el dato a buscar: ";cin>>dato;cout<<endl;
				
				if(primero!=NULL)
					{
				do{
					if(actual->dato==dato)
					{
					contador++;	
					}
					actual=actual->siguiente;
				}while(actual!=primero);
				}
				cout<<"El numero "<<dato<<" se encuentra en una cantidad de: "<<contador<<endl;
				break;
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			case 5:{
				
				
				int contador;
				
				if(primero!=NULL)
					{
				do{
					contador+=actual->dato+1;
					actual=actual->siguiente;
				}while(actual!=primero);
				}
				cout<<"La suma total de la matriz es: "<<contador<<endl;
				
				break;
			}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			case 6:{
				int mayor=0,f,c;
				if(primero!=NULL)
					{
				do{
					if(actual->dato>actual->siguiente->dato)
					{
					if(actual->dato>mayor)
					{
						mayor=actual->dato;	
						f=actual->Lista_fila;
						c=actual->Lista_columna;
					}
					}
					actual=actual->siguiente;
				}while(actual!=primero);
				}
				cout<<"\nEl numero mayor es: "<<mayor<<" en la posicion ["<<f<<"]["<<c<<"]\n";
				break;
			}
			case 7:{
					int menor=0,f,c;
				if(primero!=NULL)
					{
				do{
					if(actual->dato<actual->siguiente->dato)
					{
					if(actual->dato<menor)
					{
						menor=actual->dato;	
						f=actual->Lista_fila;
						c=actual->Lista_columna;
					}
					}
					actual=actual->siguiente;
				}while(actual!=primero);
				}
				cout<<"\nEl numero menor es: "<<menor<<" en la posicion ["<<f<<"]["<<c<<"]\n";
				break;
			}
			case 8:{
				cout<<"\nLos numeros pares son: \n";
				do{
					if(actual->dato%2==0)
					{
						cout<<actual->dato<<" ";
					}
					actual=actual->siguiente;
				}while(actual!=primero);
				break;
			}
			case 9:{
				cout<<"\nLos numeros impares son: \n";
				do{
					if(actual->dato%2!=0)
					{
						cout<<actual->dato<<" ";
					}
					actual=actual->siguiente;
				}while(actual!=primero);
				break;
			}
			case 10:{
				cout<<"\nGracias por utilizar el programa.\n";
				break;
			}
			default:{
				cout<<"\nHa ingresado un numero incorrecto.\n";
				break;
			}
		}
		
		
				
		}while(menu_informes!=10);
}
