#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <conio.h>



using namespace std;
#define Numero_operadores 6 //definir la cantidad de operadores
const string operadores[Numero_operadores] = {"+", "-", "*", "/", "%", "^"};//crear un vector con los operadores y el tamaño se lo dí al definir Numero_operadores 6
int prioridad_pila[Numero_operadores] = {1, 1, 2, 2, 2, 3};//definir la prioridad en la pila
 
bool Ser_operador( const string );//definir la funcion ser operador que me retornará un true o un false, aparte colocaré un string que es el caracter que será constante
int prioridad( const string );//funcion prioridad
int postfijo(const string);
int prefijo(const string);
void menup();
int main()

{
	menup();
}

void menup()
{
	int menu;
	string infijo;
	while(menu!=3)
	{
		cout<<"-------------MENU-----------"<<endl;
		cout<<"\t1.Ingresar infijo.\n"<<
		"\t2.Pasar de infijo a postfijo y mostrar resultado.\n"<<
		"\t3.Pasar de infijo a prefijo y mostrar resultado.\n";
		cin>>menu;
		
		
		switch(menu)
		{
			case 1:{
				cout<<"ingrese el infijo: ";
				cin>>infijo;
				break;
			}
			case 2:{
				postfijo(infijo);
				break;
			}
			case 3:{
				prefijo(infijo);
				break;
			}
			default:{
				if(menu<1 || menu>3){
					cout<<"ha ingresado un numero invalido\n";
				}
				if(menu==3){
					cout<<"Gracias por utilizar el programa\n";
				}
				break;
			}
		}
	}
}
int postfijo(string infijo){
	
	string postfija,caracter;
	stack <string> Pila_operadores;//crear pila para los operadores
	stack <double> Pila_resultado;//crear pila para los operandos, para el resultado
	char c;
	size_t i;
	double A, B;
	
	for ( i = 0; i < infijo.size(); i++ ) {
		c = infijo[i];
		caracter.clear();
		caracter += c;
 
		/* es un espacio: despreciar */
		if ( c == ' ' ) continue;
 
		cout << "\nAnalizando caracter: " << c << endl;
 
		/* es un carácter numérico: pasar al posfijo */
		if ( c >= '0' && c <= '9' ) {
			cout << "\teste caracter es numero\n \tpasado a posfijo\n" << endl << endl;
			postfija = postfija + " " + c;
			continue;
		}
 
		/* si se lee un operador: sacar de la pila y pasar al postfijo
		 * todos los operadores con una precedencia mayor o igual a la 
		 * suya, y depositar el mismo en la pila */
		if ( Ser_operador( caracter ) ) {
			cout << "\n\tes operador:" << endl;
			while ( !Pila_operadores.empty() && prioridad( Pila_operadores.top() ) >= prioridad( caracter ) ) {
				cout << "\tpasado operador "<<Pila_operadores.top()<<" de la pila a posfijo" << endl;
				postfija = postfija + " " + Pila_operadores.top();
				Pila_operadores.pop();
			}
			Pila_operadores.push( caracter );
			cout << "\tcolocar " << caracter << " en la pila" << endl << endl;
			continue;
		}
 
		/* si se lee "(": colocar en la pila */
		if ( caracter == "(" ) {
			cout << "pasando a postfijo" << endl << endl;
			Pila_operadores.push( caracter );
			continue;
		}
 
		/* si se lee ")": retirar de la pila hasta encontrar '(', y pasar 
		 * los elementos retirados a posfijo, luego descartar el "(" */
		if ( caracter == ")" ) {
			while ( !Pila_operadores.empty() && Pila_operadores.top() != "(" ) {
				cout << "\tpasando operador "<<Pila_operadores.top() <<" de la pila al postfijo" << endl << endl;
				postfija = postfija + " " + Pila_operadores.top();
				Pila_operadores.pop();
			}
			if ( !Pila_operadores.empty() )
				Pila_operadores.pop();	/* descartar el "(" */
		}
	}
 
	/* extraer de la pila cualquier operador restante y pasarlo a la cadena posfijo */
	while ( !Pila_operadores.empty() ) {
		cout << "Pasando operador " + Pila_operadores.top() + " de la pila al postfijo" << endl << endl;
		postfija = postfija + " " + Pila_operadores.top();
		Pila_operadores.pop();
	}
 
	/* Imprimir el posfijo */
	cout << "Postfijo es: \n\t" << postfija << endl << endl;
 
	/****************************************************************
	  SEGUNDA PARTE: Procesar la cadena posfijo, y devolver resultado
	 ****************************************************************/
 
	A = 0;
	cout << "Evaluando la expresion ..." << endl;
	for ( i = 0; i < postfija.size(); i++ ) {
 
		c = postfija[i];
		caracter.clear();
		caracter += c;
 
		/* si se lee un operando (caracter numerico), depositar en la pila */
		if ( c >= '0' && c <= '9' ) {
			Pila_resultado.push( c - '0' );
			continue;
		}
 
		/* si se lee un operador binario, poner en A y B los últimos dos argumentos 
		 * de la pila y operarlos, guardando el resultado en la pila */
		if ( Ser_operador( caracter) ) {
			if ( !Pila_resultado.empty() ) {
				B = Pila_resultado.top();
				Pila_resultado.pop();
			}
			else {
				cout << "Argumentos insuficientes para '" << c << "'" << endl;
				return -1;
			}
 
			if ( !Pila_resultado.empty() ) {
				A = Pila_resultado.top();
				Pila_resultado.pop();
			}
			else {
				cout <<-1;
			}
 
			cout << "\toperar " << A << caracter << B << " = ";
			if ( caracter == "+" ) {
				A += B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "-" ) {
				A -= B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "*" ) {
				A *= B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "/" ) {
				A /= B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "%" ) {
				A = (int )A % (int )B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "^" ) {
				A = pow(A, B);
				Pila_resultado.push( A );
			}
			cout << A << endl;
		}
	}
 
	if ( !Pila_resultado.empty() )
		cout << endl << "El resultado es: " << Pila_resultado.top() << endl;
		return 0;
}



