#include <iostream>
#include "usuario.h" 
using namespace std;
class Pagos : public Usuario {
private:
    double monto;
    string numeroDestinatario;

public:
    Pagos(string nombre, long long int telefono, long long int contrasena, double monto, string numeroDestinatario)
        : Usuario(nombre, telefono, contrasena, 0.0), monto(monto), numeroDestinatario(numeroDestinatario) {}

    void realizarTransaccion() {
        cout << "Realizando pago de " << monto << " a " << numeroDestinatario << endl;
        restarSaldo(monto); // Actualiza el saldo del usuario
        cout << "Nuevo saldo: " << getSaldo() << endl;
    }
};
int main() {
    return 0;
}