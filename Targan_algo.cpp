//To Find the articulation Point of a undirected Graph

#include <iostream>
#include <vector>
using namespace std;
class Graph
{
    vector<int> *adj;
    int V;

    void apSearch(int u, vector<bool> &visited, vector<int> &parent, vector<int> &disc, vector<int> &low, vector<bool> &ap)
    {
        static int time = 0;
        int children = 0;
        visited[u] = true;
        disc[u] = time;
        low[u] = time;
        time++;

        for (int child : adj[u])
        {
            if (visited[child] == false)
            {
                children++;
                parent[child] = u;
                apSearch(child, visited, parent, disc, low, ap);
                low[u] = min(low[u], low[child]);
                if (parent[u] == -1 && children > 1)
                    ap[u] = true;
                if (parent[u] != -1 && low[child] > disc[u])
                    ap[u] = true;
            }
            else if (child != parent[u])
                low[u] = min(low[u], disc[child]);
        }
    }

public:
    Graph(int v)
    {
        adj = new vector<int>[v];
        this->V = v;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); //bidirectional undirected edge
    }

    void AP()
    {
        vector<int> parent(V, -1), low(V, 0), disc(V, 0);
        vector<bool> visited(V, false), ap(V, false);
        int i;

        for (i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                apSearch(i, visited, parent, disc, low, ap);
            }
        }

        for (i = 0; i < V; i++)
        {
            if (ap[i])
            {
                cout << i << " ";
            }
        }
    }
};

int main()
{
    // Graph gp()
    cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.AP();

    cout << "\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.AP();

    cout << "\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.AP();
}