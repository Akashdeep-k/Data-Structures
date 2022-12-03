// Weighted digraph representation with adjacency list
// Space complexity : O(n + e) -> O(n) i.e linear where n is number of vertices and e is number of directed edges
#include <iostream>
using namespace std;
class node
{ // edge
public:
    int end;
    int weight;
    node *next;
    node() {}
    node(int end, int weight)
    {
        this->end = end;
        this->weight = weight;
        this->next = NULL;
    }
};
class graph
{
    int nodes; // vertex
    node **arr;

public:
    graph(int nodes)
    {
        this->nodes = nodes;
        this->arr = new node *[nodes]
        { NULL };
    }
    void InsertEdge(int s, int e, int w)
    {
        if (arr[s - 1] == NULL)
        {
            arr[s - 1] = new node(e, w);
        }
        else
        {
            node *temp = new node(e, w);
            temp->next = arr[s - 1];
            arr[s - 1] = temp;
        }
    }
    void PrintList(node *head)
    {
        while (head->next != NULL)
        {
            cout << head->end << " " << head->weight << " -> ";
            head = head->next;
        }
        cout << head->end << " " << head->weight << endl;
    }
    void Printg()
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << "Vertex " << i << " is connected to vertices -> ";
            PrintList(arr[i]);
        }
        cout << endl;
    }
};
int main()
{
    cout << "Enter number of vertex in graph : " << endl;
    int vertex;
    cin >> vertex;
    graph g(vertex);
    cout << "Enter number of edges in graph : " << endl;
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter start, end and weight of the edge : " << i + 1 << endl;
        int s, e, w;
        cin >> s >> e >> w;
        g.InsertEdge(s, e, w);
    }
    g.Printg();
    return 0;
}