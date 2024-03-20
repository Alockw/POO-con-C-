#include <iostream>
using namespace std;
//ordemantiento de listas
struct Node{
    string valor;
    string pinta;
    Node* next;
    Node(string valor, string pinta):valor(valor),pinta(pinta),next(nullptr){}
};
//funcion para insertar un nodo al principio de la lista
void insertarInicioList(Node* &head,string valor, string pinta){
    Node* nuevoNodo=new Node(pinta);
    nuevoNodo->next=head;
    head=nuevoNodo;
};
//funcion para impirmir la lista
void imprimirLista(Node* head){
    while(head!=nullptr){
        cout<<head->valor<<" ";
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
        if (sorted==nullptr ||sorted->pinta>=current->pinta){
            current->next=sorted;
            sorted=current;
        }
        else {
            Node*temp=sorted;
            while(temp->next!=nullptr && temp->next->pinta<current->pinta){
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
    insertarInicioList(head,"5","diamante");
    insertarInicioList(head,"1","corazon");
    insertarInicioList(head,"9","picas");
    insertarInicioList(head,"3","treboles");
    cout<<"lista original es: "<<endl;
    imprimirLista(head);
    ordeLista(head);
    cout<<"lista Ordenada es: "<< endl;
    imprimirLista(head);
    return 0;
} 