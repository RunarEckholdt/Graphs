#include "Graph.h"

Graph::Graph(int size)
{
	this->size = size;
	arr = new bool* [size-1];
	for (int i = 0; i < size-1;i++) {
		arr[i] = new bool[size-1-i];
		for (int n = 0; n < size-1-i; n++) {
			arr[i][n] = false;
		}
	}

}

Graph::~Graph()
{
	for (int i = 0; i < size-1; i++) {
		delete[]arr[i];
	}
	delete[] arr;
}

void Graph::addEdge(int a, int b)
{
	if (a < 0 || b < 0 || a > size||b > size || a == b)error("Invalid edge");
	if (a < b)
		arr[a][b-a-1] = true;
	else
		arr[b][a-b-1] = true;
}

void Graph::removeEdge(int a, int b) {
	if (a < 0 || b < 0 || a > size || b > size || a == b)error("Invalid edge");
	if (a < b)
		arr[a][b-a-1] = false;
	else
		arr[b][a-b-1] = false;
}

void Graph::print(){
	for (int a = 0; a < size; a++) {
		cout << a << "-> ";
		for (int b = 0; b < size; b++) {
			if (a != b){
				if (a < b) {
					if (arr[a][b - a - 1] == true) {
						cout << b << " ";
					}
				}
				else
				{
					if (arr[b][a - b - 1] == true) {
						cout << b << " ";
					}
				}
			}
			
		}
		cout << endl;
	}
}

bool Graph::inVector(int val, vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == val)return true;
	}
	return false;
}



bool Graph::dfSearch(int current,const int& target, vector<int>& visited) {
	if (current == target) return true;
	visited.push_back(current);
	for (int i = 0; i < size; i++) {
		if (current < i) {
			if (arr[current][i - current - 1] && !inVector(i,visited)) {
				bool reply = dfSearch(i, target,visited);
				if (reply)return reply;
			}
		}
			
		else {
			if (arr[i][current - i - 1] && !inVector(i, visited)) {
				bool reply = dfSearch(i, target, visited);
				if (reply)return reply;
			}
		}
	}
	return false;

}

bool Graph::dfSearch(int start,const int& target) {
	vector<int> visited;
	return dfSearch(start, target, visited);
}


bool Graph::bfSearch(int current, const int& target, vector<int>& visited, queue<int>& toVisit)
{
	if (current == target)return true;
	visited.push_back(current);
	for (int i = 0; i < size; i++) {
		if (current < i) {
			if (arr[current][i - current - 1] && !inVector(i, visited)) {
				toVisit.push(i);
			}
		}

		else {
			if (arr[i][current - i - 1] && !inVector(i, visited)) {
				toVisit.push(i);
			}
		}
	}
	if (!toVisit.empty()) {
		int front = toVisit.front();
		toVisit.pop();
		if (bfSearch(front, target, visited, toVisit))return true;
	}
	return false;
}

bool Graph::bfSearch(int start, const int& target)
{
	queue<int> toVisit;
	vector<int> visited;
	return bfSearch(start, target, visited, toVisit);
}
