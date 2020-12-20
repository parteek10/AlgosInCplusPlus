#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    vector<vector<int>> adjM;
    int V;

public:
    Graph(int v)
    {
        this->V = v;
        adjM = vector<vector<int>>(V);
        for (int i = 0; i < V; i++)
            adjM[i] = vector<int>(V);
    }

    Graph(int v, vector<vector<int>> matrix)
    {
        this->V = v;
        adjM = matrix;
    }

    void addEdge(int src, int dest, int weight)
    {
        adjM[src][dest] = weight;
    }

    void BellMannFord(int src)
    {

        vector<int> parent(V, -1), distance(V, INT_MAX);
        distance[src] = 0;
        int i, j;
        vector<vector<int>> edges;
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (adjM[i][j] != 0)
                {
                    vector<int> temp; //to store src , destination , weight
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(adjM[i][j]);
                    edges.push_back(temp);
                }
            }
        }

        int u, v, weight;
        for (i = 0; i < V - 1; i++)
        {
            for (j = 0; j < edges.size(); j++)
            {
                u = edges[j][0];
                v = edges[j][1];
                weight = edges[j][2];
                if (distance[u] != INT_MAX && distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        for (j = 0; j < edges.size(); j++)
        {
            u = edges[j][0];
            v = edges[j][1];
            weight = edges[j][2];
            if (distance[u] != INT_MAX && distance[v] > distance[u] + weight)
            {
                cout << "Negative weight edge cycle exist . Shortest distance Cannot be found .\n";
                return;
            }
        }

        cout << "Minimum Distance from source vertex is : \n";
        for (i = 0; i < V; i++)
        {
            cout << src << " - > " << i << " : " << distance[i] << endl;
        }
    }
};

int main()
{
    // vector<vector<int>> v = {{0, 2, 0, 6, 0},
    //                          {2, 0, 3, 8, 5},
    //                          {0, 3, 0, 0, 7},
    //                          {6, 8, 0, 0, 9},
    //                          {0, 5, 7, 9, 0}};

    vector<vector<int>> v = {{0, 0, 0, 0, -1, 0, 0},
                             {1, 0, 0, 2, 0, 0, 0},
                             {0, 2, 0, 0, 0, -8, 0},
                             {-4, 0, 0, 0, 3, 0, 0},
                             {0, 7, 0, 0, 0, 0, 0},
                             {0, 5, 10, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1}};

    Graph gp(7, v);
    gp.BellMannFord(6);
}
