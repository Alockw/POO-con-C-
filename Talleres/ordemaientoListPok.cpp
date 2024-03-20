#include <iostream>
using namespace std;

// Definición de la estructura Node
struct Node
{
    string valor;
    string pinta;
    Node *next;
    Node(string valor, string pinta) : valor(valor), pinta(pinta), next(nullptr) {}
};

// Función para insertar un nodo al principio de la lista
void insertarInicioList(Node *&head, string valor, string pinta)
{
    Node *nuevoNodo = new Node(valor, pinta);
    nuevoNodo->next = head;
    head = nuevoNodo;
}

// Función para imprimir la lista
void imprimirLista(Node *head)
{
    while (head != nullptr)
    {
        cout << "Valor: " << head->valor << ", Pinta: " << head->pinta << endl;
        head = head->next;
    }
}

// Función para ordenar la lista por orden alfabético de la pinta y por valor de menor a mayor
void ordeLista(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    Node *sorted = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        Node *prev = nullptr;
        Node *currSorted = sorted;

        while (currSorted != nullptr && (currSorted->pinta < current->pinta || (currSorted->pinta == current->pinta && currSorted->valor > current->valor)))
        {
            prev = currSorted;
            currSorted = currSorted->next;
        }

        if (prev == nullptr)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            prev->next = current;
            current->next = currSorted;
        }

        current = nextNode;
    }

    head = sorted;
}

int main()
{
    Node *head = nullptr;
    insertarInicioList(head, "5", "diamante");
    insertarInicioList(head, "1", "corazon");
    insertarInicioList(head, "9", "picas");
    insertarInicioList(head, "3", "treboles");
    insertarInicioList(head, "6", "diamante");
    insertarInicioList(head, "8", "diamante");
    insertarInicioList(head, "6", "corazon");
    insertarInicioList(head, "j", "corazon");
    insertarInicioList(head, "q", "corazon");
    insertarInicioList(head, "k", "corazon");
    cout << "Lista original es: " << endl;
    imprimirLista(head);
    ordeLista(head);
    cout << "Lista Ordenada es: " << endl;
    imprimirLista(head);
    return 0;
}