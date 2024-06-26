
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>


int minKey(int key[], bool mstSet[])
{
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < 5; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

int printMST(int parent[], int graph[5][5])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < 5; i++)
		printf("%d - %d \t%d \n", parent[i], i,
			graph[i][parent[i]]);
}

void primMST(int graph[5][5])
{
	
	int parent[5];
	int key[5];
	bool mstSet[5];

	for (int i = 0; i < 5; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;

	parent[0] = -1;

	for (int count = 0; count < 4; count++) {
		
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < 5; v++)

			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
	int graph[5][5] = { { 0, 10, 20, 0, 0 },
                    { 10, 0, 30, 5, 0 },
                    { 20, 30, 0, 15, 6 },
                    { 0, 5, 15, 0, 8 },
                    { 0, 0, 6, 8, 0 } };

	primMST(graph);

	return 0;
}
