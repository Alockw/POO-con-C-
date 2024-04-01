#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Clase Movimiento que representa una transacción realizada por el usuario
class Movimiento {
private:
    double monto;
    int dia;
    int mes;

public:
    Movimiento(double monto, int dia, int mes) : monto(monto), dia(dia), mes(mes) {}

    // Getter para el monto del movimiento
    double getMonto() const { return monto; }

    // Getter para el día del movimiento
    int getDia() const { return dia; }

    // Getter para el mes del movimiento
    int getMes() const { return mes; }

    // Método para obtener una representación en string del movimiento
    string toString() const {
        return "Monto: " + to_string(monto) + ", Fecha: " + to_string(dia) + "/" + to_string(mes);
    }

    // Sobrecarga del operador < para comparar movimientos por fecha
    bool operator<(const Movimiento& otro) const {
        if (mes != otro.mes) {
            return mes > otro.mes; // Ordena por mes de mayor a menor
        }
        return dia > otro.dia; // Ordena por día de mayor a menor dentro del mismo mes
    }
};

// Clase RegistroMovimientos que administra los movimientos de recarga y pago del usuario
class RegistroMovimientos {
private:
    vector<Movimiento> movimientos;

public:
    // Método para agregar un movimiento
    void agregarMovimiento(double monto, int dia, int mes) {
        movimientos.emplace_back(monto, dia, mes);
    }

    // Método para mostrar los movimientos ordenados por día de mayor a menor y luego por mes
    void mostrarMovimientosPorDiaYMes() {
        // Ordena los movimientos usando el operador < sobrecargado en la clase Movimiento
        sort(movimientos.begin(), movimientos.end());
        cout << "Movimientos del usuario organizados por día de mayor a menor y luego por mes:" << endl;
        for (const auto& movimiento : movimientos) {
            cout << movimiento.toString() << endl;
        }
    }

    // Método para mostrar los movimientos ordenados por mes de mayor a menor y luego por día
    void mostrarMovimientosPorMesYDia() {
        // Ordena los movimientos utilizando una función lambda que compara por mes y luego por día
        sort(movimientos.begin(), movimientos.end(), [](const Movimiento& a, const Movimiento& b) {
            if (a.getMes() != b.getMes()) {
                return a.getMes() > b.getMes();
            }
            return a.getDia() > b.getDia();
        });
        cout << "Movimientos del usuario organizados por mes de mayor a menor y luego por día:" << endl;
        for (const auto& movimiento : movimientos) {
            cout << movimiento.toString() << endl;
        }
    }
};
// Definición de la clase Usuario
class Usuario {
private:
    string nombre;
    long long int telefono;
    long long int contrasena;
    double saldo; // Variable para almacenar el saldo del usuario

public:
    Usuario(string nombre, long long int telefono, long long int contrasena, double saldo)
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
class Pagos {
private:
    double monto;
    string numeroDestinatario;
    int dia;          // Variable para almacenar el día de la transacción
    int mes;          // Variable para almacenar el mes de la transacción
    Usuario *usuario; // Cambiado a puntero

public:
    Pagos(Usuario *usuario, double monto, string numeroDestinatario, int dia, int mes)
        : usuario(usuario), monto(monto), numeroDestinatario(numeroDestinatario), dia(dia), mes(mes) {}

    void realizarTransaccion() {
        cout << "Realizando pago de " << monto << " a " << numeroDestinatario << " el día " << dia << " del mes " << mes << endl;
        usuario->restarSaldo(monto); // Actualiza el saldo del usuario
        cout << "Nuevo saldo: " << usuario->getSaldo() << endl;
    }
};

// Definición de la clase Recargar
class Recargar {
private:
    double monto;
    int dia;          // Variable para almacenar el día de la transacción
    int mes;          // Variable para almacenar el mes de la transacción
    Usuario *usuario; // Cambiado a puntero

public:
    Recargar(Usuario *usuario, double monto, int dia, int mes)
        : usuario(usuario), monto(monto), dia(dia), mes(mes) {}

