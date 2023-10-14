#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <regex>

using namespace std;


struct Nodo{
    int date;
    Nodo *next;
    Nodo *prev;
}*first_num,*last_num,*first_den,*last_den,*first_add,*last_add,*first_rest,*last_rest,*first_a,*last_a
,*first_b,*last_b,*first_div,*last_div;

void menu();
void Addition(Nodo *,Nodo *,int );
void rest(Nodo *,Nodo *,int);
void insertNodo(int,Nodo *&,Nodo *&);
void equalize(Nodo *&,Nodo *&,Nodo *&,Nodo *&);
int counter(Nodo *,int);
void Add_list(string ,Nodo *&,Nodo *&,int);
void show_right(Nodo *);
void show_left(Nodo *);
void multiplication(Nodo *&,Nodo *&,int ,int);
void Ask_num(string,Nodo *&, Nodo *&);
void division(Nodo *&,Nodo *&,int);
void multi_div(Nodo *&,int,int);

//vaciar la lista
void Vaciar(Nodo *&Lis){
    if (Lis== nullptr){
        return;
    }
    else{
        while (Lis!= nullptr){
            Nodo *aux=Lis;
            Lis=Lis->next;
            delete aux;
        }
    }
}
bool correct_num(string num) {
    regex expReg("^(\\d)*$");
    return regex_match(num, expReg);
}





//all variables for the operations
int partial_sum=0,residue=0,accumulated=0,accumulated_multi=0;
//create two variables for the counter of each
int counter_n=0,counter_d= 0,counter_aux_d;
int total_sum[20];
int total_rest[20];
int total_multi[30];
int total_div;
bool sw=false;
int numerator=0,denominator=0;
string num,den;

int main()
{
    menu();
}

