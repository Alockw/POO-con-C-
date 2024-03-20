/*lista enlazanadas
hacer una lista de canciones 
y una de reproduccion de spotify
*/
struct Node{
    int data;
    Node* next;
    Node (int val):data(val),next(nullptr){}
};
//crear la funcion que me va a permitir insertar 
void insertarInicio(Node* &head, int val){
    Node* newNode= newNode(val);
    newNode->next=head;
    head=newNode;
}
//funcion que muestra la lista 
void imprimirLista(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    Node* head=nullptr;
    insertarInicio(head,3)
    insertarInicio(head,4)
    cout<<"Lista yo "<<endl;
    imprimirLista(head);
}