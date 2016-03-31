#include "genomics.cpp"

class Node {
public:
	int startIndex; //where the string starts [1.....n]
	int stringDepth; //where the string ends [1.....n]
	int nodeDepth;

	Node *parent;
	Node *sl;
	Node *child;
	Node *sibling;
	
	Node() {};
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
		root = new Node(0, 0, 0, root);
		root->sl = root;
		u = root->parent;

		for (unsigned int i = 1; i <= s.length(); i++)
		{
			insertString(suffix(i));
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
		//STEP 1
			//TODO
		//STEP 2
		if (true) //case1a (SL(u)) && (u != root) 
		{

		}
		else if (true) //case1b (SL(u)) && (u == root)
		{

		}
		else if (true) //case2a !(SL(u)) && (u != root)
		{

		}
		else if (true) //case2b !(SL(u)) && (u == root)
		{

		}
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

	//(SL(u)) && (u != root)
	void case1a()
	{

	}

	//(SL(u)) && (u == root)
	void case1b()
	{

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

	//called to insert a string under a node by either adding a new terminal node, or breaking an edge and adding two node.
	void insertNode(Node parent, int stringStart)
	{
			
	}
};