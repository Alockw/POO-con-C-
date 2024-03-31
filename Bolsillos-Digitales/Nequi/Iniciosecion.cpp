#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definición de la clase Usuario
class Usuario
{
private:
    std::string nombre;
    long long int telefono;
    long long int contrasena;
    double saldo; // Variable para almacenar el saldo del usuario

public:
    Usuario(std::string nombre, long long int telefono, long long int contrasena, double saldo)
        : nombre(nombre), telefono(telefono), contrasena(contrasena), saldo(saldo) {}

    // Métodos para obtener información del usuario
    std::string getNombre() const { return nombre; }
    long long int getTelefono() const { return telefono; }
    long long int getContrasena() const { return contrasena; }
    double getSaldo() const { return saldo; }

    // Métodos para actualizar el saldo del usuario
    void agregarSaldo(double monto) { saldo += monto; }
    void restarSaldo(double monto) { saldo -= monto; }
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

    cout << "bienvenido a Nequi:\n"
         << endl;

    // Bucle para intentar iniciar sesión hasta 3 veces
    while (!sesionIniciada && intentos < 3)
    {
        cout << "Ingrese su numero de telefono: ";
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
            cout << "Numero de teléfono o contrasena incorrectos. Intente de nuevo." << endl;
            intentos++; // Incrementar el contador de intentos
        }
    }

    // Si se alcanza el límite de intentos, mostrar un mensaje
    if (intentos >= 3)
    {
        cout << "Ha alcanzado el limite de intentos. Por favor, intente mas tarde." << endl;
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
