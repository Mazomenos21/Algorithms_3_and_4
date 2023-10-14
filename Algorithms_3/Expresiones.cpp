//  Expresiones.cpp
//  Created by Henry Villada on 6/09/22.

#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool validarplacacarro(string);
bool validarplacamoto(string);

int main() {
    string placa,tipo;
    
    while (true){
        cout<<"Tipo de Vehiculo <<C>> Carro <<M>> Moto: ";
        cin>>tipo;
        if (tipo=="C" | tipo=="c"){
            cout<<"ingrese la Placa: ";
            cin>>placa;
            if (validarplacacarro(placa)){
                cout<<"Placa Valida"<<endl;
            }
            else{
                cout<<"Placa Invalida"<<endl;
            }
        }
        else{
            if (tipo=="M" | tipo=="m"){
                cout<<"ingrese la Placa: ";
                cin>>placa;
                if (validarplacamoto(placa)){
                    cout<<"Placa Valida"<<endl;
                }
                else{
                    cout<<"Placa Invalida"<<endl;
                }
            }
        }
    }
}
bool validarplacacarro(string placa){
    const regex expReg("[A-Z]{3}[-]\\d{3}");
    return regex_match(placa,expReg);
}
bool validarplacamoto(string placa){
    const regex expReg("[A-Z]{3}[-]\\d{2}[A-Z]");
    return regex_match(placa,expReg);
}
