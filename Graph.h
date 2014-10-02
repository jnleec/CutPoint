#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

#define UNVISITED 0

class Graph 
{
	private:
		int numVertex;
		int **matrix; 
		int *mark;
		int *low;

	public:
		Graph(int numVert) 
		{
			int i, j;
			numVertex = numVert;

			mark = new int[numVert];
			for(i = 0; i < numVertex; i++) 
			{
				mark[i] = UNVISITED;
			}

			low = new int[numVert];
			for(i = 0; i < numVertex; i++) 
			{
				low[i] = 0;
			}

			matrix = (int**) new int*[numVertex];
			for(i = 0; i < numVertex; i++) 
			{
				matrix[i] = new int[numVertex];
			}
			for(i = 0; i < numVertex; i++) 
			{
				for(j = 0; j < numVertex; j++) 
				{
					matrix[i][j] = 0;
				}
			}
		}

		~Graph() 
		{
			delete []mark;
			for(int i = 0; i < numVertex; i++) 
			{
				delete []matrix[i];
			}
			delete []matrix;
		}

		int n() 
		{
			return numVertex;
		}

		int first(int v) 
		{
			int i;
			for(i = 0; i < numVertex; i++) 
			{
				if(matrix[v][i] != 0) 
				{
					return i;
				}
			}
			return i;
		}

		int next(int v1, int v2) 
		{
			int i;
			for(i = v2 + 1; i < numVertex; i++) 
			{
				if(matrix[v1][i] != 0) 
				{
					return i;
				}
			}
			return i;
		}

		void setEdge(int v1, int v2) 
		{
			matrix[v1][v2] = 1;
		}

		int isHasEdge(int v1, int v2) 
		{
			return matrix[v1][v2];
		}

		int getMark(int v) 
		{
			return mark[v];
		}

		void setMark(int v, int val) 
		{
			mark[v] = val;
		}

		int getLow(int v) 
		{
			return low[v];
		}

		void setLow(int v, int val) 
		{
			low[v] = val;
		}
};

#endif