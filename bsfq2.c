#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_COMPUTERS 100

// Queue data structure for BFS traversal
typedef struct {
    int items[MAX_COMPUTERS];
    int front;
    int rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to add an item to the rear of the queue
void enqueue(Queue* queue, int item) {
    if (queue->rear == MAX_COMPUTERS - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

// Function to remove an item from the front of the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

// Function to perform BFS to find the shortest path
void bfs(int graph[MAX_COMPUTERS][MAX_COMPUTERS], int numComputers, int source, int destination) {
    bool visited[MAX_COMPUTERS] = {false}; // Array to track visited computers
    int parent[MAX_COMPUTERS]; // Array to store the parent of each computer in the path
    for (int i = 0; i < MAX_COMPUTERS; i++) {
        parent[i] = -1; // Initialize parent array to -1
    }

    Queue* queue = createQueue();
    visited[source] = true;
    enqueue(queue, source);

    while (!isEmpty(queue)) {
        int currentComputer = dequeue(queue);

        // Check if the current computer is the destination
        if (currentComputer == destination) {
            break;
        }

        for (int i = 1; i <= numComputers; i++) {
            if (graph[currentComputer][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = currentComputer;
                enqueue(queue, i);
            }
        }
    }

    if (!visited[destination]) {
        printf("No path exists between the source and destination computers\n");
    } else {
        printf("Shortest path from computer %d to computer %d: ", source, destination);
        int path[MAX_COMPUTERS];
        int pathLength = 0;
        int computer = destination;
        while (computer != -1) {
            path[pathLength++] = computer;
            computer = parent[computer];
        }
        for (int i = pathLength - 1; i >= 0; i--) {
            printf("%d", path[i]);
            if (i != 0) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}

int main() {
    int numComputers;
    int graph[MAX_COMPUTERS][MAX_COMPUTERS];
    int source, destination;

    printf("Enter the number of computers: ");
    scanf("%d", &numComputers);

    // Initialize the graph
    for (int i = 1; i <= numComputers; i++) {
        for (int j = 1; j <= numComputers; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the connections between computers (enter -1 -1 to stop):\n");
    while (true) {
        int computer1, computer2;
        scanf("%d %d", &computer1, &computer2);
        if (computer1 == -1 && computer2 == -1) {
            break;
        }
        if (computer1 < 1 || computer1 > numComputers || computer2 < 1 || computer2 > numComputers) {
            printf("Invalid input. Please enter valid computer numbers.\n");
            continue;
        }
        graph[computer1][computer2] = 1;
        graph[computer2][computer1] = 1;
    }

    printf("Enter the source computer: ");
    scanf("%d", &source);
    printf("Enter the destination computer: ");
    scanf("%d", &destination);

    bfs(graph, numComputers, source, destination);

    return 0;
}
