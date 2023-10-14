#include <iostream>
#include <regex>
#include <string>
#include <sstream>




using namespace std;

struct Nodo {
    string ced;
    string nom;
    string mail;
    string nota;


    Nodo *siguiente;
    Nodo *anterior;
} *primero, *ultimo;




void menup();
bool validarced(string);
bool validarnom(string);
bool validarmail(string);
bool validarnota(string);
void insertar(Nodo *&, int);
void modificar(Nodo *&, string);
void eliminar(Nodo *&, Nodo *&, string);
void buscar(Nodo *, string);
void mostrar(Nodo *, int);
void informes();
void aprobados(Nodo *);
void desaprobados(Nodo *);
float promedio(Nodo *, float, int);
void promedio_arriba(Nodo *, int);
void promedio_abajo(Nodo *, int);
void mejor(Nodo *, Nodo *);
void peor(Nodo *, Nodo *);

int main(int argc, char const *argv[]) {

    menup();
}

void menup() {
	bool sw=false;
    string ced;
    string nom;
    string mail;
    string nota;

    int op = 0;

    Nodo *lista = NULL;
    Nodo *aux = NULL;
    while (op != 7) {
        cout << "\n1.Agregar\n"
                << "2.Modificar\n"
                << "3.Eliminar\n"
                << "4.Buscar\n"
                << "5.Mostrar Todos\n"
                << "6.Informes\n"
                << "7.Salir\n";


        cin>>op;




        switch (op) {
            case 1:
            {
                int opi = 0, cant = 0;
                cout << "\n¿Desea ingresar mas de una persona?\n1.si\n2.no\n";
                cin>>opi;
                if (opi == 1) {
                    cout << "\nIngrese la cantidad de personas que desea ingresar.\n";
                    cin>>cant;
                } else {
                    cant = 1;
                }
                if (cant > 1) {
                    insertar(lista, cant);
                    cout << "\nSe han ingresado las personas con exito.\n";
                } else if (cant == 1) {
                    cant = 1;
                    insertar(lista, cant);
                    cout << "\nSe ha ingresado la persona con exito.\n";
                } else {
                    cout << "\nHa ingresado un dato invalido.\n";
                }
                break;
            }
            case 2:
            {
            	sw=false;
            	fflush(stdin);
                while (sw==false) {
                    cout << "\nIngrese la cedula de la persona a modificar.\n";
                    cin>>ced;
                    if (validarced(ced)) {
                        modificar(lista, ced);
                        sw=true;
                    } else {
                        cout << "\nHa ingresado una cedula invalida.\n";
                    }
                    fflush(stdin);
                }
                break;
            }
            case 3:
            {
            	sw=false;
            	fflush(stdin);
                while (sw==false) {
                    cout << "\nIngrese la cedula de la persona a eliminar.\n";
                    cin>>ced;
                    if (validarced(ced)) {
                        eliminar(lista, aux, ced);
                        sw=true;
                    } else {
                        cout << "\nHa ingresado una cedula invalida.\n";
                    }
                    fflush(stdin);
                }

                break;
            }
            case 4:
            {
            	sw=false;
                while (sw==false) {
                    cout << "\nIngrese la cedula de la persona a buscar.\n";
                    cin>>ced;
                    if (validarced(ced)) {
                        buscar(lista, ced);
                        sw=true;
                    } else {
                        cout << "\nHa ingresado una cedula invalida.\n";
                    }
                }
                break;
            }
            case 5:
            {
                int m = 0;
                mostrar(lista, m);
                break;
            }
            case 6:
            {
                informes();
                break;
            }
            case 7:
            {
                cout << "\nGracias por utilizar el programa.\n";
                break;
            }
            default:
            {
                cout << "\nHa ingresado un valor invalido.\n";
            }
        }
    }
}

