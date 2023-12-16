#include "graph.h"

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // 添加边到源结点
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // 由于是无向图，所以也要添加从目标结点到源结点的边
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        struct Node* temp = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    struct Node* temp = graph->adjacencyList[vertex];
    while (temp) {
        if (!visited[temp->data]) {
            DFS(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

void DFSTraversal(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
    }

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex, visited);

    free(visited);
}

void BFS(struct Graph* graph, int startVertex) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = false;
    }

    int queue[graph->vertices];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    printf("%d ", startVertex);
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        struct Node* temp = graph->adjacencyList[currentVertex];
        
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                printf("%d ", adjVertex);
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
}