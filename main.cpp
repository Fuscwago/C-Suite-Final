#include <iostream>
#include <vector>
#include <climits>

using namespace std; 

class Node{
    public:
        int id;
        string name;
        int travelTime;
        bool visited;
        Node* nextNode;

        Node(int id, string name, int travelTime, bool visited){
            this->id = id;
            this->name = name;
            this->travelTime = travelTime;
            this->visited = visited;
            this->nextNode = nullptr;
        }
        Node(){
            this->id = 0;
            this->name = "";
            this->travelTime = INT_MAX;
            this->visited = false;
            this->nextNode = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;

    public:
        LinkedList(){
            this->head = nullptr;
        }

        //destructor
        ~LinkedList(){
            Node* current = head;
            while(current != nullptr){
                Node* toDelete = current;
                current = current->nextNode;
                delete toDelete;
            }
            delete head;
        }

        //add node to end of list
        void append(int id, string name, int travelTime, bool visited){
            Node* currNode = head;

            if(head == nullptr){
                head = new Node(id, name, travelTime, visited);
                return;
            }

            while(currNode->nextNode != nullptr){
                currNode = currNode->nextNode;
            }
            currNode->nextNode = new Node(id, name, travelTime, visited);
        }

        //overload in case node is passed
        void append(Node* node){
            Node* newNode = new Node(node->id, node->name, node->travelTime, node->visited);
            
            Node* currNode = head;

            if(head == nullptr){
                head = newNode;
                return;
            }

            while(currNode->nextNode != nullptr){
                currNode = currNode->nextNode;
            }
            currNode->nextNode = newNode;
        }
        
        //add node to start of list
        void push(Node* node){
            Node* temp = head;
            head = node;
            head->nextNode = temp;
        }

        //another overload
        void push(int id, string name, int travelTime, bool visited){
            Node* temp = head;
            head = new Node(id, name, travelTime, visited);
            head->nextNode = temp;
        }

        void setHead(Node* head){
            this->head = head;
        }

        //overload again
        void setHead(int id, string name, int travelTime, bool visited){
            this->head = new Node(id, name, travelTime, visited);
        }

        string getHead(){
            return head->name;
        }

        void print(){
            Node* currNode = head;
            
            if(currNode == nullptr){
                cout << "List is empty";
            }
            
            while(currNode->nextNode != nullptr){
                cout << currNode->name << "->";
                currNode = currNode->nextNode;
            }
            cout << currNode->name << endl;
        }
};

class AdjacencyList{
    public:
        int numNodes;
        vector<LinkedList> *paths;
        vector<vector<int>> edges;

        AdjacencyList(int numNodes){
            this->numNodes = numNodes;
            this->paths = new vector<LinkedList>(numNodes);
            this->edges = vector<vector<int>>(numNodes);
        }

        ~AdjacencyList(){
            delete paths;
        }

        void addNode(Node* node){
            (*paths)[node->id].setHead(node);
        }
        
        void addEdge(Node* start, Node* end, int weight){
            (*paths)[start->id].append(end);
            edges[start->id].push_back(weight);
            
            (*paths)[end->id].append(start);
            edges[end->id].push_back(weight);
        }


        void printPath(int pathId){
            (*paths)[pathId].print();
        }

        void printPaths(){
            for(int i = 0; i < numNodes; i++){
                if((*paths)[i].getHead() != ""){
                    (*paths)[i].print();
                }
                else{
                    cout << "Path is Empty" << endl;
                }
            }
        }

        void printWeights(){
            for(int i = 0; i < numNodes; i++){
                if((*paths)[i].getHead() != ""){
                    for(int j = 0; j < edges[i].size(); j++){
                        cout << edges[i][j] << " ";
                    }
                    cout << endl;
                }
                else{
                    cout << "Path is Empty" << endl;
                }
            }
            cout << endl;
        }

        // LinkedList findShortestPath(Node* start, Node* end){

        // }
        
};
  
int main() 
{ 
    Node* cityA = new Node(0, "0", 0, true);
    Node* cityB = new Node(1, "1", INT_MAX, false);
    Node* cityC = new Node(2, "2", INT_MAX, false);
    Node* cityD = new Node(3, "3", INT_MAX, false);
    Node* cityE = new Node(4, "4", INT_MAX, false);

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

    cout << "Print all paths and weights: " << endl;
    map->printWeights();


    delete map;

    return 0; 
} 