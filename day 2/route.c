#include <stdio.h>
#include <limits.h>
#define MAX 100

int graph[MAX][MAX];
int numStops;

void initializeGraph(int stops) {
	numStops = stops;
	for (int i = 0; i < numStops; i++) {
		for (int j = 0; j < numStops; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INT_MAX;
		}
	}
}

void addRoute(int src, int dest, int time) {
	graph[src][dest] = time;
	graph[dest][src] = time; // Assuming bidirectional roads
}

int minDistance(int dist[], int visited[]) {
	int min = INT_MAX, minIndex;
	for (int v = 0; v < numStops; v++) {
		if (!visited[v] && dist[v] <= min) {
			min = dist[v], minIndex = v;
		}
	}
	return minIndex;
}

void dijkstra(int src, int dest) {
	int dist[MAX], visited[MAX], parent[MAX];
	for (int i = 0; i < numStops; i++) {
		dist[i] = INT_MAX;
		visited[i] = 0;
		parent[i] = -1;
	}
	dist[src] = 0;

	for (int count = 0; count < numStops - 1; count++) {
		int u = minDistance(dist, visited);
		visited[u] = 1;

		for (int v = 0; v < numStops; v++) {
			if (!visited[v] && graph[u][v] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
				parent[v] = u;
			}
		}
	}

	printf("Shortest route time: %d minutes\n", dist[dest]);
	printf("Optimized route: ");
	int path[MAX], index = 0, temp = dest;
	while (temp != -1) {
		path[index++] = temp;
		temp = parent[temp];
	}
	for (int i = index - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("\n");
}

int main() {
	int stops, routes, src, dest, time;
	printf("Enter number of bus stops: ");
	scanf("%d", &stops);
	initializeGraph(stops);

	printf("Enter number of routes: ");
	scanf("%d", &routes);
	printf("Enter routes (source destination time):\n");
	for (int i = 0; i < routes; i++) {
		scanf("%d %d %d", &src, &dest, &time);
		addRoute(src, dest, time);
	}

	printf("Enter source and destination stops: ");
	scanf("%d %d", &src, &dest);
	dijkstra(src, dest);

	return 0;
}
