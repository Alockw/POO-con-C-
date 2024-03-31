#include <iostream>
#include "usuario.h"
using namespace std;
class Recargar : public Usuario {
private:
    double monto;

public:
    Recargar(string nombre, long long int telefono, long long int contrasena, double monto)
        : Usuario(nombre, telefono, contrasena, 0.0), monto(monto) {}

    void realizarTransaccion() {
        cout << "Realizando recarga de " << monto << " a " << getNombre() << endl;
        agregarSaldo(monto); // Actualiza el saldo del usuario
        cout << "Nuevo saldo: " << getSaldo() << endl;
    }
};
int main() {
    return 0;
}