#include "Graph.h"

Graph::Graph(int size)
{
	this->size = size;
	arr = new bool* [size];
	for (int i = 0; i < size;i++) {
		arr[i] = new bool[1+i];
		for (int n = 0; n < 1+i; n++) {
			arr[i][n] = false;
		}
	}

}

Graph::~Graph()
{
	for (int i = 0; i < size; i++) {
		delete[]arr[i];
	}
	delete[] arr;
}

void Graph::addEdge(int a, int b)
{
	if (a < 0 || b < 0 || a >= size||b>= size || a == b)error("Invalid edge");
	if (a < b)
		arr[a][b-a-1] = true;
	else
		arr[b][a-b-1] = true;
}

void Graph::removeEdge(int a, int b) {
	if (a < 0 || b < 0 || a >= size || b >= size || a == b)error("Invalid edge");
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

