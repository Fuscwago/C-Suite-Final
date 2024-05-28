# Ryan’s C Suite Final
<p>
An implementation of a basic data structure and algorithm.

What are we trying to accomplish? Suppose a set of linked cities where you can freely travel between them: we want to find the shortest distance between two cities.







This map of cities is known as a weighted undirected graph. Each vertex or node will contain all the information about the city and each edge will contain the distance between the cities.

This means that the graph above can be represented like this:
Paths:
0: 1, 3
1: 0, 2, 4
2: 1, 3
3: 0, 2, 4
4: 1, 3

Edges:
2, 7
2, 3, 4
3, 1
7, 1, 4
 4, 4

In this exercise you will need to create the data structure to represent the information above in order to compute the shortest possible distance between two nodes.

This can be done with an array of linked lists known as an Adjacency List. A linked list is a linear structure that contains a series of linked nodes. Each node stores the next node’s location (this means pointer).





Part 1: Nodes and Linked Lists
You will need two classes (Node and LinkedList).

Node:
-contains an id, a name, and a pointer to the next node (I will let you decide if you want them public or private)

-two constructors one to pass data and one default

Linked List:
-contains a head (starting point of list) which must be a pointer and private (everything else can be public)

-a constructor (no input parameters)

-a destructor (remember the ~) (this lets you free up the memory used by the pointers)
	set a pointer node to head
	while the current node is not a null pointer
		set another pointer node to the current node
		current will become the next
		delete the pointer node
	try the pseudocode, then google an example before you ask (you can do it!)
-5 functions (and however many else you want: it may be nice to have overloads)
	append to add a node to the end of the list (could take an id and name or node)
	push to add a node to the start of the list (could also take an id and name or node)
	setHead to set the head of the linked list
	getHead to return the value of the head (remember its private)
	Print to print the content of the list

</p>