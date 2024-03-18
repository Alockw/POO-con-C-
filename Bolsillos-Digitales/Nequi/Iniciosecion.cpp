#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Usuario
{
private:
    string nombre;
    long long int telefono;   // Cambiado a long long int para un tamaño mayor de numero que se pueda almacenar en la bariable
    long long int contrasena; // Cambiado a long long int

public:
    // Constructor
    Usuario(string nombre, long long int telefono, long long int contrasena)
        : nombre(nombre), telefono(telefono), contrasena(contrasena) {}

    // Getters
    string getNombre() const { return nombre; }
    long long int getTelefono() const { return telefono; }
    long long int getContrasena() const { return contrasena; }

    // Setters
    void setNombre(const string &nombre) { this->nombre = nombre; }
    void setTelefono(long long int telefono) { this->telefono = telefono; }
    void setContrasena(long long int contrasena) { this->contrasena = contrasena; }
};

vector<Usuario> usuarios = {
    Usuario("Joseph", 3124208931, 123456789),
    Usuario("Ana", 987654321, 12342),
    Usuario("Carlos", 112233445, 12343)};

bool iniciarSesion()
{
    long long int telefono;
    long long int contrasena;
    bool sesionIniciada = false;
    cout << "bienvenido a Nequi:\n"
         << endl;

    while (!sesionIniciada)
    {
        cout << "Ingrese su numero de telefono: ";
        cin >> telefono;
        cout << "Ingrese su contrasena: ";
        cin >> contrasena;

        for (const auto &usuario : usuarios)
        {
            if (usuario.getTelefono() == telefono && usuario.getContrasena() == contrasena)
            {
                cout << "Bienvenido, " << usuario.getNombre() << "!" << endl;
                sesionIniciada = true;
                break;
            }
        }
        if (!sesionIniciada)
        {
            cout << "Número de teléfono o contraseña incorrectos. Intente de nuevo." << endl;
        }
    }
    return sesionIniciada;
}

int main()
{
    if (iniciarSesion())
    {
    }
    return 0;
}