void insertar(Nodo *&lista, int cant) {
    bool sw = false;
    if (cant != 0) {
        Nodo* nuevo = new Nodo();
        string ced;
        string nom;
        string mail;
        string nota;


        sw = false;
        while (sw == false) {
            cout << "\nIngrese la cedula de la persona.\n";
            cin>>ced;
            if (validarced(ced)) {
                cout << "\nCedula valida.\n";
                sw = true;
            } else {
                cout << "\nCedula invalida.\n";
            }

        }
        fflush(stdin);

        sw = false;
        while (sw == false) {
            cout << "\nIngrese el nombre de la persona.\n";
            getline(cin, nom);
            if (validarnom(nom)) {
                cout << "\nNombre valido.\n";
                sw = true;
            } else {
                cout << "\nNombre invalido.\n";
            }
            fflush(stdin);

        }
        fflush(stdin);

        sw = false;
        while (sw == false) {
            cout << "\nIngrese el correo de la persona.\n";
            cin>>mail;
            if (validarmail(mail)) {
                cout << "\nCorreo valido.\n";
                sw = true;
            } else {
                cout << "\nCorreo invalido.\n";
            }
            fflush(stdin);

        }
        fflush(stdin);
        sw = false;
        while (sw == false) {
            cout << "\nIngrese la nota de la persona.\n";
            cin>>nota;
            if (validarnota(nota)) {
                cout << "\nNota valida.\n";
                sw = true;
            } else {
                cout << "\nNota invalida.\n";
            }
            fflush(stdin);

        }
        fflush(stdin);
        nuevo->ced = ced;
        nuevo->nom = nom;
        nuevo->mail = mail;
        nuevo->nota = nota;
        if (primero == NULL) {
            primero = nuevo;
            lista = primero;
            primero-> siguiente = NULL;
            primero->anterior = NULL;
            ultimo = primero;
        } else {
            ultimo-> siguiente = nuevo;
            nuevo-> siguiente = NULL;
            nuevo-> anterior = ultimo;
            ultimo = nuevo;
        }
        cant--;
        insertar(lista->siguiente, cant);
    }
}

void modificar(Nodo *&lista, string ced) {
	bool sw=false;
    string nom;
    string mail;
    string nota;
    if (lista == NULL) {
        cout << "\nNo se encontró la persona.\n";
    } else {
    	fflush(stdin);
        if (lista->ced == ced) {
            while (sw == false) {
                cout << "\nIngrese el nombre de la persona.\n";
                getline(cin, nom);
                if (validarnom(nom)) {
                    cout << "\nNombre valido.\n";
                    sw = true;
                } else {
                    cout << "\nNombre invalido.\n";
                }
                fflush(stdin);

            }
            fflush(stdin);

            sw = false;
            while (sw == false) {
                cout << "\nIngrese el correo de la persona.\n";
                cin>>mail;
                if (validarmail(mail)) {
                    cout << "\nCorreo valido.\n";
                    sw = true;
                } else {
                    cout << "\nCorreo invalido.\n";
                }
                fflush(stdin);

            }
            fflush(stdin);
            sw = false;
            while (sw == false) {
                cout << "\nIngrese la nota de la persona.\n";
                cin>>nota;
                if (validarnota(nota)) {
                    cout << "\nNota valida.\n";
                    sw = true;
                } else {
                    cout << "\nNota invalida.\n";
                }
                fflush(stdin);

            }
        	lista->nom = nom;
        	lista->mail = mail;
        	lista->nota = nota;
        } else {
            modificar(lista->siguiente, ced);
        }
    }
}

void eliminar(Nodo *&lista, Nodo *&aux, string ced) {
    if (lista == NULL) {
        cout << "\nNo se encotro la persona.\n";
    } else {
        if (lista->ced == ced) {
            if (lista==primero){
            	if(primero->siguiente==NULL){
            		primero=NULL;
            		lista=NULL;
            		cout<<"\n---------LA LISTA QUEDO VACIA-------\n";
				}else{
					lista=lista->siguiente;
					lista->anterior=NULL;
					primero = primero-> siguiente ;
                    primero->anterior= NULL ;
				}
                } else  if (lista==ultimo){
                    aux -> siguiente = NULL ;
                    ultimo = aux;
                } else {
                    aux-> siguiente = lista-> siguiente ;
                    lista-> siguiente -> anterior = aux;
                }
                cout<<"\nSe elimino correctamente\n";
        } else {
            aux = lista;
            eliminar(lista->siguiente, aux, ced);
        }
    }
}

