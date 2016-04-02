#include "suffixTree.cpp"

int main(int argc, char *argv[])
{

	string inputString = Sequence::parseFasta(argv[1]);
	//cout << inputString << endl;

	Alphabet a = Alphabet::parseAlphabet(argv[2], '$');
	//a.display();

	McSuffixTree mST(inputString, a);
	//cout << mST.s << endl;
	mST.sigma.display();
	mST.BWT();


	cin.ignore();
	return 0;
}