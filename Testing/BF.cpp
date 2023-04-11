#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V = 5;
    int E = 4;
    int src = 0;
    int max = 1000000;

    int graph[E][3];

    cout << "\n Enter source: ";
    cin >> src;

    cout <<"\n Enter values: \n";
    for(int i=0; i<E; i++)
    {
        int u, v, w;
        cout << "\n Enter a node: ";
        cin >> u;
        cout << "\n Enter node connected to this node: ";
        cin >> v;
        cout << "\n Enter cost:";
        cin >> w;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = w;
    }

    int dis[V];
    for(int i=0; i<V; i++)
        dis[i] = max;
    dis[src] = 0;

    for(int i=0; i<V-1; i++)
    {
        for(int j=0; j<E; j++)
        {
            if(dis[graph[j][0]] !=max && dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2]; 
        }
    }
    cout <<"\n Distances:";
    for(int i=0; i<V; i++)
        cout << dis[i] << " ";

    return 0;
}