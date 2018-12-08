#include "Ceasar.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>

TXTCrypter::Ceasar::~Ceasar()
{
}

void TXTCrypter::Ceasar::Encrypt(char* key)
{
	//TODO add is digit check on key

	//Convert the argument to an integer
	int shiftIndex = atoi(key);

	//Read all current text from .txt file
	p_FirstLine = new LineNode();
	LineNode* currentLine = p_FirstLine;
	std::ifstream inFile(filePath);
	if (inFile.is_open())
	{
		while (std::getline(inFile, currentLine->Line))
		{
			LineNode* newLine = new LineNode();
			currentLine->NextLineNode = newLine;
			currentLine = newLine;
		}
	}
	inFile.close();

	//Encrypt all the lines

}
