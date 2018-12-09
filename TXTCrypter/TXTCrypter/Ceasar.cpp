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

	ReadFile();

	EncryptFile(shiftIndex);
	
	WriteFile();

}

void TXTCrypter::Ceasar::ReadFile()
{
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
}

void TXTCrypter::Ceasar::EncryptFile(int shiftIndex)
{
	LineNode* currentLine = p_FirstLine;

	//Encrypt all the lines
	do
	{
		std::string newString;

		//Loop through all characters in string
		for (int i = 0; i < currentLine->Line.length(); i++)
		{
			//Get the current char info from the string
			int currentCharCode = currentLine->Line[i];
			bool isUpperChar = isupper(currentCharCode);

			//If character is space place space in encryption and skip to next character
			if (currentCharCode == 32)
			{
				newString += " ";
				continue;
			}
			//If the character is not an alphabetic skip to the next character
			else if (!isalpha(currentCharCode))
			{
				continue;
			}

			//Add the alphabet shift
			currentCharCode += shiftIndex;

			if (isUpperChar)
			{
				//If it's not in the capital alphabet anymore
				while (currentCharCode > 90)
				{
					currentCharCode -= 25;
				}
			}
			else if (!isUpperChar)
			{
				while (currentCharCode > 122)
				{
					currentCharCode -= 25;
				}
			}

			newString += (char)currentCharCode;
		}

		currentLine->Line = newString;
		currentLine = currentLine->NextLineNode;


	} while (currentLine != nullptr);
}

void TXTCrypter::Ceasar::WriteFile()
{
	//Write encryption to file
	LineNode* currentLine = p_FirstLine;

	std::ofstream outFile(filePath);
	if (outFile.is_open())
	{
		do
		{
			outFile << currentLine->Line << std::endl;
			currentLine = currentLine->NextLineNode;
		} while (currentLine != nullptr);
	}
	outFile.close();
}
