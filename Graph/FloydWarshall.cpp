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

    void FloydWarshall()
    {
        vector<vector<int>> minD = adjM;
        vector<vector<int>> parent(V, vector<int>(V, -1));
        int i, j, k;
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (adjM[i][j] != 0)
                {
                    parent[i][j] = i + 1; // to change parent ***********
                }
                else
                {
                    minD[i][j] = INT_MAX;
                }
                if (i == j)
                {
                    // parent[i][j] = 0 ;
                    minD[i][j] = 0;
                }
            }
        }

        for (k = 0; k < V; k++)
        {
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {
                    if (minD[i][k] != INT_MAX && minD[k][j] != INT_MAX && minD[i][j] > minD[i][k] + minD[k][j])
                    {
                        minD[i][j] = minD[i][k] + minD[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }

            cout << "******** k = " << k + 1 << endl;
            cout << "\nDistance Matrix \n";
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                    cout << minD[i][j] << " ";
                cout << endl;
            }

            cout << "\nParent Matrix \n";
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                    cout << parent[i][j] << " ";
                cout << endl;
            }

            cout << endl;
        }

        cout << "---------------final  result --\n";

        cout << "Adjaceny Matrix \n";
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
                cout << adjM[i][j] << " ";
            cout << endl;
        }

        cout << "Distance Matrix \n";
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
                cout << minD[i][j] << " ";
            cout << endl;
        }

        cout << "Parent Matrix \n";
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
                cout << parent[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<int>> v = {
        {0, 3, 8, 0, -4},
        {0, 0, 0, 1, 7},
        {0, 4, 0, 0, 0},
        {2, 0, -5, 0, 0},
        {0, 0, 0, 6, 0},
    };

    Graph gp(5, v);
    gp.FloydWarshall();
}
