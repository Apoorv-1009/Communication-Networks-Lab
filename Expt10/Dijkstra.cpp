#include<iostream>
#include<climits>
using namespace std;
int nodes;
int miniDist(int distance[], bool Tset[]) // Finding minimum distance unvisited vertex
{
    int minimum = INT_MAX;
    int index;
              
    for(int k=0; k<6; k++) 
    {
        if(!Tset[k] && distance[k] <= minimum)      
        {
            minimum = distance[k];
            index = k;
        }
    }
    return index;
}

void DijkstraAlgo(int graph[10][10], int src) 
{
    //int size = sizeof(graph[0]) / sizeof(graph[0][0]);
    int distance[nodes];    // Array to calculate the minimum distance of each node from src                             
    bool Tset[nodes];   // Boolean array to mark visited and unvisited nodes
    int prev_node_list[nodes];
    prev_node_list[src] = src;
    
     
    for(int k=0; k<nodes; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k=0; k<nodes; k++)                           
    {
        int m = miniDist(distance,Tset); 
        Tset[m]=true;
        for(int j=0; j<nodes; j++)                  
        {
            // Updating the distance of neighbouring vertex
            // Conditions for updating neighbour vertex:
            // a) Not part of visited nodes
            // b) Edge cost value is not negative
            // c) Distance cost is not lowered
            if(!Tset[j] && graph[m][j] > 0 && distance[m] + graph[m][j] < distance[j])
            {
                distance[j] = distance[m] + graph[m][j];
                prev_node_list[j] = m;
            }
        }
    }
    cout<<"Vertex \t\t Distance from source vertex \n";
    for(int k=0; k<nodes; k++)                      
        cout << k << "\t\t\t" << distance[k] << "\n";
    
    cout << "\n Previous vertex list: \n";
    for(int k=0; k<nodes; k++)
        cout << k << "\t\t\t" << prev_node_list[k] << "\n";
    

}

int main()
{
    cout << "\n Enter number of nodes: ";
    cin >> nodes;
    int graph[10][10];

    int source;
    cout << "\n Enter source node: ";
    cin >> source;
    cout <<"\n";
    cout <<"*********************************************************";
    cout << "\nEnter costs: \n";
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            cout <<"Enter cost for node "<< i <<" to "<< j <<":";
            cin >> graph[i][j];
        }
    }
    cout << "\n";

    cout <<"\n Entered adjacency matrix: \n";
    for(int i=0; i<nodes; i++)
    {
        for( int j=0; j<nodes; j++)
            cout << graph[i][j] << "  ";

        cout <<"\n";
    }
    cout <<"\n";

    DijkstraAlgo(graph, source);
    return 0;                           
}

    // int graph[6][6]={{-1, 2, 1, 3, -1, -1},
    //                  {-1, -1, -1, -1, 4, -1},
    //                  {-1, -1, -1, -1, 2, 3},
    //                  {-1, -1, -1, -1, -1, 1},
    //                  {-1, -1, -1, -1, -1, 1},
    //                  {-1, -1, -1, -1, -1, 0}};   // Adjacency Matrix