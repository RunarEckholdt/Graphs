#pragma once
#include "Node.h"
#include <queue>


template<typename S>
bool inVector(S* targetPointer, vector<S*>& vec);

template<typename S>
void removeValFromVec(S* val, vector<S*>& vec);



template <typename T>
class Graph
{
	vector<Node<T>*> nodes;
	void bFSearchSize(Node<T>* current, vector<Node<T>*>& visited, queue<Node<T>*>& toVisit);
	Edge<T>* findMinCostEdge(vector<Edge<T>*>& edges,vector<Node<T>*>& copiedNodes,vector<Node<T>*>& spanningTreeNodes);
	Node<T>* findNodeInGraph(Edge<T>* edge, vector<Node<T>*>& nodes);
	Node<T>* findNodeInSpanningTree(Node<T>*, Graph<T>* spanningTree);
	bool nodeInVec(Node<T>*, vector<Node<T>*>&);
	void removeInvalidEdgesPrim(vector<Edge<T>*>&,vector<Node<T>*>&);
	//bool EdgeInVec(Node<T>*, vector<Node<T>*>&);
	
public:
	Graph();
	~Graph();
	vector<Node<T>*>& getNodes();
	Node<T>* getNode(int index);
	//bool inNodes(Node<T>*)const;
	int size()const;
	Node<T>* addNode(T val);
	void deleteNode(Node<T>*);
	void addEdge(Node<T>*,Node<T>*,int weight);
	void addEdge(Node<T>*, Node<T>*, int weight,bool biDirectional);
	void removeEdge(Node<T>*,Node<T>*);
	Node<T>* operator[](int index);
	Graph<T>* prims();
	int bFSearchSize(Node<T>* start);
	int bFSearch(Node<T>* start, const Node<T>* target);

};





template<typename T>
inline Graph<T>::Graph(){

}

template<typename T>
inline Graph<T>::~Graph(){
	for (Node<T>* node : nodes) {
		delete node;
	}
}

template<typename T>
inline vector<Node<T>*>& Graph<T>::getNodes()
{
	return nodes;
}

template<typename T>
inline Node<T>* Graph<T>::getNode(int index)
{
	return nodes[index];
}



template<typename T>
inline int Graph<T>::size() const
{
	return nodes.size();
}

template<typename T>
inline Node<T>* Graph<T>::addNode(T val){
	Node<T>* node = new Node<T>(val);
	nodes.push_back(node);
	return node;
}

template<typename T>
inline void Graph<T>::deleteNode(Node<T>* node){
	for (unsigned int i = 0; i < nodes.size();i++) {
		if (nodes[i] == node) {
			nodes.erase(nodes.begin() + i);
			break;
		}
	}
	delete node;
}

template<typename T>
inline void Graph<T>::addEdge(Node<T>* n1, Node<T>* n2, int w){
	Edge<T>* edge = new Edge<T>(n1, n2, w);
	n1->addEdge(edge);
}

template<typename T>
inline void Graph<T>::addEdge(Node<T>* n1, Node<T>* n2, int w, bool bD){
	Edge<T>* edge = new Edge<T>(n1, n2, w,bD);
	n1->addEdge(edge);
	if (bD) n2->addEdge(edge);
}

template<typename T>
inline void Graph<T>::removeEdge(Node<T>* n1, Node<T>* n2){
	for (int i = 0; i < n1->amountOfEdges(); i++) {
		Edge<T>* edge = n1->edgeAtIndex(i);
		if (edge->getOtherNode(n1) == n2) {
			delete edge;
			return;
			
		}
			
	}
	error("Edge could not be found");
}

template<typename T>
inline Node<T>* Graph<T>::operator[](int index)
{
	return nodes[index];
}



template<typename T>
inline Graph<T>* Graph<T>::prims()
{
	Graph<T>* spanningTree = new Graph<T>;
	Node<T>* current = nodes[0];
	//Node<T>* root = new Node<T>(current->getValue());
	vector<Edge<T>*> possibleEdges;
	vector<Node<T>*> nodesCopied;
	spanningTree->addNode(current->getValue());
	nodesCopied.push_back(current);
	int treeSize = bFSearchSize(current);
	int edges = 0;

	while (edges < treeSize - 1) {
		for (int i = 0; i < current->amountOfEdges(); i++) {
			Edge<T>* curEdge = current->edgeAtIndex(i);
			if (!inVector(curEdge, possibleEdges)&&!nodeInVec(curEdge->getOtherNode(current),spanningTree->getNodes())) 
				possibleEdges.push_back(curEdge);
		}
		/*cout << "Possible Edges: " << endl;
		for (unsigned int i = 0; i < possibleEdges.size(); i++) {
			cout << possibleEdges[i] << endl;
		}*/
		//cout << endl;
		Edge<T>* minCostEdge = findMinCostEdge(possibleEdges, nodesCopied,spanningTree->getNodes());
		Node<T>* nodeOnThisEnd = findNodeInGraph(minCostEdge, nodesCopied);
		current = minCostEdge->getOtherNode(nodeOnThisEnd);
		//Node<T>* newNode = new Node<T>(current->getValue());
		Node<T>* newNode = spanningTree->addNode(current->getValue());
		nodesCopied.push_back(current);
		Node<T>* nodeInSpanningTree = findNodeInSpanningTree(nodeOnThisEnd, spanningTree);
		spanningTree->addEdge(nodeInSpanningTree, newNode,minCostEdge->getCost(),minCostEdge->isBidirectional());
		edges++;
		removeValFromVec(minCostEdge, possibleEdges);
		removeInvalidEdgesPrim(possibleEdges, spanningTree->getNodes());
		
		//cout << "Current Spanning Tree:"<< endl << spanningTree << "\n\n";
		
	}
	

	return spanningTree;
}

