#include <iostream>
#include<string>
using namespace std;

class  Node
{
public:
	string info;
	Node* leftchild; 
	Node* rightchild; 

	// Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree
{
public:
	Node* ROOT;
	BinaryTree()
	{
		ROOT = nullptr; // initializing ROOT to NULL
	}

	void insert(string element) // insert a node in the binary search
	{
		Node* newNode = new Node(element, nullptr, nullptr); // Allocate memory for thhe new Node
		newNode->info = element;	//assign value to the data field of the new data
		newNode->leftchild = nullptr; // make the left child of the new node point to null
		newNode->rightchild = nullptr; // make the right child of the node point to null
	}
};