#include <iostream>
using namespace std;
//ordemantiento de listas
struct Node{
    int data;
    Node* next;
    Node(int val):data(val),next(nullptr){}
};
//funcion para insertar un nodo al principio de la lista
void insertarInicioList(Node* &head,int val){
    Node* nuevoNodo=new Node(val);
    nuevoNodo->next=head;
    head=nuevoNodo;
};
//funcion para impirmir la lista
void imprimirLista(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
};
//funcion para odernanr la lista
void ordeLista(Node* &head){
    if (head==nullptr || head ->next==nullptr)
    return;
    Node*sorted=nullptr;
    Node* current=head;
    while(current!=nullptr){
        Node* nextNode=current->next;
        if (sorted==nullptr ||sorted->data>=current->data){
            current->next=sorted;
            sorted=current;
        }
        else {
            Node*temp=sorted;
            while(temp->next!=nullptr && temp->next->data<current->data){
                temp=temp->next;
            }
            current->next=temp->next;
            temp->next=current;
        }
        current=nextNode;
    }
    head=sorted;
};
int main(){
    Node* head=nullptr;
    insertarInicioList(head,50);
    insertarInicioList(head,100);
    insertarInicioList(head,24);
    insertarInicioList(head,1);
    cout<<"lista original es: "<<endl;
    imprimirLista(head);
    ordeLista(head);
    cout<<"lista Ordenada es: "<< endl;
    imprimirLista(head);
    return 0;
} 