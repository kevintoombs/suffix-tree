#include "suffixTree.cpp"


int main(int argc, char *argv[])
{

	std::string inputString = Sequence::parseFasta(argv[1]);
	std::cout << inputString << std::endl;

	Alphabet a = Alphabet::parseAlphabet(argv[2], '$');
	a.display();

	McSuffixTree mST(inputString, a);
	//McSuffixTree mST();
	//cout << mST.s << endl;
	//mST.sigma.display();
	//mST.printDFST();



	std::cin.ignore();
	return 0;
}