#include "genomics.cpp"

class Node {
public:
	int startIndex = 0; //where the string starts [1.....n]
	int stringDepth = 0; //where the string ends [1.....n]
	int nodeDepth = 0;

	Node *parent = NULL;
	Node *sL = NULL;
	Node *child = NULL;
	Node *sibling = NULL;
	
	Node() {};
	Node(int sI, int sD, int nD)
	{
		startIndex = sI;
		stringDepth = sD;
		nodeDepth = nD;
	}
	Node(int sI, int sD, int nD, Node *pP)
	{
		startIndex = sI;
		stringDepth = sD;
		nodeDepth = nD;
		parent = pP;
	}
};

class McSuffixTree
{
public:
	Node *root;
	Node *u;
	string s;
	Alphabet sigma;

	McSuffixTree(string sIn, Alphabet aIn)
	{
		sigma = aIn;
		s = sIn + sigma.rootDelimiter->sym;

		init();
	}

	void init()
	{
		root = new Node(0, 0, 0);
		root->parent = root;
		root->sL = root;
		u = root->parent;

		for (unsigned int i = 1; i <= s.length(); i++)
		{
			insertSuffix(i);
			//insertString(suffix(i));
		}
	}

	void displayChildren(Node *u)
	{

	}
	
	void printDFST()
	{

	}

	void FindPath(Node *v, string t)
	{

	}

	void findPath(Node *v, int t)
	{
		Node *n = v->child;

		while (n != NULL)
		{
			if (s[n->startIndex] == s[t - 1])
			{
				//if a child node matches....
				//todo
			}
			else
				n = n->sibling;
		}
		
		//if there is no matching child, insert one!
		insertNode(v, t);
	}

	string pathLabel(Node u)
	{

	}

	string suffix(int i)
	{
		return s.substr(i - 1);
	}

	void insertString(string t)
	{
		//DEBUG
		cout << "Inserting: "<< t << endl;
		//END DEBUG

	}

	void insertSuffix(int i)
	{
		//DEBUG
		cout << "Inserting by index: " << s.substr(i-1) << endl;
		//END DEBUG
		if (u->sL && (u != root)) //case1a (SL(u)) && (u != root) 
		{
			cout << "case 1a called for suffix " << i << "." << endl;
		}
		else if (u->sL && (u == root)) //case1b (SL(u)) && (u == root)
		{
			cout << "case 1b called for suffix " << i << "." << endl;
			case1b(i);
		}
		else if (!(u->sL) && (u != root)) //case2a !(SL(u)) && (u != root)
		{
			cout << "case 2a called for suffix " << i << "." << endl;
		}
		else if (!(u->sL) && (u == root)) //case2b !(SL(u)) && (u == root)
		{
			cout << "case 2b called for suffix " << i << "." << endl;
		}

	}

	//(SL(u)) && (u != root)
	void case1a()
	{

	}

	//(SL(u)) && (u == root)
	void case1b(int i)
	{
		//FindPath(root, suffix(i));
		findPath(root, i);
	}

	//!(SL(u)) && (u != root)
	void case2a()
	{

	}

	//!(SL(u)) && (u == root)
	void case2b()
	{

	}

	void nodeHops(Node vPrime, string beta)
	{

	}

	//called to insert a string under a node by either adding a new terminal node, or breaking an edge and adding two nodes.
	void insertNode(Node *parent, int stringStart)
	{
		cout << "Making node for index " << stringStart << ".\n";
		
		//if parent has no children...
		if (parent->child == NULL)
		{
			parent->child = new Node(stringStart, s.length()-stringStart+1, parent->nodeDepth + 1);
		}


		return;
		//make new node
		//find correct spot in children chain for it lexographically .. 
		//we have children 1...i,j...n
		//child i is the one we want to insert, child j is the next.
		//when we insert child i, child i-1's sib
	}
};