//--REPRESENTACION DE GRAFOS CON MATRIZ DE ADYACENCIA
//-- PARA GRAFOS NO DIRIGIDOS

#include <iostream>
using namespace std;
#define MAX 100 //--nro máximos de vertices

// Esta clase representa un grafo dirigido usando matriz de adyacencia
class Grafo {
private:
    int V;  // nro de vertices
    int matrizAdy[MAX][MAX];   // matriz de adyacencia

public:
    // constructor
    Grafo(int V);
    // inicia matriz en ceros

    void ingresarAristas();
    // mostrar grafo
    void mostrarGrafo();
};

//constructor de la clase grafo
Grafo::Grafo(int V) { 
    this->V = V; //Establece en número de vértices
    matrizAdy[V][V];
    //--inicia matriz en ceros
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
        {
            matrizAdy[i][j] = 0;
        }
    }
}
// Función insertar arista
void Grafo::ingresarAristas() {
    int u, v;
    cout << "INGRESAR ARISTAS " << endl;
    char resp = 's';
    while (resp == 's') {
        cout << "ingrese vertice inicio: " << endl;
        cin >> u;
        cout << "ingrese vertice fin: " << endl;
        cin >> v;
        //agregar arista a la matriz
        matrizAdy[u][v] = 1;
        matrizAdy[v][u] = 1;

        cout << "hay mas vertices? s/n; ";
        cin >> resp;
    }
}//Función para mostrar el grafo
void Grafo::mostrarGrafo() {
    cout << "MATRIZ DE ADYACENCIA" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
        {
            cout << " " << matrizAdy[i][j];
        }
        cout << endl;
    }
}
//Programa principal
int main()
{
    int nroVert;
    cout << "ingrese el nro. de vertices: ";
    cin >> nroVert;
    //--creamos el grafo
    Grafo g(nroVert);
    //--ingresar aristas de grafo no dirigido
    g.ingresarAristas();
    //--muestra el gradfo representado con matriz de ady.
    g.mostrarGrafo();

    system("pause");
    return 0;
}