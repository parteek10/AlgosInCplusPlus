#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<vector<int>> adjM;
    int V;

    int BFS(int src, int dest, vector<int> &parent)
    {
        int i, u;
        for (i = 0; i < V; i++)
            parent[i] = -1;

        vector<bool> visited(V, false);
        queue<int> que;
        que.push(src);
        visited[src] = true;
        while (que.empty() == false)
        {
            u = que.front();
            que.pop();
            for (i = 0; i < V; i++)
            {
                if (adjM[u][i] != 0 && visited[i] == false)
                {
                    parent[i] = u;
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
        return visited[dest];
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

    int FordFulkerson(int src, int dest)
    {
        int maxFlow = 0, flow = 0, u, v, i, j;
        vector<int> parent(V);
        while (BFS(src, dest, parent))
        {
            flow = INT_MAX;
            for (u = dest; parent[u] != -1; u = parent[u])
            {
                v = parent[u];
                if (adjM[v][u] < flow)
                    flow = adjM[v][u];
            }

            for (u = dest; parent[u] != -1; u = parent[u])
            {
                v = parent[u];
                adjM[v][u] -= flow;
                adjM[u][v] += flow;
            }

            maxFlow += flow;
        }
        return maxFlow;
    }
};

int main()
{
    vector<vector<int>> v = {{0, 16, 13, 0, 0, 0},
                             {0, 0, 10, 12, 0, 0},
                             {0, 4, 0, 0, 14, 0},
                             {0, 0, 9, 0, 0, 20},
                             {0, 0, 0, 7, 0, 4},
                             {0, 0, 0, 0, 0, 0}};

    Graph gp(6, v);
    cout << gp.FordFulkerson(0, 5);
}
