// Programa para mostrar el recorrido  BFS 
// de un grafo. BFS(int s) recorre los vertices alcanzados desde s 
#include<iostream>
#include <list>

using namespace std;

// esta clase representa un grafo dirigido con 
// la representacion de una lista de adyacencia
class Grafo
{
	int V; // No. de vertices

	// Puntero a un arreglo conteniendola lista de adyacencia 
	list<int> *adj;
public:
	Grafo(int V); // constructor

	// funcion para añadir un vertice al grafo 
	void insertavertice(int v, int w);

	// mostrar el recorrido BFS desde un vertice s
	void BFS(int s);
};

Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::insertavertice(int v, int w)
{
	adj[v-1].push_back(w-1); // añade w al final de la lista.
}

void Grafo::BFS(int s)
{
	// inicialmente marca los vertices como no visitados
	bool *visitado = new bool[V];
	for(int i = 0; i < V; i++)
		visitado[i] = false;

	// Crea una cola para BFS
	list<int> cola;

	// marca el nodo actual como visitado y lo añade a la cola
	visitado[s] = true;
	cola.push_back(s);

	// 'i' se usa para obtener los vertices adyacentes 
	
	list<int>::iterator i;

	while(!cola.empty())
	{
		// Desencola un vertice de la cola y lo muestra
		s = cola.front();
		cout << s << " ";
		cola.pop_front();

		// obtener todos los verticesadyacentes de la cola
		// Si un vertice no fue visitado,
		// marcar como visitado y añadirlo a la cola
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visitado[*i])
			{
				visitado[*i] = true;
				cola.push_back(*i);
			}
		}
	}
}

// programa principal
int main()
{
	// Grafo de ejemplo
	Grafo g(9);
//	vertices

g.insertavertice(1,2);
g.insertavertice(1,3);
g.insertavertice(1,4);
g.insertavertice(1,5);
g.insertavertice(3,2);
g.insertavertice(4,3);
g.insertavertice(4,8);
g.insertavertice(7,2);
g.insertavertice(3,6);
g.insertavertice(3,8);
g.insertavertice(4,8);
g.insertavertice(9,5);
g.insertavertice(9,8);
g.insertavertice(8,6);
g.insertavertice(6,7);

	cout << ":::: Recorrido BFS para el grafo  :::: "
		<< "(Iniciamos el el vertice 1) \n";
	g.BFS(0);

	return 0;
}
