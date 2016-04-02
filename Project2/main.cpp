#include "suffixTree.cpp"

int main(int argc, char *argv[])
{
	string inputString = Sequence::parseFasta(argv[1]); //input argument one should be a fasta input file
	Alphabet a = Alphabet::parseAlphabet(argv[2], '$'); //input argument two should be an alphabet file

	//Tree is constructed from the given alphabet and string.
	unsigned int start = clock();
	McSuffixTree mST(inputString, a);
	cout << "The tree took: " << clock() - start << "ms to build" << endl << endl;

	cout << "TREE STATS" << endl;
	cout << "Number of internal nodes: " << mST.nodes - mST.s.length() << endl; //cheating
	cout << "Number of leaves: " << mST.s.length() << endl; //cheating
	cout << "Number of total nodes: " << mST.nodes << endl;
	cout << "Size of tree in bytes: " << sizeof(mST) << endl;
	cout << "average string depth of internal nodes" << "[[TODO]]" << endl;
	cout << "string-depth of deepest eternal node" << "[[TODO]]" << endl;
	cout << endl;

	cout << "print some random children" << "[[TODO]]" << endl;
	cout << endl;

	
	mST.printDFST();
	cout << "DFST written to out file." << endl;
	//mST.printBWT();
	cout << "BWT written to out file" << "[[TODO]]" <<endl;
	cout << endl;

	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;


}

int oldMain(int argc, char *argv[])
{

	string inputString = Sequence::parseFasta(argv[1]);
	//cout << inputString << endl;

	Alphabet a = Alphabet::parseAlphabet(argv[2], '$');
	//a.display();


	unsigned int start = clock();
	McSuffixTree mST(inputString, a);
	std::cout << "Time taken in millisecs: " << clock() - start << endl;

	//cout << mST.s << endl;
	//mST.sigma.display();
	//mST.BWT();


	mST.printDFST();

	//cout << mST.s << endl;
	//mST.sigma.display();

	//mST.ExactMatchingRepeat();

	cin.ignore();
	return 0;


}