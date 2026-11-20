/*Name:Pawan chondhe
Roll No:CO2022
class:SE-A-1
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_USERS 100
struct Node {
int user_id;
struct Node* next;
};

struct Graph {
int numUsers;
struct Node** adjLists;
int* visited;
};

struct Node* createNode(int v) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->user_id = v;
newNode->next = NULL;
return newNode;
}
struct Graph* createGraph(int users) {
struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
graph->numUsers = users;
graph->adjLists = (struct Node**)malloc(users * sizeof(struct Node*));
graph->visited = (int*)malloc(users * sizeof(int));
for (int i = 0; i < users; i++) {
graph->adjLists[i] = NULL;
graph->visited[i] = 0;
}
return graph;
}
void addConnection(struct Graph* graph, int u, int v) {
if (u >= graph->numUsers || v >= graph->numUsers || u < 0 || v < 0) {
printf("Invalid user IDs.\n");
return;
}
struct Node* newNode = createNode(v);
newNode->next = graph->adjLists[u];
graph->adjLists[u] = newNode;
newNode = createNode(u);
newNode->next = graph->adjLists[v];
graph->adjLists[v] = newNode;
printf("Connection added between User %d and User %d.\n", u, v);
}
void resetVisited(struct Graph* graph) {
for (int i = 0; i < graph->numUsers; i++) {
graph->visited[i] = 0;
}
}
void BFS(struct Graph* graph, int startVertex) {
int queue[MAX_USERS];
int front = 0, rear = 0;
resetVisited(graph);
graph->visited[startVertex] = 1;
queue[rear++] = startVertex;
printf("BFS Traversal: ");
while (front < rear) {
int currentUser = queue[front++];
printf("%d ", currentUser);
struct Node* temp = graph->adjLists[currentUser];
while (temp) {
int adjUser = temp->user_id;
if (graph->visited[adjUser] == 0) {
graph->visited[adjUser] = 1;
queue[rear++] = adjUser;
}
temp = temp->next;
}
}
printf("\n");
}
void DFS_recursive(struct Graph* graph, int vertex) {
struct Node* temp = graph->adjLists[vertex];
graph->visited[vertex] = 1;
printf("%d ", vertex);
while (temp != NULL) {
int connectedUser = temp->user_id;
if (graph->visited[connectedUser] == 0) {
DFS_recursive(graph, connectedUser);
}
temp = temp->next;
}
}
void DFS(struct Graph* graph, int startVertex) {
resetVisited(graph);
printf("DFS Traversal: ");
DFS_recursive(graph, startVertex);
printf("\n");
}
int main() {
int users, choice, u, v, startNode;
printf("Enter total number of users in the social network: ");
scanf("%d", &users);
struct Graph* graph = createGraph(users);
while (1) {
printf("\n--- Social Network Connectivity ---\n");
printf("1. Add connection between users\n");
printf("2. Perform Breadth First Search (BFS)\n");
printf("3. Perform Depth First Search (DFS)\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter User 1 ID (0 to %d): ", users - 1);
scanf("%d", &u);
printf("Enter User 2 ID (0 to %d): ", users - 1);
scanf("%d", &v);
addConnection(graph, u, v);
break;
case 2:
printf("Enter starting user ID for BFS: ");
scanf("%d", &startNode);
if (startNode >= 0 && startNode < users) {
BFS(graph, startNode);
} else {
printf("Invalid user ID.\n");
}
break;
case 3:
printf("Enter starting user ID for DFS: ");
scanf("%d", &startNode);
if (startNode >= 0 && startNode < users) {
DFS(graph, startNode);
} else {
printf("Invalid user ID.\n");
}
break;
case 4:
printf("Exiting program.\n");
exit(0);
default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}
