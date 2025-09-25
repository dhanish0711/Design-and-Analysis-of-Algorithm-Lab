// Implement the Floyd-Warshall algorithm in C for finding the shortest distances between all pairs of vertices in a weighted directed graph. Prompt the user to input the number of vertices (N) and edges (E), and then accept edge information (source, destination, and weight) to build the adjacency matrix.

#include <stdio.h>
#define INF 99999
#define MAX_N 20 // Maximum value for N

void printSolution(int N, int dist[MAX_N][MAX_N]);
void floydWarshall(int N, int graph[MAX_N][MAX_N]);

void floydWarshall(int N, int graph[MAX_N][MAX_N]) {
	int dist[MAX_N][MAX_N];
	int i, j, k;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) 
				dist[i][j] = 0;
			else
				dist[i][j] = graph[i][j];
		}
	}
	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	printSolution(N, dist);
}

void printSolution(int N, int dist[MAX_N][MAX_N]) {
	printf("The following matrix shows the shortest distances between all pairs of the vertices.\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF)
				printf("%5s", "INF");
			else 
				printf("%5d", dist[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int N, E;
	printf("Enter the number of vertices : ");
	scanf("%d", &N);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	int graph[MAX_N][MAX_N];
	for(int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = INF;
		}
	}
	for (int i = 1; i <= E; i++) {
		int s, d, w;
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if (s > N || d > N || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	floydWarshall(N, graph);
	return 0;
}
