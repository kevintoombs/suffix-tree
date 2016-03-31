#include "genomics.cpp"

class Node {
public:
	int startIndex; //where the string starts [1.....n]
	int stringDepth; //where the string ends [1.....n]
	int nodeDepth;

	Node *parent;
	Node *sL;
	Node *child;
	Node *sibling;
	
	Node() {};
	Node(int sI, int sD, int nD)
	{
		startIndex = sI;
		stringDepth = sD;
		nodeDepth = nD;
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
			cout << "case 1a called." << endl;
		}
		else if (u->sL && (u == root)) //case1b (SL(u)) && (u == root)
		{
			cout << "case 1b called." << endl;
			case1b(i);
		}
		else if (!(u->sL) && (u != root)) //case2a !(SL(u)) && (u != root)
		{
			cout << "case 2a called." << endl;

		}
		else if (!(u->sL) && (u == root)) //case2b !(SL(u)) && (u == root)
		{
			cout << "case 2b called." << endl;
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

	//called to insert a string under a node by either adding a new terminal node, or breaking an edge and adding two node.
	void insertNode(Node parent, int stringStart)
	{
			
	}
};