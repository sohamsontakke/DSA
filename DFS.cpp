#include <iostream> 
#define MAX_NODES 100 
using namespace std; 
int adj[MAX_NODES][MAX_NODES]; 
void addEdge(int u, int v) 
{ 
 adj[u][v] = 1; 
 adj[v][u] = 1; 
} 
void DFS(int start, bool visited[], int V) 
{ 
 visited[start] = true; 
 cout << start << " "; 
 for (int i = 1; i <= V; i++) 
 { 
 if (adj[start][i] && !visited[i]) 
 DFS(i, visited, V); 
 } 
} 
int main() 
{ 
 int n, e, strt, fnsh, st; 
 cout << "Enter no. of nodes: "; 
 cin >> n; 
 cout << "Enter no. of edges: "; 
 cin >> e; 
 for (int i = 1; i <= e; i++) 
 { 
 cout << "Enter the start and end node of edge " << i << ": "; 
 cin >> strt >> fnsh; 
 addEdge(strt, fnsh); 
 } 
 bool visited[MAX_NODES] = {false}; 
 cout << "Enter the starting node for the traversal: "; 
 cin >> st; 
 cout << "DFS using adjacency matrix: "; 
 DFS(st, visited, n); 
 cout << endl; 
 return 0; 
} 
