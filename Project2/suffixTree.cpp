#include "genomics.cpp"

class Node {
public:
	unsigned int startIndex;
	unsigned int stringDepth;
	unsigned int nodeDepth;

	char startChar;

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

		for (unsigned int i = 1; i <= s.length(); i++)
		{
			cout << i << ": " << suffi(i) << endl;
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