#include <iostream>
#include <cmath>




using namespace std;



int factorial(double);
int recursividad(double);
void Serie(double);
int Serierecursivo(double);

int main(){
	double n;
	int op;
		cout<<"El valor para calcular el factorial ";
		cin>>n;
		cout<<"\n1.para normal\n2.para recursividad\n3.Para fibonacci normal\n4.Para fibonacci recursivo\n";cin>>op;
		if(op==1)
		{
			cout<<"El factorial en ciclos es: "<<factorial(n)<<endl;	
		}else if(op==2)
		{
			cout<<"El factorial en ciclos es: "<<recursividad(n)<<endl;
		}else if(op==3){
			cout<<"la serie de fibonacci es: ";
			Serie(n);
		}else if ( op==4)
		{
			for(int j=0;j<n;j++)
			{
				cout<<"["<<Serierecursivo(j)<<"]";
			}
		}
	
		
	
}



int factorial(double x){
	double fac=1;
	for(int i=1;i<=x;i++)
	{
		fac*=i;
	}
	return fac;
}



int recursividad(double x){
	if(x==0){
		
		return 1;
	}else{
		return x*recursividad(x-1);
	}
}

void Serie(double x)
{
	int aux=1,fib=0;
	
	if(x>0){
		for(int i=1;i<=x;i++)
		{
			cout<<"["<<fib<<"]";
			aux+=fib;
			fib=aux-fib;
		}
	}
	else{
		cout<<"el numero debe ser mayor a cero"<<endl;
	}
}


int Serierecursivo(double x)
{
	if(x<2)
	{
		return x;
	}else
	{
		return (Serierecursivo(x-1)+Serierecursivo(x-2));
	}
	
}



