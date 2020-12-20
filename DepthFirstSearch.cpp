#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    vector<int> *adj;
    int V;

    void DFSVisit(int u, vector<int> &parent, vector<bool> &visited)
    {
        visited[u] = true;
        cout << u << " ";
        for (int child : adj[u])
        {
            if (visited[child] == false)
            {
                parent[child] = u;
                DFSVisit(child, parent, visited);
            }
        }
    }

public:
    Graph(int v)
    {
        this->V = v;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // adj[v].push_back(u); //bidirectional undirected Graph
    }

    void DFS()
    {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                DFSVisit(i, parent, visited);
            }
        }
    }

    //using stack
    // void DFS()
    // {
    //     stack<int> s;
    //     vector<int> parent(V, -1);
    //     vector<bool> visited(V, false);

    //     for (int i = 0; i < V; i++)
    //     {
    //         if (visited[i] == false)
    //         {
    //             s.push(i);
    //             while (s.empty() == false)
    //             {
    //                 int ele = s.top();
    //                 s.pop();
    //                 if (visited[ele] == false)
    //                 {
    //                     cout << ele << " ";
    //                     visited[ele] = true;
    //                     for (int child : adj[ele])
    //                     {
    //                         if (visited[child] == false)
    //                         {
    //                             parent[child] = ele;
    //                             s.push(child);
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
};

int main()
{
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    // g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.DFS();
}