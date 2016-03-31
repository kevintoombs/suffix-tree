#include "genomics.cpp"

class Node {
public:
	int startIndex;
	int stringDepth;
	int nodeDepth;

	Node *parent;
	Node *sl;
	vector<Node> children;
	
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

		for (unsigned int i = 1; i <= s.length(); i++)
		{
			insert(suffix(i));
		}
	}

	void displayChildren(Node *u)
	{

	}
	
	void printDFST()
	{

	}

	void FindPath(Node *v, std::string t)
	{
		//STEP 1
			//TODO
		//STEP 2
		if (/*case1*/true)
		{

		}
		else if (/*case1*/true)
		{

		}
		else if (/*case1*/true)
		{

		}
		else if (/*case1*/true)
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

	void insert(string t)
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

};