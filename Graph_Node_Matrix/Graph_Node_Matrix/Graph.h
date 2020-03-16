#pragma once
#include "..\..\std_lib_facilities.h"

class Graph
{
	bool** arr;
	int size;
public:
	Graph(int size);
	~Graph();
	void addEdge(int a, int b);
	void removeEdge(int a, int b);
	void print();
};

