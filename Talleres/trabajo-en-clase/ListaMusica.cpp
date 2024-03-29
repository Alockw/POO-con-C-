#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
// STL: Biblioteca de plantillas estándar de C++ para simplificar el manejo de contenedores y algoritmos.
struct Cancion
{
    string titulo;   // Atributo para el título de la canción
    string cantante; // Atributo para el cantante
    string duracion; // Atributo para la duracion
    // Constructor para inicializar una canción con título y género
    Cancion(string titulo, string cantante, string duracion) : titulo(titulo), cantante(cantante), duracion(duracion) {}
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
        cout << "Titulo: " << head->data.titulo << ", Cantante: " << head->data.cantante << ", Duracion: " << head->data.duracion << endl; // Imprime los datos del nodo actual
        head = head->next;                                                                                                                 // Avanza al siguiente nodo
    }
}

// Función para mostrar la lista de canciones
void mostrarCanciones(const list<Cancion> &canciones)
{
    for (const auto &cancion : canciones) // Para cada canción en la lista
    {
        cout << "Titulo: " << cancion.titulo << ", Cantante: " << cancion.cantante << ", Duracion: " << cancion.duracion << endl; // Imprime los datos de la canción
    }
}

// Función para agregar una canción a la lista
void agregarCancion(list<Cancion> &canciones, string titulo, string cantante, string duracion)
{
    canciones.push_back(Cancion(titulo, cantante, duracion)); // Agrega una nueva canción al final de la lista
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
// Función para verificar si una canción ya existe en la lista enlazada
bool existeCancionEnLista(Node *head, const string &titulo)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data.titulo == titulo)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
// Función para ordenar la lista de canciones por cantantes
void ordenarCantantes(Node *&head)
{
    // Si la lista está vacía o solo tiene un elemento, no hay necesidad de ordenar
    if (head == nullptr || head->next == nullptr)
        return;

    // Crea una lista de la STL para almacenar las canciones temporariamente
    list<Cancion> canciones;
    Node *current = head; // Inicializa un puntero al nodo actual
    while (current != nullptr)
    {
        // Añade cada canción de la lista enlazada a la lista de la STL
        canciones.push_back(current->data);
        current = current->next; // Avanza al siguiente nodo
    }

    // Ordena la lista de canciones por cantantes, y en caso de empate, por duración
    canciones.sort([](const Cancion &a, const Cancion &b)
                   {
        if (a.cantante != b.cantante) {
            return a.cantante > b.cantante; // Ordena por cantantes en orden descendente
        } else {
            // En caso de empate, ordena por duración en orden descendente
            int duracionA = stoi(a.duracion.substr(0, a.duracion.find(':')));
            int duracionB = stoi(b.duracion.substr(0, b.duracion.find(':')));
            return duracionA > duracionB;
        } });

    // Vacía la lista enlazada original
    head = nullptr;
    // Reconstruye la lista enlazada con las canciones ordenadas
    for (const auto &cancion : canciones)
    {
        insertarInicio(head, cancion);
    }
}

// Función para ordenar la lista de canciones por títulos
void ordenarTitulos(Node *&head)
{
    // Si la lista está vacía o solo tiene un elemento, no hay necesidad de ordenar
    if (head == nullptr || head->next == nullptr)
        return;

    // Crea una lista de la STL para almacenar las canciones temporariamente
    list<Cancion> canciones;
    Node *current = head; // Inicializa un puntero al nodo actual
    while (current != nullptr)
    {
        // Añade cada canción de la lista enlazada a la lista de la STL
        canciones.push_back(current->data);
        current = current->next; // Avanza al siguiente nodo
    }

    // Ordena la lista de canciones por títulos en orden ascendente
    canciones.sort([](const Cancion &a, const Cancion &b)
                   { return a.titulo < b.titulo; });

    // Vacía la lista enlazada original
    head = nullptr;
    // Reconstruye la lista enlazada con las canciones ordenadas
    for (const auto &cancion : canciones)
    {
        insertarInicio(head, cancion);
    }
}

