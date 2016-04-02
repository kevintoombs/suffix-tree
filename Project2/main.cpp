#include "suffixTree.cpp"

int main(int argc, char *argv[])
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


	//mST.printDFST();

	//cout << mST.s << endl;
	//mST.sigma.display();

	cin.ignore();
	return 0;


}