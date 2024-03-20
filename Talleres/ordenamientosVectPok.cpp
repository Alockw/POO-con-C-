#include <iostream>
#include <vector>
using namespace std;
struct Poker
{
    string nombre;
    string figura;
    int valor;
    Poker(string nombre, string figura, int valor) : nombre(nombre), figura(figura), valor(valor) {}
};
void ordBur(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}
void vectOrd(int arr[], int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}
void pedirCartas(vector<Poker> &poker, string nombre, string figura, int valor)
{
    poker.push_back(Poker(nombre, figura, valor));
}
int main()
{
    vector<Poker> pokeVector;
    int numTarjetas;
    cout << "¿Cuantas tarjetas de Poker deseas agregar? ";
    cin >> numTarjetas;
    for (int i = 0; i < numTarjetas; i++)
    {
        string nombre, figura;
        int valor;
        cout << "Introduce el nombre de la tarjeta: ";
        cin >> nombre;
        cout << "Introduce la figura de la tarjeta: ";
        cin >> figura;
        cout << "Introduce el valor de la tarjeta: ";
        cin >> valor;
        pedirCartas(pokeVector, nombre, figura, valor);
    }
    for (const auto &tarjeta : pokeVector)
    {
        cout << "Nombre: " << tarjeta.nombre << ", Figura: " << tarjeta.figura << ", Valor: " << tarjeta.valor << endl;
    }}