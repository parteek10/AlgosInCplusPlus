#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
using namespace std;

// bool cmp(Edge a , Edge b )  {
//     if(a.weight >= b.weight )
//        return true ;
//     else
//         return false ;
// }

class Edge
{
public:
    int src, dest, weight;
};

class Subset
{
public:
    int parent, rank;
};

class Graph
{
    vector<vector<int>> adjM;
    int V;

    // bool cmp(Edge a, Edge b)
    // {
    //     if (a.weight <= b.weight)
    //         return true;
    //     else
    //         return false;
    // }

    int findset(vector<Subset> &parent, int u)
    {
        if (parent[u].parent != u)
        {
            parent[u].parent = findset(parent, parent[u].parent);
        }
        return parent[u].parent;
    }

    void unionAll(vector<Subset> &parent, int u, int v)
    {
        int uParent = findset(parent, u);
        int vParent = findset(parent, v);
        if (parent[uParent].rank < parent[vParent].rank)
        {
            parent[uParent].parent = vParent;
        }
        else if (parent[uParent].rank > parent[vParent].rank)
        {
            parent[vParent].parent = uParent;
        }
        else
        {
            parent[uParent].parent = vParent;
            parent[vParent].rank++;
        }
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

    bool cmp(const Edge &a, const Edge &b)
    {
        if (a.weight <= b.weight)
            return true;
        else
            return false;
    }

    void krushkal()
    {
        // vector<Edge> edges;
        // vector<Edge> result;
        vector<Subset> parent(V);
        multimap<int, pair<int, int>> edges;
        multimap<int, pair<int, int>> result;
        int i, j;
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (adjM[i][j] != 0)
                {
                    edges.insert(make_pair(adjM[i][j], make_pair(i, j)));
                    // Edge a;
                    // a.src = i;
                    // a.dest = j;
                    // a.weight = adjM[i][j];
                    // edges.push_back(a);
                }
            }
        }

        cout << "edges : " << edges.size() << endl;

        // sort(edges.begin(), edges.end(), cmp);

        for (i = 0; i < V; i++)
        {
            parent[i].parent = i;
            parent[i].rank = 0;
        }

        int u, v;
        multimap<int, pair<int, int>>::iterator it;
        for (it = edges.begin(); it != edges.end(); it++)
        {
            u = (*it).second.first;
            v = (*it).second.second;
            if (findset(parent, u) != findset(parent, v))
            {
                unionAll(parent, u, v);
                result.insert((*it));
            }
        }

        for (it = result.begin(); it != result.end(); it++)
            cout << (*it).second.first << " -> " << (*it).second.second << " : " << (*it).first << endl;

        // int n = edges.size(), u, v;
        // for (i = 0; i < n; i++)
        // {
        //     u = edges[i].src;
        //     v = edges[i].dest;
        // if (findset(parent, u) != findset(parent, v))
        // {
        //     unionAll(parent, u, v);
        //     result.push_back(edges[i]);
        // }
        // }

        // n = result.size();
        // for (i = 0; i < n; i++)
        //     cout << result[i].src << " -> " << result[i].dest << " : " << result[i].weight << endl;
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
    gp.krushkal();
}
