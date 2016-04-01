#include "genomics.cpp"

class Node {
public:
	int startIndex = 0; //where the string starts [1.....n]
	int stringDepth = 0; //where the string ends when added to  startIndex [1.....n]
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
		Node *lastN = NULL;

		int sumI = 0;

		while (n != NULL)
		{
			if (s[n->startIndex - 1] == s[t - 1])
			{
				int i = 1;
				while ((s[n->startIndex - 1 + i] == s[t - 1 + i]) && (i < n->stringDepth - n->startIndex))
				{
					i++;
				}

				if (i == n->stringDepth)
				{
					v = n;
					n = v->child;
					sumI += i;
				}
				else
				{
					printf("===!!!!===break called with i = %i\n", i);
					edgeBreak(v, n, lastN, i, t+sumI+i);

					return;
				}
			}
			else
			{
				lastN = n;
				n = n->sibling;
			}
		}
		
		//if there is no matching child, insert one!
		//or lets use this no matter what
		insertNode(v, t);
	}

	string pathLabel(Node u)
	{
		Node* temp;
		temp = u.parent;
		while (temp->parent != root)
		{
			temp = temp->parent;
		}
		if (&u == root)
			return "";
		return s.substr(temp->startIndex, u.startIndex);
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
			case1a(u, i);
		}
		else if (u->sL && (u == root)) //case1b (SL(u)) && (u == root)
		{
			cout << "case 1b called for suffix " << i << "." << endl;
			case1b(u, i);
		}
		else if (!(u->sL) && (u->parent != root)) //case2a !(SL(u)) && (u != root)
		{
			cout << "case 2a called for suffix " << i << "." << endl;
			case2a(u, i);
		}
		else if (!(u->sL) && (u->parent == root)) //case2b !(SL(u)) && (u == root)
		{
			cout << "case 2b called for suffix " << i << "." << endl;
			case2b(u, i);
		}

	}

	//(SL(u)) && (u != root)
	void case1a(Node *u, int i)
	{
		Node *v = u->sL;
		findPath(v, i);
	}

	//(SL(u)) && (u == root)
	void case1b(Node *u, int i)
	{
		Node *v = u->sL;
		findPath(v, i);
	}

	//!(SL(u)) && (u' != root)
	void case2a(Node *u, int i)
	{
		Node *uPrime = u->parent;
		Node *vPrime = uPrime->sL;
		nodeHops(*vPrime, u->startIndex, u->stringDepth);
		Node *v = u->sL;
		findPath(v, i + u->stringDepth);
	}

	//!(SL(u)) && (u' == root)
	void case2b(Node *u, int i)
	{
		Node *uPrime = u->parent;
		Node *vPrime = uPrime->sL;
		nodeHops(*vPrime,  u->startIndex, u->stringDepth);
		Node *v = u->sL;
		findPath(v, i+u->stringDepth);
	}

	void nodeHops(Node vPrime, int betaStart, int betaLength)
	{
		Node* child = vPrime.child;
		//begin node hop, stopping when we are at the endpoint, or will insert on an edge
		while (betaLength >= (child->startIndex - vPrime.startIndex) && betaLength > 0)
		{
			
			while (s[child->startIndex-1] != s[betaStart-1])
			{
				child = child->sibling;
			}
			betaLength -= child->startIndex - vPrime.startIndex;
			betaStart += child->startIndex - vPrime.startIndex;
			//at this point we have the right child
			vPrime = *child;
			child = vPrime.child;
		}
		//mid-edge insertion
		if (betaLength > 0)
		{
			//NEED TO INSERT FIND PATH HERE WITH SPECIAL
			//edgeBreak(vPrime, child, lastN, i, t + sumI + i); //TODO
			u->sL = child;
		}
		//endpoint insertion
		else
		{
			//findPath(child, betaStart);
			u->sL = child;
		}
	}

	//called to insert a string under a node by adding a new terminal node.
	void insertNode(Node *parent, int stringStart)
	{
		cout << "Making node for index " << stringStart << ".\n";
		
		Node *child = parent->child;

		//if parent has no children...
		if (child == NULL)
		{
			parent->child = new Node(stringStart, s.length()-stringStart+1, parent->nodeDepth + 1, parent);
			u = parent;
			return;
		}
		//otherwise loop through children
		else
		{
			while (child != NULL)
			{
				cout << ".";
				//if we get a matching child
				if (s[stringStart-1] == s[child->startIndex-1])
				{
					//should never happen
					exit(2);
				}
				else
				{
					if (child->sibling == NULL)
					{
						child->sibling = new Node(stringStart, s.length() - stringStart + 1, parent->nodeDepth + 1, parent);
						u = parent;
						return;
					}
					else
					{
						child = child->sibling;
					}
				}
			}
		}

		//make new node
		//find correct spot in children chain for it lexographically .. 
		//we have children 1...i,j...n
		//child j is the one we want to insert, child i is the previous.
		//when we insert child j, child j's sibling pointer points to child i, and child i's sibling pointer is what j's used to be 


			//this is always the final function call, now we set the next u and repeat.
		exit(1);
		return;
	}

	void edgeBreak(Node* v, Node* vChild, Node* vSibling, int correctComparisons, int t)
	{
		Node* Ui = new Node(vChild->startIndex, correctComparisons, vChild->nodeDepth, v);
		Ui->child = vChild;
		//if vChild is not v's first child
		if (vSibling != NULL)
			vSibling->sibling = Ui;
		//if vChild IS v's first child
		else
			v->child = Ui;
		vChild->parent = Ui;

		//handle the case where the child being replaced has a sibling pointer
		if (vChild->sibling != NULL)
		{
			Ui->sibling = vChild->sibling;
			vChild->sibling = NULL;
		}
		//replaced child's node depth increases by 1
		vChild->nodeDepth++;
		vChild->stringDepth -= correctComparisons;
		//set previous child's start index to the last character of Ui + 1

		vChild->startIndex = Ui->startIndex + Ui->stringDepth;
		if (u != root) u->sL = Ui;
		insertNode(Ui, t);
	}

	void BWT()
	{

	}
	void BWTHelper(Node* node, vector<int>* bwtArray)
	{
		if (node == NULL)
			return;
		if (node->child == NULL)
		{
			bwtArray->push_back(node->startIndex);
			return;
		}
		else
		{
			BWTHelper(node->child, bwtArray);
		}
		if (node->sibling != NULL)
			BWTHelper(node->sibling, bwtArray);
		return;
		
	}
};