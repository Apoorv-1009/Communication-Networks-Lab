#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cout << "\n Enter number of nodes: ";
    // cin >> n;

    // int source;
    // cout << "\n Enter source node: ";
    // cin >> source;

    // int graph[10][10];
    // cout << "\n Enter costs: " << endl;
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         cout << "Cost from " << i << " to " << j << ":";
    //         cin >> graph[i][j];
    //     }
    // }
    int n = 5;
    int source = 0;
    int graph[6][6] = {{-1, 1, -1, 1, -1},
                       {-1, -1, 2, -1, -1},
                       {-1, -1, -1, -1, 3}, 
                       {-1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1}};

    cout << "\n Entered graph: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }

    bool visited[n];
    int distance[n];

    for(int i=0; i<n; i++)
    {
        distance[i] = 1000000;
        visited[i] = false;
    }
    distance[source] = 0;
    int index;

    for(int i= 0; i<n; i++)
    {
        int dis = 1000000;
        for(int k=0; k<n; k++)
        {
            if(!visited[k] && distance[k] <= dis)
            {
                index = k;
                dis = distance[k];
            }
        }
        visited[index] = true;

        for(int k=0; k<n; k++)
        {
            if(!visited[k] && graph[index][k]>0 && distance[index] + graph[index][k] < distance[k])
                distance[k] = graph[index][k] + distance[index];
        }
    }

    cout << "\n Distance of vertex from source: ";
    for(int k=0; k<n; k++)
        cout << distance[k] << " ";
}