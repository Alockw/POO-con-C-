#include <iostream>
#include <list>
#include <string>

using namespace std;

// Estructura para representar una canción
struct Cancion
{
    string titulo;
    string genero;

    // Constructor para inicializar una canción con título y género
    Cancion(string titulo, string genero) : titulo(titulo), genero(genero) {}
};

// Funcion para mostrar la lista de canciones
void mostrarCanciones(const list<Cancion> &canciones)
{
    for (const auto &cancion : canciones)
    {
        cout << "Titulo: " << cancion.titulo << ", Genero: " << cancion.genero << endl;
    }
}

// Funcion para agregar una canción a la lista
void agregarCancion(list<Cancion> &canciones, string titulo, string genero)
{
    canciones.push_back(Cancion(titulo, genero));
}

// Funcion para eliminar una canción de la lista por título
void eliminarCancion(list<Cancion> &canciones, string titulo)
{
    canciones.remove_if([&titulo](const Cancion &cancion)
                        { return cancion.titulo == titulo; });
}

int main()
{
    list<Cancion> listaCancionesPredeterminada;

    // Agregar algunas canciones de ejemplo a la lista predeterminada
    agregarCancion(listaCancionesPredeterminada, "Frijolero", "Rock");
    agregarCancion(listaCancionesPredeterminada, "Baby_justi_bieber", "Pop");

    // Mostrar las canciones existentes en la lista predeterminada
    cout << "Lista de canciones predeterminada:" << endl;
    mostrarCanciones(listaCancionesPredeterminada);

    list<Cancion> listaCancionesUsuario;

    // Solicitar al usuario que agregue o elimine canciones de su lista personal
    int opcion;
    while (true)
    {
        cout << "¿Que desea hacer con su lista personal? (Agregar(1)/Eliminar(2)/Salir(3)): ";
        cin >> opcion;

        if (opcion == 1)
        {
            string titulo, genero;
            cout << "Ingrese el título de la cancion (si tiene espacion ponga_ en cada espacio): ";
            cin >> titulo;
            cout << "Ingrese el genero de la cancion: ";
            cin >> genero;
            agregarCancion(listaCancionesUsuario, titulo, genero);
        }
        else if (opcion == 2)
        {
            string titulo;
            cout << "Ingrese el título de la cancion a eliminar: ";
            cin >> titulo;
            eliminarCancion(listaCancionesUsuario, titulo);
        }
        else if (opcion == 3)
        {
            break;
        }
        else
        {
            cout << "Opción no valida. Intente de nuevo." << endl;
        }

        // Mostrar las canciones actualizadas en la lista del usuario
        cout << "Lista personal actualizada:" << endl;
        mostrarCanciones(listaCancionesUsuario);
    }

    return 0;
}