//main menu
void menu(){
    int op=0;
    do {
        sw=false;
        //main menu for to enter the numerator and denominator
        cout<<"PROCURA UTILIZAR EL NUMERO CON MAS DIGITOS DE NUMERADOR,GRACIAS.\n";
        cout<<"----------INGRESE LOS DATOS------------\n";
        cout<<"ingrese el numerador: ";
        Ask_num(num,first_num,last_num);
        sw=false;
        cout<<"ingrese el denominador: ";
        Ask_num(den,first_den,last_den);
        counter_n=counter(first_num,0);
        counter_d=counter(first_den,0);
        counter_aux_d=counter_d;
        //equalize the lists for the operations
        equalize(first_num,last_num,first_den,last_den);

        show_left(last_num);
        show_left(last_den);
        //system pause
        system("pause");
        cout<<"-----------BIENVENIDO A LA CALCULADORA :) --------------\n";
        cout<<"1.Sumar.\n"
            <<"2.Restar.\n"
            <<"3.Multiplicar.\n"
            <<"4.Dividir.\n"
            <<"5.Salir.\n";
        cin>>op;
        cout<<endl;

        switch(op){
            case 1:{
                //send the two lists and an accountant
                cout<<"\nSe ha completado la suma.\n";
                cout<<"La suma total de los datos es: ";
                Addition(first_num,first_den,0);
                show_left(last_add);
                cout<<endl<<endl<<endl;
                break;
            }
            case 2:{
                //send the two lists and an accountant
                cout<<"\nSe ha completado la resta.\n";
                cout<<"La resta total de los datos es: ";
                rest(first_num,first_den,0);
                break;
            }
            case 3:{
                cout<<"\nSe ha completado la multiplicacion.\n";
                cout<<"La multiplicacion total de los datos es: ";
                multiplication(first_num,first_den,0,0);

                break;
            }
            case 4:{
                //send the two lists and an accountant
                cout<<"\nSe ha completado la division.\n";
                cout<<"La division total de los datos es: ";
                division(last_num,last_den,0);
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
        Vaciar(first_a);
        Vaciar(first_b);
        Vaciar(first_add);
        Vaciar(first_den);
        Vaciar(first_num);
        Vaciar(first_rest);

        last_num=nullptr;
        last_den=nullptr;
        last_a=nullptr;
        last_add=nullptr;
        last_b=nullptr;
        last_rest=nullptr;



        system("pause");
        system("cls");
    }while(op!=5);
}

void Ask_num(string n,Nodo *&first,Nodo *&last)
{
    if(sw==true)
    {
        return;
    }else{
        cin>>n;cout<<endl;
        if (correct_num(n))
        {
            sw=true;
            Add_list(n,first,last,n.size());
        }else{
            cout<<"\nHa ingresado algo diferente a un entero, vuelve a intentar.\n";
            cout<<"\nIngrese el numero nuevamente:\t";
            Ask_num(n,first,last);
        }
    }
}
//show the lists
void show_left(Nodo *list){
    if (list!=nullptr) {
        cout << list->date<<" ";
        show_left(list->prev);
    }else{
        cout<<"\n Se ha mostrado toda la lista.\n";
    }
}

void show_right(Nodo *list){
    if (list!=nullptr) {
        cout << list->date<<" ";
        show_right(list->next);
    }else{
        cout<<"\n Se ha mostrado toda la lista.\n";
    }
}


//add nodes to the lists
void Add_list(string num,Nodo *&first,Nodo *&last,int i)
{
    //create char for one node
    char s;
    int l;
    //recursion
    if (i==0){
        return;
    }else
    {
        i--;
        s = num[i];
        l = atoi(&s);
        insertNodo(l,first,last);
        //take the decimal and convert to int       4532/10=453.2    ->   num=453
        Add_list(num,first,last,i);
    }
}


//add nodes to the lists one by one
void  insertNodo (int n,Nodo *&first,Nodo *&last){
    //create new nodo
    Nodo* nuevo = new  Nodo ();
    //metod of doubly bound for numerator
    nuevo->date=n;
    nuevo->next=NULL;
    nuevo->prev=NULL;
    if (first == NULL ){
        first = nuevo;
        first -> next = NULL ;
        first -> prev = NULL ;
        last = first;
    } else {
        last-> next = nuevo;
        nuevo-> next = NULL ;
        nuevo-> prev = last;
        last = nuevo;
    }
}

//counter for know how many nodes have
int counter(Nodo *list,int i)
{
    if(list== nullptr)
    {
        return i;
    }else{
        i++;
        list=list->next;
        counter(list,i);
    }
}


//equalize the lists for have a best operations
void equalize(Nodo *&list_numerator,Nodo *&lastn,Nodo *&list_denominator,Nodo *&lastd){
    int s=0;
    if (counter_n==counter_d)
    {
        return;
    }else{
        //if numerator is greater than denominator
        if(counter_n>counter_d)
        {
            if (list_denominator != nullptr) {
                if (list_denominator->next==NULL)
                {
                    counter_d++;
                    insertNodo(s,list_denominator,lastd);
                    equalize(list_numerator,lastn,list_denominator->next,lastd);
                }else
                {
                    equalize(list_numerator,lastn,list_denominator->next,lastd);
                }

            }
        }
        //if denominator is greater than numerator
        if(counter_d>counter_n)
        {
            if (list_numerator != nullptr) {
                if (list_numerator->next==NULL)
                {
                    counter_n++;
                    insertNodo(s,list_numerator,lastn);
                    equalize(list_numerator->next,lastn,list_denominator,lastd);
                }else
                {
                    equalize(list_numerator->next,lastn,list_denominator,lastd);
                }
            }
        }
    }
}


//operation addition
void Addition(Nodo *currentnumerator,Nodo *currentdenominator,int i)

{
    int r;

    if (currentnumerator==nullptr && currentdenominator== nullptr)
    {
        return;
    }else
    {
        accumulated=currentnumerator->date+residue;
        partial_sum=accumulated+currentdenominator->date;

        if(nullptr == currentnumerator->next)
        {
            if (currentdenominator->next!= nullptr)
            {
                if (partial_sum<10)
                {
                    i++;
                    residue=0;
                    total_sum[i]=partial_sum;
                    r=total_sum[i];
                    insertNodo(r,first_add,last_add);
                    insertNodo(currentdenominator->next->date,first_add,last_add);
                    return;
                }else{
                    i++;
                    residue=0;
                    total_sum[i]=partial_sum%10;
                    r=partial_sum/10+(currentdenominator->next->date);
                    insertNodo(total_sum[i],first_add,last_add);
                    insertNodo(r,first_add,last_add);
                    return;
                }
            }else
            {
                if (partial_sum<10)
                {
                    residue=0;
                    total_sum[i]=partial_sum;
                    r=total_sum[i];
                }else{
                    residue=0;
                    total_sum[i]=partial_sum%10;
                    r=partial_sum/10;
                    insertNodo(total_sum[i],first_add,last_add);
                }
            }
        }else if(partial_sum>9)
        {
            total_sum[i]=partial_sum%10;
            residue=partial_sum/10;
            r=total_sum[i];
        }else{
            total_sum[i]=partial_sum;
            residue=0;
            r=total_sum[i];
        }
        i++;
        currentnumerator=currentnumerator->next;
        currentdenominator=currentdenominator->next;
        insertNodo(r,first_add,last_add);
        Addition(currentnumerator,currentdenominator,i);
    }
}

//operation rest
void rest(Nodo *currentnumerator,Nodo *currentdenominator,int i)

{
    int r;
    if (currentnumerator==nullptr)
    {
        show_left(last_rest);
        cout<<endl<<endl<<endl;
    }else
    {
        if(currentnumerator->date<currentdenominator->date)
        {
            currentnumerator->date=currentnumerator->date+10;
            currentnumerator->next->date=currentnumerator->next->date-1;
            total_rest[i]=currentnumerator->date-currentdenominator->date;
            r=total_rest[i];
        }else{
            total_rest[i]=currentnumerator->date-currentdenominator->date;
            r=total_rest[i];
        }
        i++;

        currentnumerator=currentnumerator->next;
        currentdenominator=currentdenominator->next;
        insertNodo(r,first_rest,last_rest);
        rest(currentnumerator,currentdenominator,i);
    }
}



void multiplication(Nodo *&numerator,Nodo *&denominator,int i,int j)
{
    if (j==counter_aux_d)
    {
        if (counter_aux_d==1)
        {
            show_left(last_a);
            counter_aux_d=0;
        }else if(counter_aux_d>1)
        {
            show_left(last_a);
            counter_aux_d=0;
        }
        return;
    }else if (denominator==first_den)
    {
        total_multi[i]=accumulated_multi+(numerator->date*denominator->date);
        if (total_multi[i]>9 && numerator->next == nullptr)
        {
            insertNodo(total_multi[i]%10,first_a,last_a);
            insertNodo(total_multi[i]/10,first_a,last_a);
            accumulated_multi=0;
        }else if (total_multi[i]<10 && numerator->next== nullptr)
        {
            insertNodo(total_multi[i],first_a,last_a);
            accumulated_multi=0;
        }
        else if (total_multi[i]>9)
        {
            insertNodo(total_multi[i]%10,first_a,last_a);
            accumulated_multi=total_multi[i]/10;
            i++;
            multiplication(numerator->next,denominator,i,j);
        }else {
            insertNodo(total_multi[i],first_a,last_a);
            accumulated_multi = 0;
            i++;
            multiplication(numerator->next,denominator,i,j);
        }
        j++;
        multiplication(first_num,denominator->next,0,j);
    }

    else if (denominator!=first_den && counter_aux_d>1)
    {
        total_multi[i]=accumulated_multi+(numerator->date*denominator->date);
        if (i<j)
        {
            accumulated_multi=0;
            insertNodo(0,first_b,last_b);
            i++;
            multiplication(numerator,denominator,i,j);
        }
        else if (total_multi[i]>9 && numerator->next == nullptr)
        {
            insertNodo(total_multi[i]%10,first_b,last_b);
            insertNodo(total_multi[i]/10,first_b,last_b);
            accumulated_multi=0;
        }else if (total_multi[i]<10 && numerator->next== nullptr)
        {
            insertNodo(total_multi[i],first_b,last_b);
            accumulated_multi=0;
        }
        else if (total_multi[i]>9)
        {
            insertNodo(total_multi[i]%10,first_b,last_b);
            accumulated_multi=total_multi[i]/10;
            i++;
            multiplication(numerator->next,denominator,i,j);
        }else {
            insertNodo(total_multi[i],first_b,last_b);
            accumulated_multi = 0;
            i++;
            multiplication(numerator->next,denominator,i,j);
        }
        if (j<counter_aux_d)
        {
            Addition(first_a,first_b,0);
            last_a=NULL;
            last_b=NULL;
            Vaciar(first_a);
            Vaciar(first_b);

            while(first_add!=NULL)
            {
                insertNodo(first_add->date, first_a,last_a);
                first_add=first_add->next;
            }
            last_add=NULL;
            Vaciar(first_add);
        }
        j++;
        multiplication(first_num,denominator->next,0,j);
    }
}


void division(Nodo *&dividend,Nodo *&divider,int i)
{
    if (i==counter_aux_d)
    {
        show_left(last_div);
    }else
    {
        if (divider->date==0){
            while(divider->date==0)
            {
                divider=divider->prev;
            }
        }
        int div;
        if (dividend->date<divider->date)
        {
            int conca;
            conca=(dividend->date*10)+(dividend->prev->date);
            div =conca/divider->date;
            dividend=dividend->prev;
        }else{
            div=dividend->date/divider->date;
        }
        insertNodo(div,first_div,last_div);
        multi_div(first_den,div,0);
        if (i== 0)
        {
            rest(first_num,first_a,0);
        }else{
            rest(first_b,first_a,0);
        }
        Vaciar(first_a);
        Vaciar(first_b);
        while(first_rest!=nullptr)
        {
            insertNodo(first_rest->date,first_b,last_b);
            first_rest=first_rest->next;
        }
        Vaciar(first_rest);
        division(last_b,last_den,i++);
    }
}

void multi_div(Nodo *&numerator,int denominator,int i)
{
    if (nullptr == numerator)
    {
        return;
    }else
    {
        total_multi[i]=accumulated_multi+(numerator->date*denominator);
        if (total_multi[i]>9 && numerator->next == nullptr)
        {
            insertNodo(total_multi[i]%10,first_a,last_a);
            insertNodo(total_multi[i]/10,first_a,last_a);
            accumulated_multi=0;
        }else if (total_multi[i]<10 && numerator->next== nullptr)
        {
            insertNodo(total_multi[i],first_a,last_a);
            accumulated_multi=0;
        }
        else if (total_multi[i]>9)
        {
            insertNodo(total_multi[i]%10,first_a,last_a);
            accumulated_multi=total_multi[i]/10;
            i++;
            multi_div(numerator->next,denominator,i);
        }else {
            insertNodo(total_multi[i],first_a,last_a);
            accumulated_multi = 0;
            i++;
            multi_div(numerator->next,denominator,i);
        }
    }
}