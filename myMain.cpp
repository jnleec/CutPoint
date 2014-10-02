#include "Graph.h"

void dfs(Graph * G, int u, int v, int num);

void main() {  
  
	int N;
    cout << "input num of vertex : ";  
    cin >> N;  
  
    Graph *graph = new Graph(N);
  
    int i,j;  
	char sign = 'n';
	
	cout << " input x and y : "<<endl;  
	while (sign != 'y') 
	{
		cin >> i >> j;
        if ( i < N && j < N && i >=0 && j >= 0 ) 
		{  
			graph->setEdge(i ,j);
			graph->setEdge(j ,i);
        } 
		else 
		{  
            cout<<"Invalid!"<<endl;  
        }  

		cout << "is it stop£¿£¨y/n£©";  
		cin >> sign;
	}
  
	dfs(graph, -1, 0,1);
	system("pause");
}  

void dfs(Graph * G, int u, int v, int num) 
{  
	G->setMark(v, num);
	G->setLow(v, num);
  
    int count = (u==-1)?0:1;  
    bool potential = false;  

	for (int w = G->first(v); w < G->n(); w = G->next(v, w)) 
	{
		if (G->isHasEdge(v, w) && w != u ) { 
			if (G->getMark(w) == UNVISITED)
			{
				dfs(G, v, w, num+1);
				if (G->getLow(w) < G->getLow(v)) 
					G->setLow(v, G->getLow(w));
				count++; 
			}
			else
			{
				if (G->getMark(w) < G->getLow(v)) 
					G->setLow(v, G->getMark(w));
			}

			if (G->getLow(w) >= G->getMark(v))  
                potential = true;  
		}
	}

	if ( potential && count>=2 )  
        cout << "cut point is : " << v << endl;
  
}   
