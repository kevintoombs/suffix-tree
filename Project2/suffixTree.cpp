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
		McSuffixTree::sigma = aIn;
		McSuffixTree::s = sIn + sigma.rootDelimiter->sym;

		for (int i = 1; i <= McSuffixTree::s.length(); i++)
		{
			cout << i << ": " << McSuffixTree::suffi(i) << endl;
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
		return McSuffixTree::s.substr(i - 1);
	}

	void insert(string)
	{

	}

	void case1a()
	{

	}

	void case1b()
	{

	}

	void case2a()
	{

	}

	void case2b()
	{

	}

};