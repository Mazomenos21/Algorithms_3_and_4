#include <iostream>
#include <cmath>
#include <stdlib.h>





using namespace std;

struct Nodo {
    int Codigo;
    string nombre;
    string apellido;
    string correo;
    float nota;
    Nodo *anterior;
    Nodo *siguiente;
} *primero, *ultimo;



void insertar1(Nodo *&, int);
void modificar(Nodo *&, int );
void eliminar(Nodo *&,Nodo *&,int);
void menu1();
void mostrar1(Nodo *);
void informes();
void aprobados(Nodo *);
float promedio(Nodo *,float,int);
void promedio_alto(Nodo *,float);
void beca(Nodo *);

int main() {

menu1();


}

void menu1() {
    int op = 0;
    int cant = 0,cod=0;
    Nodo *lista = primero;
    Nodo *aux=NULL;
    while (op != 6) {
        cout <<"\n-------------MENU PRINCIPAL------------\n"
                << "1.ingresar.\n"
                << "2.Modificar.\n"
                << "3.Eliminar.\n"
                << "4.Mostrar.\n"
                << "5.informes\n"
                << "6.Salir.\n";
        cin>>op;
        cout << endl;


        switch (op) {
            case 1:
            {
                cout << "\nIngrese la cantidad de personas que desea ingresar:\n";
                cin>>cant;
                insertar1(lista, cant);
                break;
            }
            case 2:
            {

                cout<<"Digite el codigo de la persona a modificar: ";cin>>cod;cout<<endl;
                modificar(lista,cod);
                break;
            }
            case 3:
            {
                cout<<"Digite el codigo de la persona a eliminar: ";cin>>cod;cout<<endl;
                eliminar(lista,aux,cod);

                break;
            }
            case 4:
            {
                cout << "---------MOSTRANDO REGISTROS--------\n";
                cout << "CODIGO\tNOMBRE\tAPELLIDO\tCORREO\tNOTA\n";
                mostrar1(lista);
                break;
            }
            case 5:
            {
                informes();
                break;
            }
            case 6:
            {
                cout<<"\nGracias por utiliar el programa.\n";
                break;
            }
            default:
            {
                cout<<"\nHa ingresado una opcion invalida.\n";
                break;
            }
        }
    }
}

void insertar1(Nodo *&lista, int cant1) {
    int i = 0;
    int codigo = 0;
    string nom, ape, correo;
    float nota;
    Nodo *nuevo_nodo = new Nodo();
    if (cant1 != 0) {
        cout << "Ingrese el codigo:";
        cin>>codigo;
        cout << endl;
        cout << "Ingrese nombre: ";
        cin>>nom;
        cout << endl;
        cout << "Ingrese apellido: ";
        cin>>ape;
        cout << endl;
        cout << "Ingrese el correo: ";
        cin>>correo;
        cout << endl;
        cout << "Ingrese nota: ";
        cin>>nota;
        cout << endl;


        nuevo_nodo->Codigo = codigo;
        nuevo_nodo->nombre = nom;
        nuevo_nodo->apellido = ape;
        nuevo_nodo->correo = correo;
        nuevo_nodo->nota = nota;
        if (primero==NULL) {
            primero = nuevo_nodo;
            ultimo = nuevo_nodo;
            lista=primero;
            primero-> siguiente = primero;
            primero->anterior = ultimo;
        } else {
            ultimo-> siguiente = nuevo_nodo;
            nuevo_nodo->anterior = ultimo;
            nuevo_nodo-> siguiente = primero;
            ultimo = nuevo_nodo;
            primero->anterior = ultimo;
        }
        cant1--;
        insertar1(ultimo->siguiente, cant1);
    }
}

