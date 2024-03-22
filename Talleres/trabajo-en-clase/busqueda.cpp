#include<vector>
#include<iostream>
using namespace std;
//metodos de busqueda
//Lineas:
//recorre secuencial mente la estructura y busca el dato que se pide encontrar
bool busquedaLineal(const vector<int> array,int target){
    for(int element:array){
        if(element==target){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int>numbers={1,2,3,4,5,6,7,8,9,10};
    int target=3;
    if (busquedaLineal(numbers,target)){
        cout<<"el elemento "<<target<<" esta en el array"<< endl;
    }
    else{
        cout<<"el elemento "<<target<<" no esta en el array"<< endl;
    }
}
//arbol Binario
//interpolacion
//hasing