#pragma once
#include "..\..\std_lib_facilities.h"
#include <queue>
class Graph
{
	bool** arr;
	int size;
	bool dfSearch(int current,const int& target,vector<int>& visited);
	bool inVector(int val, vector<int>& vec);
	bool bfSearch(int current,const int& target, vector<int>& visited,queue<int>& toVisit);
public:
	Graph(int size);
	~Graph();
	void addEdge(int a, int b);
	void removeEdge(int a, int b);
	void print();
	bool dfSearch(int start, const int& target);
	bool bfSearch(int start, const int& target);
};

