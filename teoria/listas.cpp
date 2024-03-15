#include<iostream>
using namespace std;
template<typename T>//<typename T> es el que la da posicion de donde se va a crear
class Nodo{
private:
T dato;
Nodo* next;

public:
Nodo(){//metodo constructor
    next=NULL;
}
Nodo(T d){
    dato=d;
    next=NULL;
}
T get_Dato(){
    return dato;
}
void set_Dato(t d ){
dato=d;
}
Nodo<T>* get_Next(){
    return next;
}
void set_Next(Nodo<T>* n){
next=n;
}
};
template<typename T>
class Listas
{
private:
Nodo<T>*ptr;
int size;
public:
Lista(){
    prt=NULL;
    size=0;
}

};