// Programa que muestra el recorrido DFS
//un vértice dado enun grafo dado
#include <bits/stdc++.h>
using namespace std;
 
// La clase Graph, representa un grafo dirigido
// utilizando listas adyacentes
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
 
    // Funcion para agregar una arista al grafo
    void addEdge(int v, int w);
 
    // DFS transversal de los vértices
    // accesible desde v
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Agregar w a la lista de v's al final
}
 
void Graph::DFS(int v)
{
    //Marcar el nodo actual como visitado e
    // imprímelo
    visited[v] = true;
    cout << v << " ";
 
    // Recurrencia para todos los vértices adyacentes
    // a este vértice
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}
 

int main()
{
    // Creando el grafo
    Graph g;
    /*g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);*/

    g.addEdge( 1 , 2 );
    g.addEdge( 1 , 3 );
    g.addEdge( 1 , 4 );
    g.addEdge( 1 , 5 );
    g.addEdge( 3 , 2 );
    g.addEdge( 4 , 3 );
    g.addEdge( 4 , 8 );
    g.addEdge( 7 , 2 );
    g.addEdge( 3 , 6 );
    g.addEdge( 3 , 8 );
    g.addEdge( 4 , 8 );
    g.addEdge( 9 , 5 );
    g.addEdge( 9 , 8 );
    g.addEdge( 8 , 6 );
    g.addEdge( 6 , 7 );
 
    cout << "Recorrido en profundidad"
            " (A partir del vértice 2) \n";
    g.DFS(1);
 
    return 0;
}