#ifndef AUCOMPUTERSCIENCETEST_GRAPH_H
#define AUCOMPUTERSCIENCETEST_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 邻接表的结点
struct Node {
    int data;
    struct Node* next;
};

// 图的结构
struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

// 创建新结点
struct Node* createNode(int data);

// 创建图
struct Graph* createGraph(int vertices);

// 添加边
void addEdge(struct Graph* graph, int src, int dest);

// 打印图
void printGraph(struct Graph* graph);

// 深度优先搜索
void DFS(struct Graph* graph, int vertex, bool visited[]);

// DFS的入口函数
void DFSTraversal(struct Graph* graph, int startVertex);

// 广度优先搜索
void BFS(struct Graph* graph, int startVertex);

#endif