
#include "Graph.h"


int main()
{
    Graph<int>* graph = new Graph<int>;
    for (int i = 0; i < 10; i++) {
        graph->addNode(i);
        
    }
    graph->addEdge(graph->getNode(0), graph->getNode(1), 2, 1);
    graph->addEdge(graph->getNode(0), graph->getNode(4), 1, 1);
    graph->addEdge(graph->getNode(3), graph->getNode(4), 4, 1);
    graph->addEdge(graph->getNode(3), graph->getNode(8), 5, 1);
    graph->addEdge(graph->getNode(6), graph->getNode(7), 3, 1);
    graph->addEdge(graph->getNode(3), graph->getNode(7), 9, 1);
    graph->addEdge(graph->getNode(7), graph->getNode(8), 2, 1);
    graph->addEdge(graph->getNode(0), graph->getNode(3), 4, 1);
    graph->addEdge(graph->getNode(2), graph->getNode(1), 3, 1);
    graph->addEdge(graph->getNode(2), graph->getNode(9), 6, 1);
    graph->addEdge(graph->getNode(2), graph->getNode(5), 2, 1);
    graph->addEdge(graph->getNode(5), graph->getNode(9), 2, 1);
    

    cout << "Graph:" << endl;
    cout << graph << endl << endl;
    Graph<int>* spanningTree = graph->prims();
  
    cout << "Spanning tree: " << endl;
    cout << spanningTree << endl << endl;

    delete spanningTree;
    delete graph;



    
}

