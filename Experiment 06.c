// Write a C program to implement Kruskal’s algorithm for finding the Minimum Cost Spanning Tree (MCST) and the total minimum cost of travel for a given undirected graph. The graph will be represented by an adjacency matrix.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int find(int parent[], int i) {
	if (parent[i] != i)
		parent[i]  = find(parent, parent[i]);
	return parent[i];
}

void union1(int parent[], int rank[], int i, int j) {
	int root_i = find(parent, i);
	int root_j = find(parent, j);
	if (rank[root_i] < rank[root_j]) {
		parent[root_i] = root_j;
	} else if (rank[root_i] > rank[root_j]) {
		parent[root_j] = root_i;
	} else {
		parent[root_j] = root_i;
		rank[root_i]++;
	}
}

void kruskalMST(int **cost, int V) {
	int parent[V], rank[V];
	for (int i = 0; i < V; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	int edges[V * V][3];
	int k = 0;
	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			if (cost[i][j] != 9999) {
				edges[k][0] = i;
				edges[k][1] = j;
				edges[k][2] = cost[i][j];
				k++;
			}
		}
	}
	for (int i = 0; i < k - 1; i++) {
		for (int j = 0; j < k - i - 1; j++) {
			if (edges[j][2] > edges[j + 1][2]) {
				int temp0 = edges[j][0];
				int temp1 = edges[j][1];
				int temp2 = edges[j][2];
				edges[j][0] = edges[j + 1][0];
				edges[j][1] = edges[j + 1][1];
				edges[j][2] = edges[j + 1][2];
				edges[j + 1][0] = temp0;
				edges[j + 1][1] = temp1;
				edges[j + 1][2] = temp2;
			}
		}
	}
	int count = 0, i = 0, minCost = 0;
	while (count < V - 1 && i < k) {
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		int set_u = find(parent, u);
		int set_v = find(parent, v);
		if (set_u != set_v) {
			printf("Edge %d:(%d, %d) cost:%d\n", count, u, v, w);
			minCost += w;
			union1(parent, rank, set_u, set_v);
			count++;
		}
		i++;
	}
	printf("Minimum cost= %d\n", minCost);
}

int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