    void realizarTransaccion() {
        cout << "Realizando recarga de " << monto << " a " << usuario->getNombre() << " el día " << dia << " del mes " << mes << endl;
        usuario->agregarSaldo(monto); // Actualiza el saldo del usuario
        cout << "Nuevo saldo: " << usuario->getSaldo() << endl;
    }
};

// Vector de usuarios predefinidos
vector<Usuario *> usuarios = {
    new Usuario("Joseph", 3124208931, 1254, 0.0),
    new Usuario("Ana", 987654321, 1234, 0.0),
    new Usuario("Carlos", 112233445, 1224, 0.0)};

// Estructura para el resultado del inicio de sesión
struct ResultadoInicioSesion {
    bool exito;
    Usuario *usuario; // Cambiado a puntero
    ResultadoInicioSesion() : exito(false), usuario(nullptr) {}
};

// Función para iniciar sesión
ResultadoInicioSesion iniciarSesion() {
    long long int telefono;
    long long int contrasena;
    ResultadoInicioSesion resultado;
    resultado.exito = false;

    cout << "Bienvenido a Daviplata:\n"
         << endl;

    for (int intentos = 0; intentos < 3; ++intentos) {
        cout << "Ingrese su numero de telefono: ";
        cin >> telefono;
        cout << "Ingrese su contrasena: ";
        cin >> contrasena;

        for (auto &usuario : usuarios) {
            if (usuario->getTelefono() == telefono && usuario->getContrasena() == contrasena) {
                cout << "Bienvenido, " << usuario->getNombre() << "!" << endl;
                resultado.usuario = usuario;
                resultado.exito = true;
                return resultado;
            }
        }
        cout << "Numero de teléfono o contrasena incorrectos. Intente de nuevo." << endl;
    }

    cout << "Ha alcanzado el limite de intentos. Por favor, intente mas tarde." << endl;
    return resultado;
}

int main() {
    ResultadoInicioSesion resultado = iniciarSesion();

    if (resultado.exito) // Verifica si el inicio de sesión fue exitoso
    {
        RegistroMovimientos registro;

        int opcion;
        double monto;
        int dia, mes;
        string numeroDestinatario;
        do {
            cout << "Ingrese el dia: ";
            cin >> dia;
            cout << "Ingrese el mes: ";
            cin >> mes;

            cout << "[1] Verificar saldo\n"
                 << "[2] Realizar recarga\n"
                 << "[3] Realizar pago\n"
                 << "[4] Mostrar movimientos ordenados por día de mayor a menor y luego por mes\n"
                 << "[5] Mostrar movimientos ordenados por mes de mayor a menor y luego por día\n"
                 << "[6] Salir\n"
                 << "Ingrese su opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Su saldo actual es: " << resultado.usuario->getSaldo() << endl;
                    break;
                case 2:
                    cout << "Ingrese el monto a recargar: ";
                    cin >> monto;
                    {
                        Recargar recarga(resultado.usuario, monto, dia, mes);
                        recarga.realizarTransaccion();
                        registro.agregarMovimiento(monto, dia, mes);
                    }
                    break;
                case 3:
                    cout << "Ingrese el monto a pagar: ";
                    cin >> monto;
                    cout << "Ingrese el numero de telefono del destinatario: ";
                    cin >> numeroDestinatario;
                    {
                        Pagos pago(resultado.usuario, monto, numeroDestinatario, dia, mes);
                        pago.realizarTransaccion();
                        registro.agregarMovimiento(-monto, dia, mes);
                    }
                    break;
                case 4:
                    registro.mostrarMovimientosPorDiaYMes();
                    break;
                case 5:
                    registro.mostrarMovimientosPorMesYDia();
                    break;
                case 6:
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    cout << "Por favor, ingrese un numero valido." << endl;
            }
        } while (opcion != 6);
    }
    // Liberar memoria asignada a los usuarios
    for (auto &usuario : usuarios) {
        delete usuario;
    }

    return 0;
}