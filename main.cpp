#include <iostream>
#include <vector>

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
        LinkedList(Node *head){
            this->head = head;
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
            while(currNode->nextNode != nullptr){
                currNode = currNode->nextNode;
            }
            currNode->nextNode = new Node(id, name, travelTime, visited);
        }

        //overload in case node is passed
        void append(Node* node){
            Node* currNode = head;
            while(currNode->nextNode != nullptr){
                currNode = currNode->nextNode;
            }
            currNode->nextNode = node;
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

        string getHead(){
            return head->name;
        }

        void print(){
            Node* currNode = head;
            while(currNode->nextNode != nullptr){
                cout << currNode->name << "->";
                currNode = currNode->nextNode;
            }
            cout << currNode->name << endl;
        }
};

class AdjacencyList{
    private:
        int numNodes;
        vector<LinkedList> *path;
    
    public:
        // AdjacencyList(int numNodes){ //needs default LinkedList constructor
        //     this->numNodes = numNodes;
        //     this->path = new vector<LinkedList>(numNodes);
        // }

        void changeHeadNode(string name){
            for(int i = 0; i < path->size(); i++){
                
            }
        }
        
        void addEdge(Node* start, Node* end){
            //path[].append(end);

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
    Node* cityA = new Node(0, "Pittsburgh", 10, true);
    Node* cityB = new Node(1, "Philly", 40, false);
    Node* cityC = new Node(2, "Bublakandia", 100, false);
    Node* cityD = new Node(3, "Throckmortonia", 25, false);
    Node* cityE = new Node(4, "Nuuk Greenland", 100, false);
    Node* cityF = new Node();
    LinkedList* list = new LinkedList(cityA);
    list->append(cityB);
    list->append(cityC);
    list->print();
    list->push(cityD);
    list->print();

    //AdjacencyList* map = new AdjacencyList(5);

    delete list;
    delete cityE;
    delete cityF;

    return 0; 
} 