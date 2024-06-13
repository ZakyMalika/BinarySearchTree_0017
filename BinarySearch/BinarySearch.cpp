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

		Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode); // locate the node which be parent of the node to be inserted

		if (parent == nullptr) // if the parent is NNULL (tree is empty)
		{
			
			ROOT = newNode; // mark the new node as root 
			return; //exit
		}
		if (element < parent->info) // if the value in the data field pf the new node is less than  that of the parent
		{
			parent->leftchild = newNode;	// make the leftchild of the parent point to the new node

		}
		else  if (element > parent->info) // if the value in the data field of the new data is greater than that of the parent
		{
			parent->rightchild = newNode;
		}
	}

	void search(string element, Node*& parent, Node*& currentNode) /////
	{
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != nullptr) && currentNode->info != element)
		{
			parent = currentNode;
			if (element < currentNode->info)
			{
				currentNode = currentNode->leftchild;
			}
			else 
			{
				currentNode = currentNode->rightchild;
			}
		}
	}
	void inorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) 
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}
	void preorder(Node* ptr)
	{ 
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild); 
			preorder(ptr->rightchild);
		}
	}
	void postorder(Node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	BinaryTree x;
	while (true) {
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			x.insert(word);
			break;
		}
		case '2':
		{
			x.inorder(x.ROOT);
			break;
		}
		case '3':
		{
			x.preorder(x.ROOT);
			break;
		}
		case '4': {
			x.postorder(x.ROOT);
			break;
		}
		case '5': {
			return 0;
		}

		default:
			cout << "Pilihan tidak ditemukan" << endl;
			break;

		}

	}

}