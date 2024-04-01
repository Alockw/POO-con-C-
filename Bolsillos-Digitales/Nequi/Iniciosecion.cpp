#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base Usuario
class Usuario {
protected:
    string nombre;
    long long int telefono;
    long long int contrasena;
    double saldo;

public:
    Usuario(string nombre, long long int telefono, long long int contrasena, double saldo)
        : nombre(nombre), telefono(telefono), contrasena(contrasena), saldo(saldo) {}

    string getNombre() const { return nombre; }
    long long int getTelefono() const { return telefono; }
    long long int getContrasena() const { return contrasena; }
    double getSaldo() const { return saldo; }

    bool verificarContrasena(long long int contrasena) const {
        return this->contrasena == contrasena;
    }

    void agregarSaldo(double monto) { saldo += monto; }
    bool restarSaldo(double monto) {
        if (saldo >= monto) {
            saldo -= monto;
            return true;
        }
        return false;
    }
};

// Clase hija Recarga
class Recarga : public Usuario {
private:
    string metodo;
    string banco;
    string codigo;

public:
    Recarga(string nombre, long long int telefono, long long int contrasena, double saldo, string metodo, string banco, string codigo)
        : Usuario(nombre, telefono, contrasena, saldo), metodo(metodo), banco(banco), codigo(codigo) {}

    void realizarRecarga(double monto) {
        if (metodo == "Efectivo" || metodo == "PSE") {
            agregarSaldo(monto);
            cout << "Recarga realizada con éxito." << endl;
        } else {
            cout << "Método de recarga no válido." << endl;
        }
    }
};

// Clase hija Colchon
class Colchon : public Usuario {
public:
    Colchon(string nombre, long long int telefono, long long int contrasena, double saldo)
        : Usuario(nombre, telefono, contrasena, saldo) {}

    void transferirACuenta(double monto, Usuario& cuentaDestino) {
        if (restarSaldo(monto)) {
            cuentaDestino.agregarSaldo(monto);
            cout << "Transferencia realizada con éxito." << endl;
        } else {
            cout << "Saldo insuficiente para realizar la transferencia." << endl;
        }
    }
};

// Clase hija Bolsillos
class Bolsillos : public Usuario {
private:
    vector<double> fondosEnBolsillos;

public:
    Bolsillos(string nombre, long long int telefono, long long int contrasena, double saldo)
        : Usuario(nombre, telefono, contrasena, saldo) {}

    void agregarFondos(double monto) {
        fondosEnBolsillos.push_back(monto);
        restarSaldo(monto);
        cout << "Fondos agregados a Bolsillos." << endl;
    }

    double verTotalBolsillos() const {
        double total = 0;
        for (double fondo : fondosEnBolsillos) {
            total += fondo;
        }
        return total;
    }
};

// Clase hija Meta
class Meta : public Usuario {
private:
    double objetivo;

public:
    Meta(string nombre, long long int telefono, long long int contrasena, double saldo, double objetivo)
        : Usuario(nombre, telefono, contrasena, saldo), objetivo(objetivo) {}

    void establecerObjetivo(double monto) {
        objetivo = monto;
        cout << "Objetivo de ahorro establecido en $" << objetivo << "." << endl;
    }

    double verProgreso() const {
        return saldo / objetivo * 100.0;
    }
};

// Clase hija SacarPlata
class SacarPlata : public Usuario {
public:
    SacarPlata(string nombre, long long int telefono, long long int contrasena, double saldo)
        : Usuario(nombre, telefono, contrasena, saldo) {}

    bool retirarDinero(double monto) {
        if (restarSaldo(monto)) {
            cout << "Retiro exitoso. Ha retirado $" << monto << " de su cuenta." << endl;
            return true;
        } else {
            cout << "Fondos insuficientes. No se puede completar el retiro." << endl;
            return false;
        }
    }
};

