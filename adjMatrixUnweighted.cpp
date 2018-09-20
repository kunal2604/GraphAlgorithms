#include <iostream>
using namespace std;

class Graph {
private:
      bool** adjMatrix;
      int numVertices;
public:
      Graph(int v) {
            numVertices = v;
            adjMatrix = new bool*[numVertices];
            for (int i = 0; i < numVertices; i++) {
                  adjMatrix[i] = new bool[numVertices];
                  for (int j = 0; j < numVertices; j++)
                        adjMatrix[i][j] = false;
          }
    }
 
      void addEdge(int i, int j) {
                  adjMatrix[i][j] = true;
                  adjMatrix[j][i] = true;
    }
 
      void removeEdge(int i, int j) {
                  adjMatrix[i][j] = false;
                  adjMatrix[j][i] = false;
    }
 
      bool isEdge(int i, int j) {
                  return adjMatrix[i][j];
    }

    void toString() {
      for (int i = 0; i < numVertices; i++) {
                  cout << (i+1) << " : ";
                  for (int j = 0; j < numVertices; j++)
                        cout << adjMatrix[i][j] << " ";
                  cout << "\n";
      }

    }
 
    ~Graph() {
            for (int i = 0; i < numVertices; i++)
                  delete[] adjMatrix[i];
            delete[] adjMatrix;
    }
};


int main(){
		int nodes, maxEdges, origin, destination;
		cout << "Enter number of nodes: ";
		cin >> nodes;
		Graph g(nodes);
		maxEdges = nodes * (nodes-1);
		cout << "\nMAX EDGES: " << maxEdges << endl;
		for(int i=0; i<maxEdges; i++){
				cout << "Enter edge (-1 -1 to exit) : ";
				cin >> origin >> destination;
				if(origin!=-1 && destination!=-1)
					g.addEdge(origin-1, destination-1);
				else	
					break;
		}
		g.toString();
		return 0;
		/*	
        Graph g(4);
 
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);

        
       */
		/*Outputs
           0: 0 1 1 0 
           1: 1 0 1 0 
           2: 1 1 0 1 
           3: 0 0 1 0 
          */
}