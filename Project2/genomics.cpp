#include "includes.h"

class Alphabet
{
public:
	class Symbol
	{
	public:
		char sym;
		Symbol *next = NULL;
		Symbol(char s)
		{
			this->sym = s;
		}
	};

	Symbol *rootDelimiter;
	Symbol *currentSymbol;
	string aString;

	Alphabet()
	{

	}
	Alphabet(char delimiter)
	{
		rootDelimiter = new Symbol(delimiter);
		currentSymbol = rootDelimiter;
	}
	void addSymbol(char newSymbol)
	{
		Symbol *sym = new Symbol(newSymbol);
		this->currentSymbol->next = sym;
		this->currentSymbol = sym;
	}
	void display()
	{
		display(rootDelimiter);
		cout << endl;
		cout << this->aString << endl;
	}
	void display(Symbol *sym)
	{
		cout << sym->sym << ",";
		if (sym->next)
		display(sym->next);
	}

	static Alphabet parseAlphabet(char *alphabetFile, char delimiter)
	{
		Alphabet a = Alphabet(delimiter);

		ifstream fin;
		fin.open(alphabetFile);

		string sym, line;
		stringstream iss;
		getline(fin, line, '\n');
		iss << line;
		a.aString = delimiter;
		while (getline(iss, sym, ' '))
		{
			a.aString.append(sym);
			a.addSymbol(sym[0]);
		}

		fin.close();
		return a;
	}
};

class Sequence
{
public:
	string seq;
	string header;

	static string Sequence::parseFasta(char *fastaFile)
	{
		string out;
		ifstream fin;
		fin.open(fastaFile);

		string seqHeader;
		getline(fin, seqHeader, '\n');

		while (fin.good())
		{
			string line;
			getline(fin, line, '\n');
			out += line;
		}

		fin.close();
		return out;
	}
};


