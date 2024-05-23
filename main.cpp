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
        //Node* prevNode; //do i need this 

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

        void insert(Node* left, Node* right, Node* data){
            
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

        AdjacencyList(int numNodes){
            this->numNodes = numNodes;
            this->paths = new vector<LinkedList>(numNodes);
        }

        ~AdjacencyList(){
            delete paths;
        }

        void addNode(Node* node){
            (*paths)[node->id].setHead(node);
        }
        
        void addEdge(Node* start, Node* end){
            (*paths)[start->id].append(end);
            (*paths)[end->id].append(start);
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
                    cout << "Path is Empty!" << endl;
                }
            }
        }
        
};

class Edge{
    public:
        string start;
        string end;
        string distance;
};
  
int main() 
{ 
    Node* cityA = new Node(0, "0", 10, true);
    Node* cityB = new Node(1, "1", 40, false);
    Node* cityC = new Node(2, "2", 100, false);
    Node* cityD = new Node(3, "3", 25, false);
    Node* cityE = new Node(4, "4", 100, false);

    AdjacencyList* map = new AdjacencyList(5);
    map->addNode(cityA);
    map->addNode(cityB);
    map->addNode(cityC);
    map->addNode(cityD);
    map->addNode(cityE);


    map->addEdge(cityA, cityB); 
    map->addEdge(cityA, cityD);
    map->addEdge(cityB, cityC);
    map->addEdge(cityB, cityE);
    map->addEdge(cityC, cityD);
    map->addEdge(cityD, cityE);
    
    cout << "Printing all paths: " << endl;
    map->printPaths();



    delete map;

    return 0; 
} 