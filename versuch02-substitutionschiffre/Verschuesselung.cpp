///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXII
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	int n;
	int i;
	string code = "";

	n = wort.length();

	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (wort[i] == schluessel[0][j])
			{
				code = code + schluessel[1][j];
			}
		}
	}

	return code;

	/*return wort;*/
}

string entschluesseln(char schluessel[2][26], string wort)
{	
	// Hier folgt Ihr Code
	int n;
	int i;
    string code = "";

	n = wort.length();

	for (i = 0; i < n; i++) 
	{
		
		for (int j = 0; j < 26; j++)
		{
			if (wort[i] == schluessel[1][j])
			{
				code += schluessel[0][j];
			}
	
		}
		
	}

	return code;
	/*return wort;*/
}

int main()
{
	// Hier folgt Ihr Code
	string word;
	string anonym = "";

	char schluessel[2][26] = { {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
							  {'Z', 'X', 'V', 'C', 'B', 'N', 'M', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'W', 'Q', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'} };

	cout << "Bitte geben Sie Ihr Wort: ";
	cin >> word;
	cout << " " << endl;

	anonym = verschluesseln(schluessel, word);

	string entschlus_s;
	entschlus_s = entschluesseln(schluessel, anonym);

	cout << "Ihr verschlueseltes Wort lautet: " << anonym << endl;
	cout << " " << endl;

	cout << "Ihr entschlueseltes Wort lautet: " << entschluesseln(schluessel, anonym) << endl;

	return 0;
}

