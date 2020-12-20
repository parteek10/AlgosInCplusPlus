//to determine mst

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    vector<vector<int>> adjM;
    int V;

    int minDistance(vector<bool> mset, vector<int> dis)
    {
        int min = INT_MAX, minIndex;
        for (int i = 0; i < V; i++)
        {
            if (mset[i] == false && dis[i] != INT_MAX && dis[i] < min)
            {
                min = dis[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

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

    void Prim(int src)
    {
        vector<int> parent(V, -1), distance(V, INT_MAX);
        vector<bool> mset(V, false);
        distance[src] = 0;
        int u, i, j;
        for (i = 0; i < V; i++)
        {
            u = minDistance(mset, distance);
            mset[u] = true;
            for (j = 0; j < V; j++)
            {
                if (adjM[u][j] != 0 && mset[j] == false && distance[j] > adjM[u][j])
                {
                    distance[j] = adjM[u][j];
                    parent[j] = u;
                }
            }
        }

        for (i = 0; i < V; i++)
        {
            if (parent[i] != -1)
                cout << parent[i] << " -> " << i << " = " << adjM[parent[i]][i] << endl;
        }
    }
};

int main()
{
    vector<vector<int>> v = {{0, 2, 0, 6, 0},
                             {2, 0, 3, 8, 5},
                             {0, 3, 0, 0, 7},
                             {6, 8, 0, 0, 9},
                             {0, 5, 7, 9, 0}};

    Graph gp(5, v);
    gp.Prim(0);
}
