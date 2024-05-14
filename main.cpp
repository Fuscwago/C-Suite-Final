#include <iostream>
#include <vector>

using namespace std; 

class Node{
    public:
        string name;
        int travelTime;
        bool visited;
        Node* nextNode;

        Node(string name, int travelTime, bool visited){
            this->name = name;
            this->travelTime = travelTime;
            this->visited = visited;
            this->nextNode = nullptr;
        }
};

class linkedList{
    private:
        Node* head;
        Node* tail;

    public:
        linkedList(Node *head){
            this->head = head;
            tail = nullptr;
        }

        //add node to end of list
        void push(string name, int travelTime, bool visited){
            Node* newNode = new Node(name, travelTime, visited);
            tail = newNode;
            tail->nextNode = nullptr;
        }

        //overload in case node is passed
        void push(Node* node){
            tail = node;
            tail->nextNode;
        }
        
        void insert(string name, int travelTime, bool visited){
            Node* newNode = new Node(name, travelTime, visited);
            newNode->nextNode = head;
            head = newNode;
        }

        void print(){
            cout << head->name << endl;
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
    Node* cityB = new Node("Pilly", 40, false);
    linkedList* list = new linkedList(cityA);
    list->push(cityA);
    list->print();

    return 0; 
} 