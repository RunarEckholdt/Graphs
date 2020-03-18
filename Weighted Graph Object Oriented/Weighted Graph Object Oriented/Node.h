
#include "Edge.h"
//#include "..\..\std_lib_facilities.h"
template <typename T>
class Node
{
	T val;
	vector<Edge<T>*> edges;
	bool inVector(Edge<T>*);
public:
	Node(T val);
	~Node();
	void addEdge(Edge<T>*);
	void removeEdge(Edge<T>*);
	int amountOfEdges();
	Edge<T>* edgeAtIndex(int index);
};

template<typename T>
inline Node<T>::Node(T val):val(val)
{}

template<typename T>
inline Node<T>::~Node(){
	for (Edge<T>* edge : edges) {
		delete edge;
	}
}

template<typename T>
inline bool Node<T>::inVector(Edge<T>* edge) {
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == edge)return true;
	}
	return false;
}

template<typename T>
inline void Node<T>::addEdge(Edge<T>* edge) {
	if (!inVector(edge))
		edges.push_back(edge);
	else
		error("Edge was already added");
}

template<typename T>
inline void Node<T>::removeEdge(Edge<T>* edge){
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i] == edge) {
			edges.erase(edges.begin() + i);
			break;
		}
	}
}

template<typename T>
inline int Node<T>::amountOfEdges(){
	return edges.size();
}


template<typename T>
inline Edge<T>* Node<T>::edgeAtIndex(int index){
	Edge<T>* edge = edges[index];
	return edge;
}


