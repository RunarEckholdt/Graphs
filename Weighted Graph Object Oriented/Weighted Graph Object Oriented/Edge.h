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
	int weight;
public:
	Edge(Node<T>* start, Node<T>* destination, int weight);
	Edge(Node<T>* start, Node<T>* destination, int weight, bool isBiDirectional);
	Node<T>* getOtherNode(Node<T>* node);
	~Edge();
};


template <typename T>
inline Edge<T>::Edge(Node<T>* s, Node<T>* d, int w)
	:start(s), destination(d), weight(w), biDirectional(false)
{}

template <typename T>
inline Edge<T>::Edge(Node<T>* s, Node<T>* d, int w, bool biDirect)
	: start(s), destination(d), weight(w), biDirectional(biDirect)
{}

template<typename T>
inline Node<T>* Edge<T>::getOtherNode(Node<T> * node)
{
	if (start == node)return destination;
	else return start;
}

template<typename T>
inline Edge<T>::~Edge(){
	start->removeEdge(this);
	destination->removeEdge(this);
}

#endif