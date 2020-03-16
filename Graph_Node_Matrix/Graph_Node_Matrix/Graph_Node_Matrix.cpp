
#include "Graph.h"

int main()
{
    Graph* graph = new Graph(10);
    graph->addEdge(0, 1);
    graph->addEdge(1, 5);
    graph->addEdge(1, 3);
    graph->addEdge(3, 2);
    graph->addEdge(3, 6);
    graph->addEdge(6, 4);
    graph->addEdge(7, 8);
    graph->addEdge(7, 9);
    graph->print();

    cout<<endl << graph->bfSearch(0,8)<<endl;

}