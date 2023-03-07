#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// void	dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int current_vertex, int num_vertices)
void	dfs(int **graph, int *visited, int current_vertex, int num_vertices)
{
	visited[current_vertex] = 1;
	printf("%d ", current_vertex);

	for (int i=0; i<num_vertices; i++)
	{
		if (graph[current_vertex][i] == 1 && visited[i] == 0)
			dfs(graph, visited, i, num_vertices);
	}
}

int	main()
{
	int	**graph;
	int	*visited;
	int	num_vertices;
	int	start_vertex;
	int	i;

	graph = malloc(sizeof(int *) * MAX_VERTICES);
	i = 0;
	while (i < MAX_VERTICES)
	{
		graph[i] = malloc(sizeof(int) * MAX_VERTICES);
		i++;
	}
	visited = malloc(sizeof(int) * MAX_VERTICES);

	printf("Enter the number of vertices: ");
	scanf("%d", &num_vertices);

	printf("Enter the adjacency matrix:\n");
	for (int i = 0; i < num_vertices; i++) {
		for (int j = 0; j < num_vertices; j++) {
			scanf("%d", &graph[i][j]);
		}
	}

	printf("Enter the starting vertex: ");
	scanf("%d", &start_vertex);

	for (int i = 0; i < num_vertices; i++) {
		visited[i] = 0;
	}


	printf("DFS traversal: ");
	dfs(graph, visited, start_vertex, num_vertices);

	free(visited);
	free(graph);
	return 0;
}