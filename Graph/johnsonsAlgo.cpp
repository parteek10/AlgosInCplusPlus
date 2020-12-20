#include <iostream>
#include <vector>
using namespace std;
class Graph
{
    int V;
    vector<vector<int>> adjM;

public:
    Graph(vector<vector<int>> gp, int v)
    {
        adjM = gp;
        this->V = v;
    }

    void Johnson()
    {
        vector<vector<int>> adjTemp = adjM;
        int i, j;
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
                if (adjTemp[i][j] == 0 && i != j)
                    adjTemp[i][j] = INT_MAX;
            adjTemp[i].push_back(INT_MAX);
        }

        vector<int> temp(V + 1, 0);
        adjTemp.push_back(temp);
        vector<int> distance(V + 1, INT_MAX);
        if (BellmannFord(adjTemp, distance))
        {
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {
                    if (adjTemp[i][j] != INT_MAX)
                    {
                        adjTemp[i][j] = adjTemp[i][j] + distance[i] - distance[j];
                    }
                }
            }

            vector<vector<int>> result = Dijkstra(adjTemp);
            for (auto p : result)
            {
                for (auto q : p)
                    cout << q << " ";
                cout << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "A negative weight cycle exist in the graph .";
        }
    }

    vector<vector<int>> Dijkstra(vector<vector<int>> &adjTemp)
    {
        vector<vector<int>> result;
        int u = 0, i, j, k;
        for (i = 0; i < V; i++)
        {
            vector<int> dist(V, INT_MAX);
            vector<int> visited(V, 0);
            dist[i] = 0;
            for (j = 0; j < V; j++)
            {
                u = min_dist(dist, visited);
                visited[u] = 1;
                for (k = 0; k < V; k++)
                {
                    if (adjTemp[u][k] != INT_MAX && visited[k] == 0 && dist[u] != INT_MAX && dist[k] > dist[u] + adjTemp[u][k])
                    {
                        dist[k] = dist[u] + adjTemp[u][k];
                    }
                }
            }
            result.push_back(dist);
        }
        return result;
    }

    int min_dist(vector<int> dist, vector<int> visited)
    {
        int i, j, min = INT_MAX, idx;
        for (i = 0; i < V; i++)
        {
            if (visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                idx = i;
            }
        }
        return idx;
    }

    bool BellmannFord(vector<vector<int>> adjTemp, vector<int> &distance)
    {
        distance[V] = 0;
        int i, j;
        vector<vector<int>> edges;

        for (i = 0; i <= V; i++)
        {
            for (j = 0; j <= V; j++)
            {
                if (adjTemp[i][j] != INT_MAX)
                {
                    vector<int> edge;
                    edge.push_back(i);
                    edge.push_back(j);
                    edge.push_back(adjTemp[i][j]);
                    edges.push_back(edge);
                }
            }
        }

        int u, v, w;
        for (i = 0; i < V; i++)
        {
            for (auto edge : edges)
            {
                u = edge[0];
                v = edge[1];
                w = edge[2];
                if (distance[u] != INT_MAX && distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                }
            }
        }

        for (auto edge : edges)
        {
            u = edge[0];
            v = edge[1];
            w = edge[2];
            if (distance[v] > distance[u] + w)
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<vector<int>> v = {{0, 2, 0, 6, 0},
                             {2, 0, 3, 8, 5},
                             {0, 3, 0, 0, 7},
                             {6, 8, 0, 0, 9},
                             {0, 5, 7, 9, 0}};

    Graph gp(v, 5);
    gp.Johnson();
}