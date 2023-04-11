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
 
    // Relax all edges |V| - 1 times. A simple shortest path from src to any other
    // vertex can have at-most |V| - 1 edges
    for(int i=0; i<V-1; i++) 
    {
        for(int j=0; j<E; j++) 
        {
            if(dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
        }
    }
 
    // Check for negative-weight cycles.
    // The above step guarantees shortest distances if graph doesn't contain
    // negative weight cycle.  If we get a shorter path, then there is a cycle.
    // for (int i=0; i<E; i++) 
    // {
    //     int x = graph[i][0];
    //     int y = graph[i5][1];
    //     int weight = graph[i][2];
    //     if (dis[x] != INT_MAX && dis[x] + weight < dis[y])
    //         cout << "Graph contains negative weight cycle" << endl;
    // }
 
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
 
    // Every edge has three values (u, v, w) where the edge is from vertex u to v. 
    // And weight of the edge is w.
    // int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
    //                    { 1, 2, 3 }, { 1, 3, 2 },
    //                    { 1, 4, 2 }, { 3, 2, 5 },
    //                    { 3, 1, 1 }, { 4, 3, -3 } };
 
    BellmanFord(graph, V, E, src);
    return 0;
}