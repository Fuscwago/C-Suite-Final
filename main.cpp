#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Node {
public:
    int id;
    string name;
    Node* nextNode;

    Node(int id, string name) {
        this->id = id;
        this->name = name;
        this->nextNode = nullptr;
    }
    Node() {
        this->id = 0;
        this->name = "";
        this->nextNode = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        this->head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->nextNode;
            delete toDelete;
        }
    }

    // Add node to end of list
    void append(int id, string name) {
        Node* currNode = head;

        if (head == nullptr) {
            head = new Node(id, name);
            return;
        }

        while (currNode->nextNode != nullptr) {
            currNode = currNode->nextNode;
        }
        currNode->nextNode = new Node(id, name);
    }

    // Overload in case node is passed
    void append(Node* node) {
        Node* newNode = new Node(node->id, node->name);

        Node* currNode = head;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        while (currNode->nextNode != nullptr) {
            currNode = currNode->nextNode;
        }
        currNode->nextNode = newNode;
    }

    // Add node to start of list
    void push(Node* node) {
        Node* temp = head;
        head = node;
        head->nextNode = temp;
    }

    // Another overload
    void push(int id, string name) {
        Node* temp = head;
        head = new Node(id, name);
        head->nextNode = temp;
    }

    void setHead(Node* head) {
        this->head = head;
    }

    // Overload again
    void setHead(int id, string name) {
        this->head = new Node(id, name);
    }

    Node* getHead() {
        return head;
    }

    void print() {
        Node* currNode = head;

        if (currNode == nullptr) {
            cout << "List is empty";
        }

        while (currNode->nextNode != nullptr) {
            cout << currNode->name << "->";
            currNode = currNode->nextNode;
        }
        cout << currNode->name << endl;
    }
};

class AdjacencyList {
public:
    int numNodes;
    vector<LinkedList>* paths;
    vector<vector<pair<int, int>>> edges;

    AdjacencyList(int numNodes) {
        this->numNodes = numNodes;
        this->paths = new vector<LinkedList>(numNodes);
        this->edges = vector<vector<pair<int, int>>>(numNodes);
    }

    ~AdjacencyList() {
        delete paths;
    }

    void addNode(Node* node) {
        (*paths)[node->id].setHead(node);
    }

    void addEdge(Node* start, Node* end, int weight) { //in order between nodes
        (*paths)[start->id].append(end);
        edges[start->id].push_back(make_pair(end->id, weight));

        (*paths)[end->id].append(start);
        edges[end->id].push_back(make_pair(start->id, weight));
    }

    void printPath(int pathId) {
        (*paths)[pathId].print();
    }

    void printPaths() {
        for (int i = 0; i < numNodes; i++) {
            if ((*paths)[i].getHead() != nullptr) {
                (*paths)[i].print();
            }
            else {
                cout << "Path is Empty" << endl;
            }
        }
    }

    int minDistance(vector<int>& dist, vector<bool>& visited) {
        int min = INT_MAX, min_index;

        for (int v = 0; v < numNodes; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }

    void printWeights() {
        for (int i = 0; i < numNodes; i++) {
            if ((*paths)[i].getHead() != nullptr) {
                for (int j = 0; j < edges[i].size(); j++) {
                    cout << edges[i][j].second << " ";
                }
                cout << endl;
            }
            else {
                cout << "Path is Empty" << endl;
            }
        }
        cout << endl;
    }

    void findShortestPath(Node* start) {
        vector<int> dist(numNodes, INT_MAX);
        vector<bool> visited(numNodes, false);

        // Set distance of the start node to itself as 0
        dist[start->id] = 0;

        // Loop to find shortest path for all nodes
        for (int count = 0; count < numNodes - 1; count++) {
            // Find the unvisited node with the minimum distance
            int u = minDistance(dist, visited);

            // Mark the node as visited
            visited[u] = true;

            // Update the distances of adjacent nodes
            for (int i = 0; i < edges[u].size(); i++) {
                int v = edges[u][i].first;
                int weight = edges[u][i].second;

                // Check if the path through u to v is shorter than the known path
                if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Print the shortest distances
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < numNodes; i++) {
            cout << i << " \t\t " << dist[i] << endl;
        }
    }
};

int main()
{
    Node* cityA = new Node(0, "0");
    Node* cityB = new Node(1, "1");
    Node* cityC = new Node(2, "2");
    Node* cityD = new Node(3, "3");
    Node* cityE = new Node(4, "4");

    AdjacencyList* map = new AdjacencyList(5);
    map->addNode(cityA);
    map->addNode(cityB);
    map->addNode(cityC);
    map->addNode(cityD);
    map->addNode(cityE);

    map->addEdge(cityA, cityB, 2);
    map->addEdge(cityA, cityD, 7);
    map->addEdge(cityB, cityC, 3);
    map->addEdge(cityB, cityE, 4);
    map->addEdge(cityC, cityD, 1);
    map->addEdge(cityD, cityE, 4);

    cout << "Printing all paths: " << endl;
    map->printPaths();

    cout << "Print all weights: " << endl;
    map->printWeights();

    cout << "Shortest paths from city 0:" << endl;
    map->findShortestPath(cityA);

    delete map;

    return 0;
}
