#include <iostream> 
using namespace std; 
void addEdge(string cities[], bool visited[], bool added[], const string& source, 
const string& destination, int& count) 
{ 
 cities[count++] = source; 
 cities[count++] = destination; 
 visited[count / 2 - 1] = true; 
 visited[count / 2] = true; 
 added[count - 2] = true; 
 added[count - 1] = true; 
} 
bool isConnected(string cities[], const bool visited[], const bool added[], int 
count) 
{ 
 if (count == 0) 
 return true; 
 bool currentVisited[count / 2]; 
 for (int i = 0; i < count / 2; ++i) 
 currentVisited[i] = visited[i]; 
 string start = cities[0]; 
 int front = 0; 
 int rear = 1; 
 while (front < rear) 
 { 
 string current = cities[front]; 
 for (int i = 0; i < count; i += 2) 
 { 
 if (added[i] && added[i + 1]) 
 { 
 if (current == cities[i] && currentVisited[i / 2]) 
 { 
 currentVisited[i / 2] = false; 
 cities[rear++] = cities[i + 1]; 
 } 
 else if (current == cities[i + 1] && currentVisited[i / 2]) 
 { 
 currentVisited[i / 2] = false; 
 cities[rear++] = cities[i]; 
 } 
 } 
 } 
 ++front; 
 } 
 for (int i = 0; i < count / 2; ++i) 
 { 
 if (currentVisited[i]) 
 return false; 
 } 
 return true; 
} 
int main() 
{ 
 const int MAX_CITIES = 100; 
 string cities[MAX_CITIES]; 
 bool visited[MAX_CITIES / 2] = { false }; 
 bool added[MAX_CITIES] = { false }; 
 int count = 0; 
 int n; 
 cout << "Enter the number of edges: "; 
 cin >> n; 
 string source, destination; 
 for (int i = 1; i <= n; ++i) 
 { 
 cout << "Enter the start and end node of edge " << i << ": "; 
 cin >> source >> destination; 
 addEdge(cities, visited, added, source, destination, count); 
 } 
 if (isConnected(cities, visited, added, count)) 
 cout << "The flight graph is connected." << endl; 
 else 
 cout << "The flight graph is not connected." << endl; 
 return 0; 
} 
