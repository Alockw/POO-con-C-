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