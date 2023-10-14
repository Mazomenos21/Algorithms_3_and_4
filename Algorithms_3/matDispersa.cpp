#include<iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void iniciar();
void leermat();
void calcular();
void mostrar();

int mat[100][100];
int disp[100][3];
int n,m,x,fd;

int main(){
    cout<<"Digite Numero de Filas: ";
    cin>>n;
    cout<<"Digite Numero de Columnas: ";
    cin>>m;
    cout<<"Digite Numero de Datos que desea ingresar: ";
    cin>>x;
    iniciar();
    leermat();
    calcular();
    mostrar();
    return 0;
}
void iniciar(){
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            mat[i][j]=0;
        }
    }
}
void leermat(){
    int f=0,c=0,sw=1,i=0;
    do{
        cout<<"Ingrese Fila: ";
        cin>>f;
        cout<<"Ingrese Columna: ";
        cin>>c;
        if (mat[f][c]==0){
            cout<<"Ingrese Numero en la Posición ["<<f<<","<<c<<"]:";
            cin>>mat[f][c];
            i++;
        }
        else{
            cout<<"ojo esa Posicion esta ocupada";
        }
        if (i==x){
            sw=0;
        }
    }while (sw==1);
}
void calcular(){
    fd=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]!=0){
                disp[fd][0]=i;
                disp[fd][1]=j;
                disp[fd][2]=mat[i][j];
                fd++;
            }
        }
    }
}
void mostrar(){
    cout<<"Matriz Original Dispersa:";
    for(int i=0; i<n; i++){
        cout<<endl;
        for(int j=0; j<m; j++){
            cout<<mat[i][j]<<" ";
        }
    }
    cout<<"\nMatriz dispersa:\n";
    cout<<"F,C->Dato\n";
    for(int i=0; i<fd; i++){
        cout<<disp[i][0]<<","<<disp[i][1]<<"->"<<disp[i][2]<<endl;
    }
}