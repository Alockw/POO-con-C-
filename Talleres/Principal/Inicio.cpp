#include <iostream>
#include "../salud/Persona.h"

using namespace std;

class Inicio {
public:
    void validacionImc(Persona &user) {
        float resultado = user.calcularMc();
        if (resultado < 20) {
            cout << "PESOBAJO" << endl;
        } else if (resultado >= 20 && resultado <= 25) {
            cout << "PESOIDEAL" << endl;
        } else {
            cout << "SOBREPESO" << endl;
        }
    }
};

int main() {
    Persona user;
    Inicio inicio;
    user.pedirDatos();
    inicio.validacionImc(user);
    return 0;
}
