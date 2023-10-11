/*
Below is Bellman-Ford algorithm that generates random edges with random weights and vertices and then prints the 
randomly generated graph, ask for source node and then shows the sortest path , from the source node to all other nodes.
*/

#include <bits/stdc++.h>


using namespace std;

const int INF = INT_MAX;

// Function to perform the Bellman-Ford algorithm
void BellmanFord(vector<vector<int>>& graph, int numVertices, int source) {
    vector<int> distance(numVertices, INF);
    distance[source] = 0;

    for (int i = 0; i < numVertices - 1; i++) {
        for (int u = 0; u < numVertices; u++) {
            for (int v = 0; v < numVertices; v++) {
                if (graph[u][v] != INF && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 0; u < numVertices; u++) {
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] != INF && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                cout << "Graph contains a negative weight cycle!" << endl;
                return;
            }
        }
    }

    // Print the shortest distances from the source to all other vertices
    cout << "Shortest distances from vertex " << source << " to all other vertices:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, INF));

    // Generate random edges
    cout << "Randomly generated edges:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i != j) {
                int weight = rand() % 100; // Random edge weight between 0 and 99
                graph[i][j] = weight;
                if (weight != INF) {
                    numEdges++;
                    cout << "Edge " << i << " -> " << j << " with weight " << weight << endl;
                }
            }
        }
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    BellmanFord(graph, numVertices, source);

    return 0;
}
