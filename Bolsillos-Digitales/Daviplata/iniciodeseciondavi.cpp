#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definición de la clase Usuario
class Usuario
{
private:
    string nombre;            // Nombre del usuario
    long long int telefono;   // Número de teléfono del usuario
    long long int contrasena; // Contraseña del usuario

public:
    // Constructor de la clase Usuario
    Usuario(string nombre, long long int telefono, long long int contrasena)
        : nombre(nombre), telefono(telefono), contrasena(contrasena) {}

    // Métodos getter para obtener los datos del usuario
    string getNombre() const { return nombre; }
    long long int getTelefono() const { return telefono; }
    long long int getContrasena() const { return contrasena; }

    // Métodos setter para modificar los datos del usuario
    void setNombre(const string &nombre) { this->nombre = nombre; }
    void setTelefono(long long int telefono) { this->telefono = telefono; }
    void setContrasena(long long int contrasena) { this->contrasena = contrasena; }
};

// Vector de usuarios predefinidos
vector<Usuario> usuarios = {
    Usuario("Joseph", 3124208931, 1254),
    Usuario("Ana", 987654321, 1234),
    Usuario("Carlos", 112233445, 1224)};

// Función para iniciar sesión
bool iniciarSesion()
{
    long long int telefono;      // Variable para almacenar el número de teléfono ingresado
    long long int contrasena;    // Variable para almacenar la contraseña ingresada
    bool sesionIniciada = false; // Bandera para indicar si la sesión ha sido iniciada
    int intentos = 0;            // Contador de intentos de inicio de sesión

    cout << "bienvenido a Daviplata:\n"
         << endl;

    // Bucle para intentar iniciar sesión hasta 3 veces
    while (!sesionIniciada && intentos < 3)
    {
        cout << "Ingrese su numero de teléfono: ";
        cin >> telefono;
        cout << "Ingrese su contrasena: ";
        cin >> contrasena;

        // Verificar si el número de teléfono y la contraseña coinciden con algún usuario
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
            intentos++; // Incrementar el contador de intentos
        }
    }

    // Si se alcanza el límite de intentos, mostrar un mensaje
    if (intentos >= 3)
    {
        cout << "Ha alcanzado el límite de intentos. Por favor, intente más tarde." << endl;
    }

    return sesionIniciada;
}

int main()
{
    // Intentar iniciar sesión
    if (iniciarSesion())
    {
        // Aquí puedes agregar el código que se ejecutará después de un inicio de sesión exitoso
    }
    return 0;
}