// Programa que muestra la clasifiación topológica
// de un Grafo Acíclico Dirigido
#include <iostream>
#include <list>
#include <stack>
using namespace std;
 
// Clase para representar un grafo
class Graph {
    // Número de vértices
    int V;
 
    // Puntero ala matriz de adyacencia listsList
    list<int>* adj;
 
    // Funcion de clasificación topológica
    void topologicalSortUtil(int v, bool visited[],
                             stack<int>& Stack);
 
public:
    // Constructor
    Graph(int V);
 
    // funcion para agrearuna arista al grafo
    void addEdge(int v, int w);
 
    // Muestra la clasificación topológica del grafo completo 
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    // agrega w al final de la lista de v's
    adj[v].push_back(w);
}
 
// Funcion racursiva para la clasificacion topologica
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Marcar el nodo actual como visitado.
    visited[v] = true;
 
    // Recorrer todos los vértices
    // adyacentes a éste vértice
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    // Colocar el vértice actual para apilar
    // conlos resultados almacenados
    Stack.push(v);
}
 
// Funcion para hacer la clasificación topológica
// Se utiliza rcursivamente topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
 
    // Marcar todo los vértices como no visitados
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Llamar a la funcion auxiliar recursiva
    // para almacenar topologicamete
    // Ordenar a partir de todos
    // los vértices uno por uno
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    // Mostrar el contenido de la pila
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
 

int main()
{
    // Creando un grafo
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
  
   
 
    cout << "Clasificación topológica del  "
            "grafo \n";
 
    //Llamar a la función
    g.topologicalSort();
 
    return 0;
}