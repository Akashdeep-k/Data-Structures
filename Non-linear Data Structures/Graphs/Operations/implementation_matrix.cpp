// Unweighted graph representation with adjacency matrix
// Space Complexity : O(n^2)
#include <iostream>
using namespace std;
class graph
{
    int nodes;
    int **arr;

public:
    graph() {}
    graph(int nodes)
    {
        this->nodes = nodes;
        this->arr = new int *[nodes];
        for (int i = 0; i < nodes; i++)
        {
            this->arr[i] = new int[nodes]{0};
        }
    }
    void InsertEdge(int s, int e)
    {
        arr[s - 1][e - 1] = 1;
        arr[e - 1][s - 1] = 1;
    }
    void Printg()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~graph()
    {
        for (int i = 0; i < nodes; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main()
{
    cout << "Enter number of nodes : " << endl;
    int n;
    cin >> n;
    graph g(n);
    cout << "Enter number of edges : " << endl;
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter start, end of edge " << i + 1 << endl;
        int s, e;
        cin >> s >> e;
        g.InsertEdge(s, e);
    }
    g.Printg();
    return 0;
}
