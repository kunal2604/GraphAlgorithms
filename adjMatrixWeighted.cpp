#include<iostream>

using namespace std;


class Graph{
	int ** vertex_matrix;
	int numVertices, numEdges;

public:
	Graph(int v = 10) :numVertices(v){
		
		numEdges = 0;
		vertex_matrix = new int*[numVertices];

		for(int i=0; i<numVertices; i++){
			vertex_matrix[i] = new int[numVertices];
		}
		
		for(int i=0; i<numVertices; i++){
			for(int j=0; j<numVertices; j++){
				vertex_matrix[i][j] = 0;	
			}
		}
	
	}

	~Graph(){
		for(int i=0; i<numVertices; i++){
			delete[] vertex_matrix[i];
		}
		delete[] vertex_matrix;
	}

	void addEdge(int v1, int v2, int weight=1){
		if(vertex_matrix[v1-1][v2-1] == 0){
			numEdges++;
		}
		vertex_matrix[v1-1][v2-1] = weight;
		vertex_matrix[v2-1][v1-1] = weight;
	}

	void delEdge(int v1, int v2){
		if(vertex_matrix[v1-1][v2-1] != 0)
			numEdges--;
		vertex_matrix[v1-1][v2-1] = 0;
		vertex_matrix[v2-1][v1-1] = 0;
	}

	void test(){
		cout << "V: " << numVertices << ", E: " << numEdges;
	}

	void printGraph() {
		for(int i=0; i<numVertices; i++){
			cout << (i+1) << "->";
			for(int j=0; j<numVertices; j++){
				if(vertex_matrix[i][j] != 0)
				{		
					cout << (j+1) <<"(" <<vertex_matrix[i][j] <<") ; ";
				}
				cout << "";
			}
			cout << endl;
		}
	}
	
	void printMatrix() {
		int t;
		for(int i=0; i<numVertices; i++){
			cout << (i+1) << "->";
			t = 0;
			for(int j=0; j<numVertices; j++){
				t = 0;
				if(vertex_matrix[i][j] != 0)
						t = 1;
				cout << t;
				cout << " ";
			}
			cout << endl;
		}
	}
};

int main(){
	Graph g(6);
	g.addEdge(1,2, 5);	
	g.addEdge(1,3, 4);
	g.addEdge(1,6, 3);
	g.addEdge(2,4, 3);
	g.addEdge(3,4 ,6);
	g.addEdge(3,5);
	g.addEdge(3,6);
	g.addEdge(5,6);
	
	g.printGraph();
	cout <<"\n----------------\n";
	g.printMatrix();
return 0;
}