int prefijo(string infijo)
{
	
	string prefija,caracter;
	stack <string> Pila_operadores;//crear pila para los operadores
	stack <double> Pila_resultado;//crear pila para los operandos, para el resultado
	char c;
	size_t i;
	double A, B;
	
	for ( i =infijo.size(); i >0; i-- ) {
		c = infijo[i];
		caracter.clear();
		caracter += c;
 
		/* es un espacio: despreciar */
		if ( c == ' ' ) continue;
 
		cout << "\nAnalizando caracter: " << c << endl;
 
		/* es un carácter numérico: pasar al posfijo */
		if ( c >= '0' && c <= '9' ) {
			cout << "\teste caracter es numero\n \tpasado a prefijo\n" << endl << endl;
			prefija = prefija + " " + c;
			continue;
		}
 
		/* si se lee un operador: sacar de la pila y pasar al postfijo
		 * todos los operadores con una precedencia mayor o igual a la 
		 * suya, y depositar el mismo en la pila */
		if ( Ser_operador( caracter ) ) {
			cout << "\n\tes operador:" << endl;
			while ( !Pila_operadores.empty() && prioridad( Pila_operadores.top() ) >= prioridad( caracter ) ) {
				cout << "\tpasado operador "<<Pila_operadores.top()<<" de la pila a prefijo" << endl;
				prefija = prefija + " " + Pila_operadores.top();
				Pila_operadores.pop();
			}
			Pila_operadores.push( caracter );
			cout << "\tcolocar " << caracter << " en la pila" << endl << endl;
			continue;
		}
 
		/* si se lee "(": colocar en la pila */
		if ( caracter == ")" ) {
			cout << "pasando a prefijo" << endl << endl;
			Pila_operadores.push( caracter );
			continue;
		}
 
		/* si se lee ")": retirar de la pila hasta encontrar '(', y pasar 
		 * los elementos retirados a posfijo, luego descartar el "(" */
		if ( caracter == "(" ) {
			while ( !Pila_operadores.empty() && Pila_operadores.top() != ")" ) {
				cout << "\tpasando operador "<<Pila_operadores.top() <<" de la pila al prefijo" << endl << endl;
				prefija = prefija + " " + Pila_operadores.top();
				Pila_operadores.pop();
			}
			if ( !Pila_operadores.empty() )
				Pila_operadores.pop();	/* descartar el "(" */
		}
}
 
	/* extraer de la pila cualquier operador restante y pasarlo a la cadena posfijo */
	while ( !Pila_operadores.empty() ) {
		cout << "Pasando operador " + Pila_operadores.top() + " de la pila al prefijo" << endl << endl;
		prefija = prefija + " " + Pila_operadores.top();
		Pila_operadores.pop();
	}
 
	/* Imprimir el posfijo */
	cout << "Prefijo es: \n\t" << prefija << endl << endl;
 
	/****************************************************************
	  SEGUNDA PARTE: Procesar la cadena prefijo, y devolver resultado
	 ****************************************************************/
 
	A = 0;
	cout << "Evaluando la expresion ..." << endl;
	for ( i = 0; i < prefija.size(); i++ ) {
 
		c = prefija[i];
		caracter.clear();
		caracter += c;
 
		/* si se lee un operando (caracter numerico), depositar en la pila */
		if ( c >= '0' && c <= '9' ) {
			Pila_resultado.push( c - '0' );
			continue;
		}
 
		/* si se lee un operador binario, poner en A y B los últimos dos argumentos 
		 * de la pila y operarlos, guardando el resultado en la pila */
		if ( Ser_operador( caracter) ) {
			if ( !Pila_resultado.empty() ) {
				A = Pila_resultado.top();
				Pila_resultado.pop();
			}
			else {
				cout << "Argumentos insuficientes para '" << c << "'" << endl;
				return -1;
			}
 
			if ( !Pila_resultado.empty() ) {
				B = Pila_resultado.top();
				Pila_resultado.pop();
			}
			else {
				cout <<-1;
			}
 
			cout << "\toperar " << A << caracter << B << " = ";
			if ( caracter == "+" ) {
				A += B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "-" ) {
				A -= B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "*" ) {
				A *= B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "/" ) {
				A /= B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "%" ) {
				A = (int )A % (int )B;
				Pila_resultado.push( A );
			}
			else if ( caracter == "^" ) {
				A = pow(A, B);
				Pila_resultado.push( A );
			}
			cout << A << endl;
		}
	}
 
	if ( !Pila_resultado.empty() )
		cout << endl << "El resultado es: " << Pila_resultado.top() << endl;
		return 0;
}





bool Ser_operador( const string caracter ) {//le mando el caracter en específico
 
	for ( int i = 0; i < Numero_operadores; i++ )//hasta que sea menor a 6 que es la cantidad de operadores
		if ( operadores[i] == caracter ) //si el caracter que mande, es alguno de los 6 operadores que me retorne verdadero si no que me retoirne falso
			return true;
 
	return false;
}






int prioridad( const string caracter ) {//le mando el caracter para que me devuelva la prioridad del operador
 
	for ( int i = 0; i < Numero_operadores; i++ )//hasta que sea menor a 6 que son los operadores
	{
		if ( operadores[i] == caracter ) //si el caracter es igual al operador en la posicion sub i 
			{
				return prioridad_pila[i];//me retorna el valor o la herencia del operador en la posicion sub i
			}
	}
 
	return -1;
}


