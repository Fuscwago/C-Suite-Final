#include <iostream>
#include <vector>

using namespace std; 

class Node{
    public:
        string name;
        int travelTime;
        bool visited;
        Node* nextNode;
        //Node* prevNode; //do i need this 

        Node(string name, int travelTime, bool visited){
            this->name = name;
            this->travelTime = travelTime;
            this->visited = visited;
            this->nextNode = nullptr;
        }
        Node(){
            this->name = "";
            this->travelTime = INT_MAX;
            this->visited = NULL;
            this->nextNode = nullptr;
        }
};

class linkedList{
    private:
        Node* head;

    public:
        linkedList(Node *head){
            this->head = head;
        }

        //add node to end of list
        void append(string name, int travelTime, bool visited){
            Node* currNode = head;
            while(currNode->nextNode != nullptr){
                currNode = currNode->nextNode;
            }
            currNode->nextNode = new Node(name, travelTime, visited);
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
        void push(string name, int travelTime, bool visited){
            Node* temp = head;
            head = new Node(name, travelTime, visited);
            head->nextNode = temp;
        }

        void insert(Node* left, Node* right, Node* data){
            
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

class map{
    private:
        int numNodes;
        vector<linkedList> paths;

        //map()
};

class edge{
    public:
        string start;
        string end;
        string distance;
};
  
int main() 
{ 
    Node* cityA = new Node("Pittsburgh", 10, true);
    Node* cityB = new Node("Philly", 40, false);
    Node* cityC = new Node("Bublakandia", 100, false);
    Node* cityD = new Node("Throckmortonia", 25, false);
    Node* cityE = new Node("Nuuk Greenland", 100, false);
    Node* cityF = new Node();
    linkedList* list = new linkedList(cityA);
    list->append(cityB);
    list->append(cityC);
    list->print();
    list->push(cityD);
    list->print();

    return 0; 
} 