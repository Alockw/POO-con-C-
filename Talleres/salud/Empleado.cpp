#include "Persona.h"
class Empleado : public Persona
{
private:
    string cargo;
    int valorHora;
    int horasTrabajadas;
    string departamento;
    int fecha;

public:
    // getters
    int getFecha() const { return fecha; }
    string getCargo() const { return cargo; }
    int getValorHora() const { return valorHora; }
    int getHorasTrabajadas() const { return horasTrabajadas; }
    string getDepartamento() const { return departamento; }
    //setters
    void setFecha(int año) { fecha = año; }
    void setCargo(string puesto) { cargo = puesto; }
    void setValorHora(int vhora) { valorHora = vhora; }
    void setHorasTrabajadas(int hTrabajadas) { horasTrabajadas = hTrabajadas; }
    void setDepartamento(string dep) { departamento = dep; }
    void pedirDatos()
    {
        cout << "Por favor registre el cargo del empleado: " << endl;
        cin >> cargo;
        cout << "Por favor registre el valor de su hora " << endl;
        cin >> valorHora;
        cout << "En que departamento esta ?: " << endl;
        cin >> departamento;
        cout << "Cuantas horas a trabajado ?: " << endl;
        cin >> horasTrabajadas;
        cout << "En que año nacio ?: " << endl;
        cin >> fecha;
    }
    int mayoriaEdad(int fecha)
    {
        int edad = fecha - 2024;
        if (edad < 18)
        {
            cout << "el usuario es menor de edad " << edad << endl;
        }
        else
        {
            cout << "el usuario es mayor de edad " << edad << endl;
        }
        return edad;
    }
    void calcularHonorarios()
    {
        int totalHoras = valorHora * horasTrabajadas;
        double honorarios = totalHoras - (totalHoras * 0.966 / 100);
        cout << "El total de sus honorarios es de :" << honorarios << endl;
    }
};
int main()
{
    Empleado empleado1;
    Persona empleado2;
    empleado2.pedirDatos();
    empleado1.pedirDatos();
    empleado1.calcularMc();
    empleado1.mayorEdad();
    empleado1.calcularHonorarios();
    empleado1.mayorEdad();
    empleado1.mostrarPersona();
};