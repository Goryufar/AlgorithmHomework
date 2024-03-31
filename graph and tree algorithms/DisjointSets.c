#include <stdio.h>
#include <stdlib.h>

int parent[1000000];

int root(int a)
{

	if (a == parent[a]) {
		return a;
	}

	return parent[a] = root(parent[a]);
}


void connect(int a, int b)
{

	a = root(a);
	b = root(b);

	if (a != b) {
		parent[b] = a;
	}
}

void connectedComponents(int n)
{
	int s[n];

	for (int i = 0; i < n; i++) {
		s[i] = root(parent[i]);
	}
	int uniqueCount = 0;
	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < i; j++) {
			if (s[i] == s[j])
				break;
		}
		if (i == j)
			uniqueCount++;
	}

	printf("%d\n", uniqueCount);
}

void printAnswer(int N, int edges[][2], int M)
{

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		connect(edges[i][0], edges[i][1]);
	}

	connectedComponents(N);
}

int main()
{

	int N = 8;
	int edges[][2] = {
		{ 1, 0 }, { 0, 2 }, { 5, 3 }, { 3, 4 }, { 6, 7 }
	};

	int M = sizeof(edges) / sizeof(edges[0]);
	printAnswer(N, edges, M);

	return 0;
}
