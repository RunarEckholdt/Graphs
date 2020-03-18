
#include "Node.h"


template <typename T>
class Graph
{
	vector<Node<T>*> nodes;
	vector<Edge<T>*> edges;
public:
	Graph();
	~Graph();
	void addNode(T val);
	void deleteNode(Node<T>*);
	void addEdge(Node<T>*,Node<T>*,int weight);
	void addEdge(Node<T>*, Node<T>*, int weight,bool biDirectional);

};



template<typename T>
inline Graph<T>::Graph()
{
}

template<typename T>
inline Graph<T>::~Graph()
{
}

template<typename T>
inline void Graph<T>::addNode(T val){
	Node<T>* node = new Node<T>(val);
}

template<typename T>
inline void Graph<T>::deleteNode(Node<T>* node){
	for (int i = 0; i < nodes.size()) {
		if (nodes[i] == node)nodes.erase(nodes.begin() + i);
	}
	for(int i = 0; i < node->)
}

template<typename T>
inline void Graph<T>::addEdge(Node<T>* n1, Node<T>* n2, int w){
	Edge<T> edge = new Edge<T>(n1, n2, w);
	n1->addEdge(edge);
	edges.push_back(edge);
}

template<typename T>
inline void Graph<T>::addEdge(Node<T>* n1, Node<T>* n2, int w, bool bD){
	Edge<T> edge = new Edge<T>(n1, n2, w,bD);
	n1->addEdge(edge);
	edges.push_back(edge);
	if (bD) n2->addEdge(edge);
}



