
#include "Graph.h"


int main()
{
    Graph<int>* graph = new Graph<int>;
    for (int i = 0; i < 10; i++) {
        graph->addNode(i);
        
    }
    vector<Node<int>*> nodes = graph->getNodes();
    nodes[0]->printValue();

    cout << graph;
}

