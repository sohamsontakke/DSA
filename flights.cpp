#include <iostream>
#include <string>
using namespace std;

struct Node {
    string vertex;
    int time;
    Node* next;
};

void getGraph(string v[], int m[][10], int n) {
    cout << "\nEnter name of cities:\n";
    for (int i = 0; i < n; i++)
        cin >> v[i];

    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "\nIs there a path present between city " << v[i] << " and " << v[j] << " (y/n): ";
                cin >> ch;
                if (ch == 'y') {
                    cout << "Enter time required to reach city " << v[j] << " from " << v[i] << " in minutes: ";
                    int z;
                    cin >>m[i][j];
                    
                } else {
                    m[i][j] = 0;
                    m[j][i] = 0;
                }
            } else {
                m[i][j] = 0;
            }
        }
    }
}

void createAdjList(Node* head[], string v[], int m[][10], int n) {
    for (int i = 0; i < n; i++) {
        Node* p = new Node;
        p->next = NULL;
        p->vertex = v[i];
        head[i] = p;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != 0) {
                Node* p = new Node;
                p->vertex = v[j];
                p->time = m[i][j];
                p->next = NULL;
                if (head[i]->next == NULL) {
                    head[i]->next = p;
                } else {
                    Node* temp = head[i]->next;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = p;
                }
            }
        }
    }
}

void displayAdjList(Node* head[], string v[], int n) {
    cout << "\nAdjacency list is:\n";
    for (int i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "Adjacency list not present\n";
            break;
        } else {
            cout << head[i]->vertex;
            Node* temp = head[i]->next;
            while (temp != NULL) {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    cout << "\nPath and time required to reach cities:\n";
    for (int i = 0; i < n; i++) {
        if (head[i] == NULL) {
            cout << "Adjacency list not present\n";
            break;
        } else {
            Node* temp = head[i]->next;
            while (temp != NULL) {
                cout << head[i]->vertex << " -> " << temp->vertex << "\n   [Time required: " << temp->time << " min]\n";
                temp = temp->next;
            }
        }
    }
}

bool isConnected(Node* head[], int n)
{
    bool visited[n] = { false };
    string cities[n];

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (head[i] != NULL)
        {
            visited[i] = true;
            cities[count++] = head[i]->vertex;
        }
    }

    if (count == 0)
        return true;

    int front = 0;
    int rear = 1;
    while (front < rear)
    {
        string current = cities[front];
        for (int i = 0; i < n; i++)
        {
            if (head[i] != NULL)
            {
                Node* temp = head[i]->next;
                while (temp != NULL)
                {
                    if (current == head[i]->vertex && visited[i])
                    {
                        visited[i] = false;
                        cities[rear++] = temp->vertex;
                    }
                    else if (current == temp->vertex && visited[i])
                    {
                        visited[i] = false;
                        cities[rear++] = head[i]->vertex;
                    }
                    temp = temp->next;
                }
            }
        }
        ++front;
    }

    for (int i = 0; i < n; ++i)
    {
        if (visited[i])
            return false;
    }

    return true;
}


int main() {
    int m;
    const int MAX_CITIES = 20;
    string v[MAX_CITIES];
    int mat[MAX_CITIES][10] = { 0 };
    Node* head[MAX_CITIES] = { NULL };
    int n = 0;

    while (true) {
        cout << "\n****MAIN MENU****\n";
        cout << "1. Enter graph\n";
        cout << "2. Display adjacency list for cities\n";
        cout << "3. Check if the graph is connected\n";
        cout << "4. Exit\n";
        cout << "Enter your choice:\n";
        cin >> m;

        switch (m) {
            case 1:
                cout << "\nEnter the number of cities (max. 20): ";
                cin >> n;
                if (n > MAX_CITIES) {
                    cout << "Exceeded the maximum number of cities.\n";
                    break;
                }
                getGraph(v, mat, n);
                createAdjList(head, v, mat, n);
                break;

            case 2:
                displayAdjList(head, v, n);
                break;

            case 3:
                if (n > 0) {
                    if (isConnected(head, n))
                        cout << "The graph is a connected graph.\n";
                    else
                        cout << "The graph is not a connected graph.\n";
                } else {
                    cout << "No graph entered yet. Please enter a graph first.\n";
                }
                break;

            case 4:
                exit(0);

            default:
                cout << "\nUnknown choice\n";
        }
    }

    return 0;
}

