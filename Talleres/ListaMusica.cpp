#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
struct Cancion
{
    string titulo; // Atributo para el título de la canción
    string genero; // Atributo para el género de la canción

    // Constructor para inicializar una canción con título y género
    Cancion(string titulo, string genero) : titulo(titulo), genero(genero) {}
};

// Estructura para representar un nodo en una lista enlazada
struct Node
{
    Cancion data;                                   // Datos del nodo, que es una canción
    Node *next;                                     // Puntero al siguiente nodo
    Node(Cancion val) : data(val), next(nullptr) {} // Constructor que acepta un objeto Cancion
};

// Función para insertar un nuevo nodo al inicio de la lista enlazada
void insertarInicio(Node *&head, Cancion val)
{
    Node *newNode = new Node(val); // Crea un nuevo nodo con los datos proporcionados
    newNode->next = head;          // El nuevo nodo apunta al nodo actualmente en la cabeza de la lista
    head = newNode;                // Actualiza la cabeza de la lista al nuevo nodo
}

// Función para imprimir la lista enlazada
void imprimirLista(Node *head)
{
    while (head != nullptr) // Mientras no se llegue al final de la lista
    {
        cout << "Titulo: " << head->data.titulo << ", Genero: " << head->data.genero << endl; // Imprime los datos del nodo actual
        head = head->next;                                                                    // Avanza al siguiente nodo
    }
}

// Función para mostrar la lista de canciones
void mostrarCanciones(const list<Cancion> &canciones)
{
    for (const auto &cancion : canciones) // Para cada canción en la lista
    {
        cout << "Titulo: " << cancion.titulo << ", Genero: " << cancion.genero << endl; // Imprime los datos de la canción
    }
}

// Función para agregar una canción a la lista
void agregarCancion(list<Cancion> &canciones, string titulo, string genero)
{
    canciones.push_back(Cancion(titulo, genero)); // Agrega una nueva canción al final de la lista
}

// Función para eliminar una canción de la lista por título
void eliminarCancion(list<Cancion> &canciones, string titulo)
{
    canciones.remove_if([&titulo](const Cancion &cancion) // Elimina todas las canciones que coincidan con el título proporcionado
                        { return cancion.titulo == titulo; });
    // Asegúrate de llamar a erase después de remove_if para eliminar los elementos
    canciones.erase(std::remove_if(canciones.begin(), canciones.end(), [&titulo](const Cancion &cancion)
                                   { return cancion.titulo == titulo; }),
                    canciones.end());
}

// Función para buscar una canción por título en la lista
bool buscarCancionPorTitulo(const list<Cancion> &canciones, const string &tituloBuscado)
{
    auto it = find_if(canciones.begin(), canciones.end(), [&tituloBuscado](const Cancion &cancion)
                      { return cancion.titulo == tituloBuscado; }); // Busca la canción por título

    return it != canciones.end(); // Devuelve verdadero si la canción se encuentra en la lista
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
    list<Cancion> listaCancionesAmigo;
    // Solicitar al usuario que agregue o elimine canciones de su lista personal
    int opcion;

    while (true)
    {
        cout << "que lista de reproduccion quieres escoger (1)propia o (2)amigo " << endl;
        cin >> opcion; // Corregido: se cambió la coma por un punto y coma
        if (opcion == 1)
        {
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

                    // Verificar si la canción ya existe en la lista predeterminada
                    if (buscarCancionPorTitulo(listaCancionesPredeterminada, titulo))
                    {
                        cout << "La canción '" << titulo << "' ya existe en la lista predeterminada." << endl;
                        agregarCancion(listaCancionesUsuario, titulo, genero);
                        cout << "Cancion agregada a la lista personal." << endl;
                    }
                    else
                    {
                        agregarCancion(listaCancionesPredeterminada, titulo, genero);
                        cout << "Cancion agregada a la lista predeterminada." << endl;
                    }
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
                    cout << "esta saliendo de su playlist " << endl;
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
        }
        else if (opcion == 2)
        {
            while (true)
            {
                cout << "¿Que desea hacer con la lista de su amigo? (Agregar(1)/Eliminar(2)/Salir(3)): ";
                cin >> opcion;

                if (opcion == 1)
                {
                    string titulo, genero;
                    cout << "Ingrese el título de la cancion (si tiene espacion ponga_ en cada espacio): ";
                    cin >> titulo;
                    cout << "Ingrese el genero de la cancion: ";
                    cin >> genero;

                    // Verificar si la canción ya existe en la lista predeterminada
                    if (buscarCancionPorTitulo(listaCancionesPredeterminada, titulo))
                    {
                        cout << "La canción '" << titulo << "' ya existe en la lista predeterminada." << endl;
                        agregarCancion(listaCancionesAmigo, titulo, genero);
                        cout << "Cancion agregada a la lista de amigo." << endl;
                    }
                    else
                    {
                        agregarCancion(listaCancionesPredeterminada, titulo, genero);
                        cout << "Cancion agregada a la lista predeterminada." << endl;
                    }
                }
                else if (opcion == 2)
                {
                    string titulo;
                    cout << "Ingrese el título de la cancion a eliminar: ";
                    cin >> titulo;
                    eliminarCancion(listaCancionesAmigo, titulo);
                }
                else if (opcion == 3)
                {
                    cout << "esta saliendo de su playlist " << endl;
                    break;
                }
                else
                {
                    cout << "Opción no valida. Intente de nuevo." << endl;
                }

                // Mostrar las canciones actualizadas en la lista del amigo
                cout << "Lista personal actualizada:" << endl;
                mostrarCanciones(listaCancionesAmigo);
            }
        }
        else if (opcion == 3)
        {
            cout << "usted esta saliendo de las listas de reproduccion" << endl;
            break;
        }
        else
        {
            cout << "opcion no valida" << endl;
        }
    }
    Node *head = nullptr;
    // Corrección: Iterar sobre cada lista y agregar cada canción a la lista enlazada
    for (const auto &cancion : listaCancionesUsuario)
    {
        insertarInicio(head, cancion);
    }
    for (const auto &cancion : listaCancionesAmigo)
    {
        insertarInicio(head, cancion);
    }
    cout << "Lista de canciones del jam : " << endl;
    imprimirLista(head);
    return 0;
}