void buscar(Nodo *lista, string ced) {
    if (lista == NULL) {
        cout << "\nNo se encontró la persona.\n";
    } else {
        if (lista->ced == ced) {
            cout << "\nLa cedula de la persona es: " << lista->ced;
            cout << "\nEl nombre de la persona es: " << lista->nom;
            cout << "\nEl correo de la persona es: " << lista->mail;
            cout << "\nLa nota de la persona es: " << lista->nota;
            cout<<endl;
        } else {
            buscar(lista->siguiente, ced);
        }
    }
}

void mostrar(Nodo *lista, int m) {
    m++;
    if (lista != NULL) {
        cout << "\n-------PERSONA #" << m << "---------\n";
        cout << "\nLa cedula de la persona es: " << lista->ced;
        cout << "\nEl nombre de la persona es: " << lista->nom;
        cout << "\nEl correo de la persona es: " << lista->mail;
        cout << "\nLa nota de la persona es: " << lista->nota;
        cout << endl << endl;
        mostrar(lista->siguiente, m);

    }
}

bool validarced(string ced) {
    const regex expReg("^([0-9]{1,3}[.])?(\\d{1,3}[.]\\d{3}[.]\\d{3})$");
    return regex_match(ced, expReg);
}

bool validarnom(string nom) {
    const regex expReg("^[A-Z]+\\s[A-Z]+\\s[A-Z]+\\s?([A-Z]+)?$");
    return regex_match(nom, expReg);
}

bool validarmail(string mail) {
    const regex expReg("^(\\w+)[@]{1}([a-z]+)[.]{1}([a-z]{2,3})([.][a-z]{2})?$");
    return regex_match(mail, expReg);
}

bool validarnota(string nota) {
    const regex expReg("^([0-4]{1}[.][0-9]{1,2})?([5]{1}[.]?[0]{1,2})?$");
    return regex_match(nota, expReg);
}

void informes() {
    Nodo *lista = primero;
    float prom = 0;
    int cant = 0;
    int op = 0;
    while (op != 7) {
        cout << "\n1.Alumnos aprobados.\n"
                << "2.Alumnos desaprobados.\n"
                << "3.Promedio de Grupo.\n"
                << "4.Alumnos por encima del promedio y Alumnos por debajo del promedio.\n"
                << "5.Mejor Alumno.\n"
                << "6.Peor Alumno.\n"
                << "7.Salir.\n";
        cin>>op;

        switch (op) {
            case 1:
            {
                cout << "\nLos alumnos aprobados son: \n";
                aprobados(lista);
                break;
            }
            case 2:
            {
                cout << "\nLos alumnos desaprobados son: \n";
                desaprobados(lista);
                break;
            }
            case 3:
            {
                cout << "\nEl promedio del grupo es: \n";
                prom = promedio(lista, prom, cant);
                cout << prom;
                break;
            }
            case 4:
            {
                cout << "\nLos alumnos por encima del promedio son: \n";
                promedio_arriba(lista, prom);
                cout << endl << endl;
                cout << "\nLos alumnos por debajo del promedio son: \n";
                promedio_abajo(lista, prom);
                break;
            }
            case 5:
            {
                Nodo *aux2 = lista;
                cout << "\nEl mejor alumno es: \n";
                mejor(lista, aux2);
                break;
            }
            case 6:
            {
                Nodo *aux3 = lista;
                cout << "\nEl peor alumno es: \n";
                peor(lista, aux3);
                break;
            }
            case 7:
            {
                cout << "\nGracias por utilizar el programa.\n";
                break;
            }
            default:
            {
                cout << "\nHa ingresado un numero invalido.\n";
                break;
            }
        }


    }
}