int main() {
    // Usuarios almacenados en una estructura de datos (vector)
    vector<Usuario> usuarios = {
        Usuario("Joseph", 3124208931, 1254, 1000.0),
        Usuario("Ana", 987654321, 1234, 1500.0),
        Usuario("Carlos", 112233445, 1224, 2000.0)
    };

    long long int telefono;
    long long int contrasena;

    cout << "Acceso a la aplicación Nequi" << endl;

    // Pedir número de teléfono y contraseña
    cout << "Ingrese su número de teléfono: ";
    cin >> telefono;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    bool sesionIniciada = false;
    Usuario usuarioActual("", 0, 0, 0.0);

    // Verificar si el número de teléfono y la contraseña coinciden con algún usuario registrado
    for (const auto& usuario : usuarios) {
        if (usuario.getTelefono() == telefono && usuario.verificarContrasena(contrasena)) {
            sesionIniciada = true;
            usuarioActual = usuario;
            break;
        }
    }

    if (sesionIniciada) {
        // Mostrar saldo después de iniciar sesión
        cout << "Bienvenido, " << usuarioActual.getNombre() << "!" << endl;
        cout << "Su saldo actual es: $" << usuarioActual.getSaldo() << endl;

        // Mostrar menú
        int opcion;
        do {
            cout << "\nMenú de opciones:" << endl;
            cout << "1. Recargar saldo" << endl;
            cout << "2. Ver saldo" << endl;
            cout << "3. Transferir a colchón" << endl;
            cout << "4. Ver total en bolsillos" << endl;
            cout << "5. Establecer meta de ahorro" << endl;
            cout << "6. Sacar dinero" << endl;
            cout << "7. Salir" << endl;
            cout << "Seleccione una opción: ";
            cin >> opcion;

            switch (opcion) {
                case 1: {
                    double monto;
                    cout << "Ingrese el monto a recargar: ";
                    cin >> monto;
                    Recarga recarga(usuarioActual.getNombre(), usuarioActual.getTelefono(), usuarioActual.getContrasena(), usuarioActual.getSaldo(), "Efectivo", "", "");
                    recarga.realizarRecarga(monto);
                    break;
                }
                case 2:
                    cout << "Su saldo actual es: $" << usuarioActual.getSaldo() << endl;
                    break;
                case 3: {
                    double monto;
                    cout << "Ingrese el monto a transferir al colchón: ";
                    cin >> monto;
                    Colchon colchon(usuarioActual.getNombre(), usuarioActual.getTelefono(), usuarioActual.getContrasena(), usuarioActual.getSaldo());
                    colchon.transferirACuenta(monto, usuarioActual);
                    break;
                }
                case 4: {
                    Bolsillos bolsillos(usuarioActual.getNombre(), usuarioActual.getTelefono(), usuarioActual.getContrasena(), usuarioActual.getSaldo());
                    cout << "El total en bolsillos es: $" << bolsillos.verTotalBolsillos() << endl;
                    break;
                }
                case 5: {
                    double objetivo;
                    cout << "Ingrese el objetivo de ahorro: ";
                    cin >> objetivo;
                    Meta meta(usuarioActual.getNombre(), usuarioActual.getTelefono(), usuarioActual.getContrasena(), usuarioActual.getSaldo(), objetivo);
                    meta.establecerObjetivo(objetivo);
                    break;
                }
                case 6: {
                    double monto;
                    cout << "Ingrese el monto a retirar: ";
                    cin >> monto;
                    SacarPlata sacarPlata(usuarioActual.getNombre(), usuarioActual.getTelefono(), usuarioActual.getContrasena(), usuarioActual.getSaldo());
                    sacarPlata.retirarDinero(monto);
                    break;
                }
                case 7:
                    cout << "Saliendo del programa..." << endl;
                    break;
                default:
                    cout << "Opción no válida. Inténtelo de nuevo." << endl;
            }
        } while (opcion != 7);
    } else {
        cout << "Número de teléfono o contraseña incorrectos. No se pudo iniciar sesión." << endl;
    }

    return 0;
}