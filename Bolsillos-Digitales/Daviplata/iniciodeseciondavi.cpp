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

// Definición de la clase Pagos
class Pagos : public Usuario
{
private:
    double monto;
    string numeroDestinatario;

public:
    Pagos(string nombre, long long int telefono, long long int contrasena, double monto, string numeroDestinatario)
        : Usuario(nombre, telefono, contrasena, 0.0), monto(monto), numeroDestinatario(numeroDestinatario) {}

    void realizarTransaccion()
    {
        cout << "Realizando pago de " << monto << " a " << numeroDestinatario << endl;
        restarSaldo(monto); // Actualiza el saldo del usuario
        cout << "Nuevo saldo: " << getSaldo() << endl;
    }
};

// Definición de la clase Recargar
class Recargar : public Usuario
{
private:
    double monto;

public:
    Recargar(string nombre, long long int telefono, long long int contrasena, double monto)
        : Usuario(nombre, telefono, contrasena, 0.0), monto(monto) {}

    void realizarTransaccion()
    {
        cout << "Realizando recarga de " << monto << " a " << getNombre() << endl;
        agregarSaldo(monto); // Actualiza el saldo del usuario
        cout << "Nuevo saldo: " << getSaldo() << endl;
    }
};

// Vector de usuarios predefinidos
vector<Usuario> usuarios = {
    Usuario("Joseph", 3124208931, 1254, 0.0),
    Usuario("Ana", 987654321, 1234, 0.0),
    Usuario("Carlos", 112233445, 1224, 0.0)};

// Función para iniciar sesión
bool iniciarSesion()
{
    long long int telefono;           // Variable para almacenar el número de teléfono ingresado
    long long int contrasena;         // Variable para almacenar la contraseña ingresada
    bool sesionIniciada = false;      // Bandera para indicar si la sesión ha sido iniciada
    int intentos = 0;                 // Contador de intentos de inicio de sesión
    Usuario *usuarioActual = nullptr; // Puntero para almacenar el usuario actual

    cout << "bienvenido a Daviplata:\n"
         << endl;

    // Bucle para intentar iniciar sesión hasta 3 veces
    while (!sesionIniciada && intentos < 3)
    {
        cout << "Ingrese su numero de telefono: ";
        cin >> telefono;
        cout << "Ingrese su contrasena: ";
        cin >> contrasena;

        // Verificar si el número de teléfono y la contraseña coinciden con algún usuario
        for (auto &usuario : usuarios)
        {
            if (usuario.getTelefono() == telefono && usuario.getContrasena() == contrasena)
            {
                cout << "Bienvenido, " << usuario.getNombre() << "!" << endl;
                sesionIniciada = true;
                usuarioActual = &usuario; // Guardar el puntero al usuario actual
                break;
            }
        }
        if (!sesionIniciada)
        {
            cout << "Numero de telefono o contrasena incorrectos. Intente de nuevo." << endl;
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
        int opcion;
        double monto;
        string numeroDestinatario;
        do
        {
            cout << "[1] Verificar saldo\n"
                 << "[2] Realizar recarga\n"
                 << "[3] Realizar pago\n"
                 << "[4] Salir\n"
                 << "Ingrese su opción: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                cout << "Su saldo actual es: " << usuarioActual->getSaldo() << endl;
                break;
            case 2:
                cout << "Ingrese el monto a recargar: ";
                cin >> monto;
                Recargar recargar(usuarioActual->getNombre(), usuarioActual->getTelefono(), usuarioActual->getContrasena(), monto);
                recargar.realizarTransaccion();
                break;
            case 3:
                cout << "Ingrese el monto a pagar y el número de teléfono del destinatario: ";
                cin >> monto;
                cin >> numeroDestinatario;
                Pagos pagos(usuarioActual->getNombre(), usuarioActual->getTelefono(), usuarioActual->getContrasena(), monto, numeroDestinatario);
                pagos.realizarTransaccion();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Por favor, ingrese un número válido." << endl;
            }
        } while (opcion != 4);
    }
    return 0;
}