template<typename T>
inline void Graph<T>::bFSearchSize(Node<T>* current, vector<Node<T>*>& visited, queue<Node<T>*>& toVisit)
{
	if (!inVector(current, visited)) {
		visited.push_back(current);
		for (int i = 0; i < current->amountOfEdges(); i++) {
			Edge<T>* edge = current->edgeAtIndex(i);
			Node<T>* otherNode = edge->getOtherNode(current);
			if (!inVector(otherNode, visited)) {
				toVisit.push(otherNode);
			}
		}
	}
	if (!toVisit.empty()) {
		Node<T>* front = toVisit.front();
		toVisit.pop();
		bFSearchSize(front, visited, toVisit);
	}
}



template<typename T>
inline Edge<T>* Graph<T>::findMinCostEdge(vector<Edge<T>*>& edges, vector<Node<T>*>& copiedNodes,vector<Node<T>*>& spanningTreeNodes){
	Edge<T>* minCost = edges[0];
	for (Edge<T>* edge : edges) {
		Node<T>* nodeInTree = nullptr;
		for (Node<T>* node : spanningTreeNodes) {
			if (edge->getStart()->getValue() == node->getValue()) {
				nodeInTree = node;
				break;
			}
			if (edge->getDestination()->getValue() == node->getValue()) {
				nodeInTree = node;
				break;
			}
			
		}
		if (nodeInTree == nullptr)error("error when finding minCostEdge");
		if (edge->getCost() < minCost->getCost() && !inVector(edge->getOtherNode(nodeInTree),copiedNodes)) {
			minCost = edge;
		}
	}
	return minCost;
}

template<typename T>
inline Node<T>* Graph<T>::findNodeInGraph(Edge<T>* edge, vector<Node<T>*>& nodes){
	for (Node<T>* node : nodes) {
		if (edge->getStart() == node)return node;
		if (edge->getDestination() == node) return node;
	}
	return nullptr;
}

template<typename T>
inline Node<T>* Graph<T>::findNodeInSpanningTree(Node<T>* original, Graph<T>* spanningTree)
{
	for (Node<T>* node : spanningTree->getNodes()) {
		if (node->getValue() == original->getValue())
			return node;
	}
	return nullptr;
}

template<typename T>
inline bool Graph<T>::nodeInVec(Node<T>* node, vector<Node<T>*>& vec)
{
	for (Node<T>* n : vec) {
		if (n->getValue() == node->getValue())return true;
	}
	return false;
}

template<typename T>
inline void Graph<T>::removeInvalidEdgesPrim(vector<Edge<T>*>& edges, vector<Node<T>*>& nodes){
	bool done = false;
	while (!done) {
		done = true;
		for (unsigned int i = 0; i < edges.size(); i++) {
			Node<T>* start = edges[i]->getStart();
			Node<T>* destination = edges[i]->getDestination();
			if (nodeInVec(start, nodes) && nodeInVec(destination, nodes)) {
				edges.erase(edges.begin() + i);
				done = false;
				break;
			}
		}
	}
}

template<typename T>
inline int Graph<T>::bFSearchSize(Node<T>* start){
	queue<Node<T>*> toVisit;
	vector<Node<T>*> visited;
	bFSearchSize(start,visited,toVisit);
	return visited.size();
}


template <typename T>
ostream& operator<<(ostream& os, Graph<T>* graph) {
	for (Node<T>* node : graph->getNodes()) {
		os << node;
	}
	return os;
}


template<typename S>
bool inVector(S* targetPointer, vector<S*>& vec) {
	for (S* pointer : vec) {
		if (pointer == targetPointer)return true;
	}
	return false;
}

template<typename S>
void removeValFromVec(S* val, vector<S*>& vec) {
	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec[i] == val) {
			vec.erase(vec.begin() + i);
			break;
		}
	}
}