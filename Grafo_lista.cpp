#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Esta clase representa un grafo dirigido usando una lista de adyacencia
class Grafo
{
    int V;    // No. de vertices
    
              // Puntero a un arreglo de listas que contiene la lista adyacencia del grafo
    vector<list<int>> adj;
public:
    Grafo(int V);  // Constructor

    // función que agrega un arista desde v hasta w
    void insertaArista(int v, int w);

    //  imprime el grafo 
    void printGrafo(Grafo g, int V);

    // muestra la lista de adyacencia 
    void showlist(list<int> g);
};

//constructor de la clase grafo
Grafo::Grafo(int V)
{
    this->V = V; //Establece en número de vértices
    adj.resize(V); //--redimensiona el vector de listas de adyacencia
}
//Función insertar arista
void Grafo::insertaArista(int v, int w)
{
    adj[v].push_back(w); // Agrega w al final de la lista de v.
}

// Función para mostrar el grafo
void Grafo::showlist(list<int> g)
//--mostra contenido de la lista g
{
    // 'it' se usa para obtener los vértices adyacentes

    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
//Función para imprimir la lista de adyacencia
void Grafo::printGrafo(Grafo g, int V)
//--muestra el grafo representado por listas de adyacencia
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Lista de adyacencia de vertice " << v
            << "\n head ";
        showlist(adj[v]);
    }
}

//Programa principal
int main()
{
    // Crea el grafo
    Grafo g(4);
    g.insertaArista(0, 1);
    g.insertaArista(0, 2);
    g.insertaArista(1, 2);
    g.insertaArista(2, 0);
    g.insertaArista(2, 3);
    g.insertaArista(3, 3);

    g.printGrafo(g, 4);

   
    system("pause");
    return 0;
}
