#include "genomics.cpp"

class Node {
public:
	int startIndex;
	int stringDepth;
	int nodeDepth;

	Node *parent;
	Node *sl;
	vector<Node> children;
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
		//To <- make root node
		for (unsigned int i = 1; i <= s.length(); i++)
		{
			insert(suffi(i));
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

	}

	string pathLabel(Node u)
	{

	}

	string suffi(int i)
	{
		return s.substr(i - 1);
	}

	void insert(string t )
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