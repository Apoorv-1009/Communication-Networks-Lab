#include <bits/stdc++.h>
using namespace std;
 
void BellmanFord(int graph[][3], int V, int E, int src)
{
    // Initialize distance of all vertices as infinite.
    int dis[V];
    for(int i=0; i<V; i++)
        dis[i] = INT_MAX;
 
    // Initialize distance of source as 0
    dis[src] = 0;
    for(int i=0; i<V-1; i++) 
    {
        for(int j=0; j<E; j++) 
        {
            if(dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }

 
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dis[i] << endl;
}
 
int main()
{
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    int src = 0;

    cout << "\n Enter number of Nodes: ";
    cin >> V;
    cout << "Enter number of Edges: ";
    cin >> E;
    cout << "Enter source node: ";
    cin >> src;
    cout << "\n";
    int graph[E][3];
    cout << "****************************************************";
    
    for(int i=0; i<E; i++)
    {
        int u, v, w;
        cout << "\nEnter a node: ";
        cin >> u;
        cout << "Enter node attached to this node: ";
        cin >> v;
        cout << "Enter cost between these nodes: ";
        cin >> w;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = w;
    }
 
    BellmanFord(graph, V, E, src);
    return 0;
}