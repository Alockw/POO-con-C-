#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    long long int telefono; // Cambiado a long long int
    long long int contrasena; // Cambiado a long long int

public:
    // Constructor
    Usuario(string nombre, long long int telefono, long long int contrasena)
        : nombre(nombre), telefono(telefono), contrasena(contrasena) {}

    // Getters
    string getNombre() const { return nombre; }
    long long int getTelefono() const { return telefono; } // Devuelve long long int
    long long int getContrasena() const { return contrasena; } // Devuelve long long int

    // Setters
    void setNombre(const string& nombre) { this->nombre = nombre; }
    void setTelefono(long long int telefono) { this->telefono = telefono; } // Acepta long long int
    void setContrasena(long long int contrasena) { this->contrasena = contrasena; } // Acepta long long int
};

vector<Usuario> usuarios = {
    Usuario("Joseph", 3124208931, 123456789),
    Usuario("Ana", 987654321, 12342),
    Usuario("Carlos", 112233445, 12343)
};

bool iniciarSesion() {
    long long int telefono; // Cambiado a long long int
    long long int contrasena; // Cambiado a long long int
    bool sesionIniciada = false;

    while (!sesionIniciada) {
        cout << "Ingrese su número de teléfono: ";
        cin >> telefono;
        cout << "Ingrese su contraseña: ";
        cin >> contrasena;

        for (const auto& usuario : usuarios) {
            if (usuario.getTelefono() == telefono && usuario.getContrasena() == contrasena) {
                cout << "Bienvenido, " << usuario.getNombre() << "!" << endl;
                sesionIniciada = true;
                break;
            }
        }
        if (!sesionIniciada) {
            cout << "Número de teléfono o contraseña incorrectos. Intente de nuevo." << endl;
        }
    }
    return sesionIniciada;
}

int main() {
    if (iniciarSesion()) {
        // Aquí puedes agregar el código que se ejecutará después de un inicio de sesión exitoso
    }
    return 0;
}