// Función para ordenar la lista de canciones por duración
void ordenarPorDuracion(Node *&head)
{
    // Si la lista está vacía o solo tiene un elemento, no hay necesidad de ordenar
    if (head == nullptr || head->next == nullptr)
        return;

    // Crea una lista de la STL para almacenar las canciones temporariamente
    list<Cancion> canciones;
    Node *current = head; // Inicializa un puntero al nodo actual
    while (current != nullptr)
    {
        // Añade cada canción de la lista enlazada a la lista de la STL
        canciones.push_back(current->data);
        current = current->next; // Avanza al siguiente nodo
    }

    // Ordena la lista de canciones por duración en orden descendente
    canciones.sort([](const Cancion &a, const Cancion &b)
                   {
        int duracionA = stoi(a.duracion.substr(0, a.duracion.find(':')));
        int duracionB = stoi(b.duracion.substr(0, b.duracion.find(':')));
        return duracionA > duracionB; });

    // Vacía la lista enlazada original
    head = nullptr;
    // Reconstruye la lista enlazada con las canciones ordenadas
    for (const auto &cancion : canciones)
    {
        insertarInicio(head, cancion);
    }
}
int main()
{
    list<Cancion> listaCancionesPredeterminada;

    // Agregar algunas canciones de ejemplo a la lista predeterminada
    agregarCancion(listaCancionesPredeterminada, "Frijolero", "panchos", "1:56");
    agregarCancion(listaCancionesPredeterminada, "Baby", "justi_bieber", "3:23");

    // Mostrar las canciones existentes en la lista predeterminada
    cout << "Lista de canciones predeterminada:" << endl;
    mostrarCanciones(listaCancionesPredeterminada);

    list<Cancion> listaCancionesUsuario;
    list<Cancion> listaCancionesAmigo;
    // Solicitar al usuario que agregue o elimine canciones de su lista personal
    int opcion;

    while (true)
    {
        cout << "que lista de reproduccion quieres escoger (1)propia o (2)amigo o(3)salir a la lista compartida" << endl;
        cin >> opcion; // Corregido: se cambió la coma por un punto y coma
        if (opcion == 1)
        {
            while (true)
            {
                cout << "Que desea hacer con su lista personal? (Agregar(1)/Eliminar(2)/Salir(3)): ";
                cin >> opcion;

                if (opcion == 1)
                {
                    string titulo, cantante, duracion;
                    cout << "Ingrese el titulo de la cancion (si tiene espacion ponga_ en cada espacio): ";
                    cin >> titulo;
                    cout << "Ingrese el cantante de la cancion: ";
                    cin >> cantante;
                    cout << "Ingrese la duracion de la cancion: ";
                    cin >> duracion;

                    // Verificar si la canción ya existe en la lista predeterminada
                    if (buscarCancionPorTitulo(listaCancionesPredeterminada, titulo))
                    {
                        cout << "La canción '" << titulo << "' ya existe en la lista predeterminada." << endl;
                        agregarCancion(listaCancionesUsuario, titulo, cantante, duracion);
                        cout << "Cancion agregada a la lista personal." << endl;
                    }
                    else
                    {
                        agregarCancion(listaCancionesPredeterminada, titulo, cantante, duracion);
                        cout << "Cancion agregada a la lista predeterminada." << endl;
                    }
                }
                else if (opcion == 2)
                {
                    string titulo;
                    cout << "Ingrese el titulo de la cancion a eliminar: ";
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
                cout << "Que desea hacer con la lista de su amigo? (Agregar(1)/Eliminar(2)/Salir(3)): ";
                cin >> opcion;

                if (opcion == 1)
                {
                    string titulo, cantante, duracion;
                    cout << "Ingrese el titulo de la cancion (si tiene espacion ponga_ en cada espacio): ";
                    cin >> titulo;
                    cout << "Ingrese el cantante de la cancion: ";
                    cin >> cantante;
                    cout << "Ingrese el genero de la cancion: ";
                    cin >> duracion;

                    // Verificar si la canción ya existe en la lista predeterminada
                    if (buscarCancionPorTitulo(listaCancionesPredeterminada, titulo))
                    {
                        cout << "La cancion '" << titulo << "' ya existe en la lista predeterminada." << endl;
                        agregarCancion(listaCancionesAmigo, titulo, cantante, duracion);
                        cout << "Cancion agregada a la lista de amigo." << endl;
                    }
                    else
                    {
                        agregarCancion(listaCancionesPredeterminada, titulo, cantante, duracion);
                        cout << "Cancion agregada a la lista predeterminada." << endl;
                    }
                }
                else if (opcion == 2)
                {
                    string titulo;
                    cout << "Ingrese el titulo de la cancion a eliminar: ";
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
                    cout << "Opcion no valida. Intente de nuevo." << endl;
                }

                // Mostrar las canciones actualizadas en la lista del amigo
                cout << "Lista de amigo actualizada:" << endl;
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
    // Iteración sobre cada canción en la lista de canciones del usuario
    for (const auto &cancion : listaCancionesUsuario)
    {
        // Verificar si la canción ya existe en la lista enlazada final
        if (!existeCancionEnLista(head, cancion.titulo))
        {
            // Insertar cada canción al inicio de la lista enlazada
            insertarInicio(head, cancion);
        }
    }

    // Iteración sobre cada canción en la lista de canciones del amigo
    for (const auto &cancion : listaCancionesAmigo)
    {
        // Verificar si la canción ya existe en la lista enlazada final
        if (!existeCancionEnLista(head, cancion.titulo))
        {
            // Insertar cada canción al inicio de la lista enlazada
            insertarInicio(head, cancion);
        }
    }

    // Imprimir el mensaje de inicio de la lista de canciones del jam
    cout << "Lista de canciones del jam : " << endl;
    imprimirLista(head);
    ordenarCantantes(head);
    cout << "Lista Ordenada (cantantes): " << endl;
    imprimirLista(head);
    ordenarTitulos(head);
    cout << "Lista Ordenada (titulos): " << endl;
    imprimirLista(head);
    ordenarPorDuracion(head);
    cout << "Lista Ordenada (duracion 1 a 3 minutos): " << endl;
    imprimirLista(head);
    return 0;
}