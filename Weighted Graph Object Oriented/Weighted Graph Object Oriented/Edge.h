#pragma once
#ifndef _EDGE
#define _EDGE
#include "Node.h"
#include "..\..\std_lib_facilities.h"

template <typename T>
class Node;

template <typename T>
class Edge
{
	bool biDirectional;
	Node<T>* start;
	Node<T>* destination;
	int cost;
public:
	Edge(Node<T>* start, Node<T>* destination, int cost);
	Edge(Node<T>* start, Node<T>* destination, int cost, bool isBiDirectional);
	Node<T>* getOtherNode(Node<T>* node);
	int getCost();
	bool isBidirectional();
	~Edge();
	Node<T>* getStart()const;
	Node<T>* getDestination()const;
	
};


template <typename T>
inline Edge<T>::Edge(Node<T>* s, Node<T>* d, int c)
	:start(s), destination(d), cost(c), biDirectional(false)
{}

template <typename T>
inline Edge<T>::Edge(Node<T>* s, Node<T>* d, int c, bool biDirect)
	: start(s), destination(d), cost(c), biDirectional(biDirect)
{}

template<typename T>
inline Edge<T>::~Edge() {
	start->removeEdge(this);
	if(this->isBidirectional())
		destination->removeEdge(this);
}

template<typename T>
inline Node<T>* Edge<T>::getStart() const{return start;}

template<typename T>
inline Node<T>* Edge<T>::getDestination() const{return destination;}

template<typename T>
inline Node<T>* Edge<T>::getOtherNode(Node<T> * node)
{
	if (start->getValue() == node->getValue())return destination;
	else return start;
}

template<typename T>
inline int Edge<T>::getCost(){return cost;}

template<typename T>
inline bool Edge<T>::isBidirectional(){return biDirectional;}

template<typename T>
ostream& operator<<(ostream& os, Edge<T>* edge) {
	return os << edge->getStart()->getValue() << " : " << edge->getDestination()->getValue()
		<< " Cost: " << edge->getCost() << "| ";
}



#endif