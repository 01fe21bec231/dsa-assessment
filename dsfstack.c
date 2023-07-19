#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 8

struct Node {
  int vertex;
  struct Node* next;
};

struct Stack {
  struct Node* top;
};

struct Node* createNode(int v)
 {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Stack* createStack()
 {
  struct Stack* stack = malloc(sizeof(struct Stack));
  stack->top = NULL;
  return stack;
}

void push(struct Stack* stack, int v)
 {//vertex
  struct Node* newNode = createNode(v);
  newNode->next = stack->top;
  stack->top = newNode;
}

int pop(struct Stack* stack)
 {
  if (stack->top == NULL)
    {
    return -1; // Stack underflow
  }
  int vertex = stack->top->vertex;
  struct Node* temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return vertex;
}

int isEmpty(struct Stack* stack) {
  return stack->top == NULL;
}

struct Graph {
  int numVertices;
  struct Node** adjLists;
  int* visited;
};

struct Graph* createGraph(int vertices)
{
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct Node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct Node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int startVertex) {
  struct Stack* stack = createStack();
  push(stack, startVertex);

  while (!isEmpty(stack)) {
    int currentVertex = pop(stack);

    if (graph->visited[currentVertex] == 0) {
      graph->visited[currentVertex] = 1;
      printf("%d ", currentVertex);

      struct Node* temp = graph->adjLists[currentVertex];
      while (temp != NULL) {
        if (graph->visited[temp->vertex] == 0) {
          push(stack, temp->vertex);
        }
        temp = temp->next;
      }
    }
  }
}

int main() {
  struct Graph* graph = createGraph(MAX_VERTICES);

  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 5);
  addEdge(graph, 3, 6);
  addEdge(graph, 4, 7);
  addEdge(graph, 4, 5);
  addEdge(graph, 5, 2);

  printf("Depth First Traversal for the graph is: ");
  DFS(graph, 0);

  return 0;
}

