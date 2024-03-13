#include<iostream>
#include<cmath>
using namespace std;
class Persona{
    private:
    string nombreUsuario;
    string apellidoUsiario;
    int edadUsuario;
    string tipoDocumento;
    string numeroDocumento;
    string sexoUsiario;
    int pesoUsiaro;
    float usiaroEstatura;
    public:
    // Getters
    string getNombreUsuario() const { return nombreUsuario; }
    string getApellidoUsuario() const { return apellidoUsiario; }
    int getEdadUsuario() const { return edadUsuario; }
    string getTipoDocumento() const { return tipoDocumento; }
    string getNumeroDocumento() const { return numeroDocumento; }
    string getSexoUsuario() const { return sexoUsiario; }
    int getPesoUsuario() const { return pesoUsiaro; }
    float getUsuarioEstatura() const { return usiaroEstatura; }

    // Setters
    void setNombreUsuario(string nombre) { nombreUsuario = nombre; }
    void setApellidoUsuario(string apellido) { apellidoUsiario = apellido; }
    void setEdadUsuario(int edad) { edadUsuario = edad; }
    void setTipoDocumento(string tipo) { tipoDocumento = tipo; }
    void setNumeroDocumento(string numero) { numeroDocumento = numero; }
    void setSexoUsuario(string sexo) { sexoUsiario = sexo; }
    void setPesoUsuario(int peso) { pesoUsiaro = peso; }
    void setUsuarioEstatura(float estatura) { usiaroEstatura= estatura;}
    void pedirDatos(){
        cout << "Por favor registre el nombre del usuario: " << endl;
        cin >> nombreUsuario;
        cout << "Por favor registre el apellido del usuario " << endl;
        cin >> apellidoUsiario;
        cout << "Que tipo de documento es CC o TI: " << endl;
        cin >> tipoDocumento;
        cout << "Por favor registre la edad del usuario: " << endl;
        cin >> edadUsuario;
        cout << "Por favor registre numero de documento del usario: " << endl;
        cin >> numeroDocumento;
        cout << "Por favor registre el sexo del usuario M(masculino)o F(femenino),x(otro): " << endl;
        cin >> sexoUsiario;
        cout << "Por favor registre el peso del usuario en kg: " << endl;
        cin >> pesoUsiaro;
        cout << "Por favor registre la altura del usuario en m(metros): " << endl;
        cin >> usiaroEstatura;
    }
    void mostrarPersona(){
        cout<<"Nombre: "<<nombreUsuario<<endl;
        cout<<"Apellido: "<<apellidoUsiario<<endl;
        cout<<"Documento: "<<tipoDocumento<<endl;
        cout<<"Numero Doc;"<<numeroDocumento<<endl;
        cout<<"Edad "<<edadUsuario<<endl;
        cout<<"Sexo: "<<sexoUsiario<<endl;
        cout<<"Peso "<<pesoUsiaro<<endl;
    }
    void calcularMc(){
        int pesoActual=(pesoUsiaro/pow(usiaroEstatura,2));
        if (pesoActual<20){
            cout<<"el peso esta debajo de lo ideal"<<pesoActual<<endl;
        }
        else if (pesoActual>=20 && pesoActual<=25)
        {
            cout<<"el peso es ideal"<<pesoActual<<endl;;
        }
        else {
            cout<<"el peso da indices de sobre peso"<<pesoActual <<endl;
        }
    }
    void mayorEdad(){
        if (edadUsuario<18){
            cout<<"el usuario es menor de edad"<<edadUsuario<<endl;
        }
        else{
            cout<<"el usuario es mayor de edad"<<edadUsuario<<endl;
        }
    }

};
int main(){
Persona persona1;
   persona1.pedirDatos();
   persona1.mostrarPersona();
   persona1.calcularMc();
   persona1.mayorEdad();
   return 0;
};