void aprobados(Nodo *lista) {
    float n = 0;
    if (lista != NULL) {
        istringstream(lista->nota)>>n;
        if (n >= 3.0) {
            cout << "\nLa cedula de la persona es: " << lista->ced;
            cout << "\nEl nombre de la persona es: " << lista->nom;
            cout << "\nEl correo de la persona es: " << lista->mail;
            cout << "\nLa nota de la persona es: " << lista->nota;
            cout << endl << endl;
            aprobados(lista->siguiente);
        } else {
            aprobados(lista->siguiente);
        }
    }
}

void desaprobados(Nodo *lista) {
    if (lista != NULL) {
    	double n = std::stod(lista->nota);
        if (n < 3.0) {
            cout << "\nLa cedula de la persona es: " << lista->ced;
            cout << "\nEl nombre de la persona es: " << lista->nom;
            cout << "\nEl correo de la persona es: " << lista->mail;
            cout << "\nLa nota de la persona es: " << lista->nota;
            cout << endl << endl;
            desaprobados(lista->siguiente);
        } else {
            desaprobados(lista->siguiente);
        }
    }
}

float promedio(Nodo *lista, float n, int cant) {


    if (lista != NULL) {
    	float nota = 0;
    	istringstream(lista->nota)>>nota;
    	n += nota;
    	cant++;
        promedio(lista->siguiente, n, cant);
    } else {
        return n / cant++;
    }
}

void promedio_arriba(Nodo *lista, int prom) {
    float n = 0;
    if (lista != NULL) {
        istringstream(lista->nota)>>n;
        if (n > prom) {
            cout << "\nLa cedula de la persona es: " << lista->ced;
            cout << "\nEl nombre de la persona es: " << lista->nom;
            cout << "\nEl correo de la persona es: " << lista->mail;
            cout << "\nLa nota de la persona es: " << lista->nota;
            cout << endl << endl;
            promedio_arriba(lista->siguiente, prom);
        } else {
            promedio_arriba(lista->siguiente, prom);
        }
    }
}

void promedio_abajo(Nodo *lista, int prom) {
    float n = 0;
    if (lista != NULL) {
        istringstream(lista->nota)>>n;
        if (n < prom) {
            cout << "\nLa cedula de la persona es: " << lista->ced;
            cout << "\nEl nombre de la persona es: " << lista->nom;
            cout << "\nEl correo de la persona es: " << lista->mail;
            cout << "\nLa nota de la persona es: " << lista->nota;
            cout << endl << endl;
            promedio_abajo(lista->siguiente, prom);
        } else {
            promedio_abajo(lista->siguiente, prom);
        }
    }
}

void mejor(Nodo *lista, Nodo *aux) {
    float n = 0, m = 0;
    if (lista == NULL) {
        cout << "\nLa cedula de la persona es: " << aux->ced;
        cout << "\nEl nombre de la persona es: " << aux->nom;
        cout << "\nEl correo de la persona es: " << aux->mail;
        cout << "\nLa nota de la persona es: " << aux->nota;
        cout << endl << endl;
    } else {
        istringstream(lista->nota)>>n;
        istringstream(aux->nota)>>m;
        if (n > m) {
            aux = lista;
            mejor(lista->siguiente, aux);
        } else {
            mejor(lista->siguiente, aux);
        }
    }
}

void peor(Nodo *lista, Nodo *aux) {
    float n = 0, m = 0;
    if (lista == NULL) {
        cout << "\nLa cedula de la persona es: " << aux->ced;
        cout << "\nEl nombre de la persona es: " << aux->nom;
        cout << "\nEl correo de la persona es: " << aux->mail;
        cout << "\nLa nota de la persona es: " << aux->nota;
        cout << endl << endl;
    } else {
        istringstream(lista->nota)>>n;
        istringstream(aux->nota)>>m;
        if (n < m) {
            aux = lista;
            peor(lista->siguiente, aux);
        } else {
            peor(lista->siguiente, aux);
        }
    }
}