#include "genomics.cpp"

class Node {
public:
	int startIndex;
	int stringDepth;
	int nodeDepth;

	Node *parent;
	Node *sl;
	std::vector<Node> children;
};

class McSuffixTree
{
public:
	Node *root;
	std::string s;
	Alphabet sigma;

	McSuffixTree(std::string sIn, Alphabet aIn)
	{
		McSuffixTree::sigma = aIn;
		McSuffixTree::s = sIn + sigma.rootDelimiter->sym;

		for (int i = 1; i <= McSuffixTree::s.length(); i++)
		{
			std::cout << i << ": " << McSuffixTree::suffi(i) << std::endl;
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

	std::string pathLabel(Node u)
	{

	}

	std::string suffi(int i)
	{
		return McSuffixTree::s.substr(i - 1);
	}

	void insert(std::string)
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