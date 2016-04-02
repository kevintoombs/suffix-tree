#include "genomics.cpp"

class Node {
public:
	int startIndex = 0; //where the string starts [1.....n]
	int stringSize = 0; //where the string ends when added to  startIndex [1.....n]
	int nodeDepth = 0;

	Node *parent = NULL;
	Node *sL = NULL;
	Node *child = NULL;
	Node *sibling = NULL;
	
	Node() {};
	Node(int sI, int sD, int nD)
	{
		startIndex = sI;
		stringSize = sD;
		nodeDepth = nD;
	}
	Node(int sI, int sS, int nD, Node *pP)
	{
		startIndex = sI;
		stringSize = sS;
		nodeDepth = nD;
		parent = pP;
	}
};

class McSuffixTree
{
public:
	Node *root;
	Node *u;
	Node *LongestInternalNode;
	int ExactMatchLength;
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
			displayAllChildren(root);
			__noop;
		}
	}

	void displayAllChildren(Node *u)
	{
		Node *child = u->child;
		
		cout << u->nodeDepth << ":";
		for (int i = 0; i < u->nodeDepth; i++)
		{
			cout << " ";
		}
		cout << "[";
		while (child != NULL)
		{
			cout << "(" << child->startIndex << "," << child->stringSize;
			if (child->nodeDepth != u->nodeDepth + 1)
			{
				cout << "{!!!" << child->nodeDepth << ": not correct node depth}";
			}

			if (child->sL != NULL && false)
			{
				cout << "|!!!" << child->sL->startIndex << "," << child->sL->stringSize << "suffix link|";
			}
			cout << ")";
			child = child->sibling;
		}
		cout << "]" << endl;

		child = u->child;
		while (child != NULL)
		{
			displayAllChildren(child);
			child = child->sibling;
		}
		
	}

	void displayChildren(Node *u)
	{
		Node *child = u->child;
		while (child != NULL) 
		{
			cout << child->startIndex << "," << child->stringSize << endl;
			child = child->sibling;
		}
	}
	
	void printDFST()
	{

	}

	void findPath(Node *v, int t)
	{
		//check the children of n
		Node *n = v->child;
		Node *lastN = NULL;

		
		int sumI = 0;
		//if n has any children or hasn't run out of possiblities
		while (n != NULL)
		{
			
			//if the first character of the child matches matches...
			if (s[n->startIndex - 1] == s[t - 1])
			{
				//set matches to 1 
				int i = 1;
				//check for more matches
				while ((s[n->startIndex - 1 + i] == s[t - 1 + i]) && (i < n->stringSize - n->startIndex))
				{
					i++;
				}

				//if all characters matched
				if (i == n->stringSize)
				{
					//set this child to the new parent
					v = n;
					//set it's first child to the child
					n = v->child;
					//note how many matches have been made total.
					sumI += i;
				}
				//otherwise break the edge that far down.
				else
				{
					printf("===!!!!===break called with i = %i\n", i);
					findPath(edgeBreak(v, n, lastN, i), t + sumI + i);

					return;
				}
			}
			//if not go to the next child
			else
			{
				lastN = n;
				n = n->sibling;
			}
		}
		
		//if there is no matching child, insert one!
		//or lets use this no matter what
		insertNode(v, t+sumI);
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
		nodeHops(vPrime, u->startIndex, u->stringSize);
		Node *v = u->sL;
		findPath(v, i + u->stringSize);
	}

	//!(SL(u)) && (u' == root)
	void case2b(Node *u, int i)
	{
		Node *uPrime = u->parent;
		Node *vPrime = uPrime->sL;
		nodeHops(vPrime,  u->startIndex+1, u->stringSize-1);	
		Node *v = u->sL;
		findPath(v, i+u->stringSize-1);
	}

	void nodeHops(Node* vPrime, int betaStart, int betaLength)
	{
		if (betaLength == 0)
		{
			u->sL = vPrime;
			return;
		}
		Node* child = vPrime->child;
		Node* parent = child->parent;
		Node* prevSibling = NULL;
		bool b = true;
		//begin node hop, stopping when we are at the endpoint, or will insert on an edge
		while (/*betaLength >= (child->stringSize)*/b && betaLength > 0)
		{
			parent = child->parent;
			prevSibling = NULL;
			while (s[child->startIndex-1] != s[betaStart-1])
			{
				prevSibling = child;
				child = child->sibling;
				
			}

			if (betaLength < (child->stringSize))
			{
				b = false;
			}
			else 
			{
				betaLength -= child->stringSize;
				betaStart += child->stringSize;
				//at this point we have the right child

				
				child = child->child;
			}
		}

		//mid-edge insertion
		if (betaLength > 0)
		{
			//NEED TO INSERT FIND PATH HERE WITH SPECIAL
			Node* v= edgeBreak(parent, child, prevSibling, betaLength);

			u->sL =v; //TODO
			//u->sL = child;
		}
		//endpoint insertion
		else
		{
			u->sL = child;
			//findPath(child, betaStart);
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
				//cout << ".";
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

	Node* edgeBreak(Node* v, Node* vChild, Node* vSibling, int correctComparisons)
	{
		printf("===!!!!===break called\n");
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
		vChild->stringSize -= correctComparisons;
		//set previous child's start index to the last character of Ui + 1

		vChild->startIndex = Ui->startIndex + Ui->stringSize;
		//if (u->sL == NULL) u->sL = Ui;
		return Ui;
	}

	void BWT()
	{
		vector<int> bwtArray;
		BWTHelper(root, &bwtArray);
		vector<char> bwtResult;
		unsigned int i;
		for (i = 0; i < bwtArray.size(); i++)
		{
			if (bwtArray[i] == 1)
				bwtResult.push_back('$');
			else
				bwtResult.push_back(s[bwtArray[i]]);
		}
		ofstream outfile;
		outfile.open("outfile.txt");
		for (i = 0; i < bwtResult.size(); i++)
			outfile << bwtResult[i] << endl;
		outfile.close();
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

	void ExactMatchingRepeat()
	{
		//find longest internal node
		ExactMatchLength = 0;
		ExactMatchHelper(0, root);
		cout << "----------------------" << endl;
		cout << "Exact Matching Repeat:" << endl;
		cout << "Length: " << ExactMatchLength << endl;
		cout << "Starting Coordinates: " << LongestInternalNode->startIndex << " and " << abs(LongestInternalNode->child->stringSize - LongestInternalNode->child->sibling->stringSize) + LongestInternalNode->startIndex << endl;
		cout << "----------------------" << endl;
	}

	void ExactMatchHelper(int currentDepth, Node* node)
	{
		if (node == NULL)
			return;
		if (node->child == NULL)
			return;
		currentDepth += node->stringSize;
		if (currentDepth > ExactMatchLength)
		{
			ExactMatchLength = currentDepth;
			LongestInternalNode = node;
		}
		ExactMatchHelper(currentDepth, node->child);
		ExactMatchHelper(currentDepth - node->stringSize, node->sibling);
		return;
	}
};