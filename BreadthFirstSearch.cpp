#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    vector<int> *adj;
    int V;

public:
    Graph(int v)
    {
        this->V = v;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS()
    {
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);
        queue<int> que;
        int i;
        for (i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                que.push(i);
                visited[i] = true;
                cout << i << " ";
                while (que.empty() == false)
                {
                    int u = que.front();
                    que.pop();
                    for (int child : adj[u])
                    {
                        if (visited[child] == false)
                        {
                            parent[child] = u;
                            visited[child] = true;
                            cout << child << " ";
                            que.push(child);
                        }
                    }
                }
            }
        }
    }
};

int main()
{

    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.BFS();
}