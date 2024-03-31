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
    return 0;
}
//arbol Binario
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value):data(value),left(nullptr),right(nullptr)
};
Node* buscar(Node* root, int key){
    if(root==nullptr||root->data==key){
        return root;
    }
        if(root->data<key){
            return buscar()
        }
}
//interpolacion
//hasing