void modificar(Nodo *&lista,int cod){
    string nom, ape, correo;
    float nota;
    if (lista->siguiente==primero)
    {
        if (lista->Codigo==cod)
        {
            cout << endl;
            cout << "Ingrese nombre: ";
            cin>>nom;
            cout << endl;
            cout << "Ingrese apellido: ";
            cin>>ape;
            cout << endl;
            cout << "Ingrese el correo: ";
            cin>>correo;
            cout << endl;
            cout << "Ingrese nota: ";
            cin>>nota;
            cout << endl;
            lista->nombre = nom;
            lista->apellido = ape;
            lista->correo = correo;
            lista->nota = nota;
        }else{
            cout<<"\nNo se encontro el codigo.\n";
        }
    }else{
        if (lista->Codigo==cod)
        {
            cout << endl;
            cout << "Ingrese nombre: ";
            cin>>nom;
            cout << endl;
            cout << "Ingrese apellido: ";
            cin>>ape;
            cout << endl;
            cout << "Ingrese el correo: ";
            cin>>correo;
            cout << endl;
            cout << "Ingrese nota: ";
            cin>>nota;
            cout << endl;
            lista->nombre = nom;
            lista->apellido = ape;
            lista->correo = correo;
            lista->nota = nota;
        }else{
        	modificar(lista->siguiente ,cod);
        }
    }
    
}



void eliminar(Nodo *&lista,Nodo *&aux,int eli){
    if (lista->siguiente==primero)
    {
        if (lista->Codigo==eli)
        {
        	if(lista==primero)
           	{
           		lista=NULL;
				primero=lista;	
			}else if(lista==ultimo)
			{
			ultimo = ultimo->anterior;
			ultimo->siguiente = primero;
			primero->anterior = ultimo;	
			}
        }else{
            cout<<"\nNo se encontro el codigo.\n";
        }
    }else{
        if (lista->Codigo==eli)
        {
           	if(lista==primero)
           	{
           		lista=lista->siguiente;
				lista->anterior = ultimo;
				ultimo->siguiente = lista;
				primero=lista;	
			}else{
				aux->siguiente = lista-> siguiente ;
				lista->siguiente->anterior = aux;
			}
        }else{
        	aux=lista;
        	eliminar(lista->siguiente ,aux,eli);
        }
    }
}



void mostrar1(Nodo *lista) {
    if(lista==NULL){
    	cout<<"la lista esta vacia.\n";
	}else{
		if (lista->siguiente == primero) {
			cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
    } else {
        cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
        mostrar1(lista->siguiente);
    }
	}

}




void informes(){
    int op=0;
    Nodo *lista_derecha=primero;
    Nodo *lista_izquierda=ultimo;
    float prom=0;
    do{
        cout<<"\n1.Alumnos aprobados.\n"
        <<"2.Promedio asignatura.\n"
        <<"3.Alumnos por encima del promedio.\n"
        <<"4.Propuesta para beca.\n"
        <<"5.Salir.\n";
        cin>>op;

        switch(op){
            case 1:{
                cout<<"\nLos alumnos aprobados son:\n";
                aprobados(lista_derecha);
            }break;
            case 2:{
                cout<<"\nEl promedio de la asignatura es: ";
                double n=0;
                int cant=0;
                prom=promedio(lista_izquierda,n,cant);
                cout<<prom<<endl;
            }break;
            case 3:{
				cout<<"\nLos alumnos por encima del promedio son: \n";
				promedio_alto(lista_derecha,prom);
            }break;
            case 4:{
				cout<<"\nLos alumnos que van a ganar beca son: \n";
				beca(lista_izquierda);
            }break;
            case 5:{

            }break;
            default:{

            }break;

        }
    }while(op!=5);
}





void aprobados(Nodo *lista){
    if (lista->siguiente==primero)
    {
        if(lista->nota>2.9)
        {
            cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
        }
    }else{
        if (lista->nota>2.9)
        {
            cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
        }
        aprobados(lista->siguiente);
    }
}




float promedio(Nodo *lista,float n,int cant){
	n+=lista->nota;
	cant++;
	
	
	if(lista==primero)
	{
		return n/cant++;
	}else{
		promedio(lista->anterior,n,cant);
	}
}



void promedio_alto(Nodo *lista,float prom){
	if(lista==ultimo)
	{
		if(lista->nota>prom){
			cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
		}
	}else
	{
		if(lista->nota>prom){
			cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
		}
		promedio_alto(lista->siguiente,prom);
	}
}




void beca(Nodo *lista){
	if(lista==primero){
		
		if(lista->nota>4.5){
		cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
		}
	}else{
		if(lista->nota>4.5){
		cout <<lista->Codigo<<"\t"<<lista->nombre<<"\t"<<lista->apellido<<"\t"<<lista->correo<<"\t"<<lista->nota<<endl;
		}
		beca(lista->anterior);
	}
	
	
}

























