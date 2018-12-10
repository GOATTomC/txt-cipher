#include "Cipher.h"
#include <fstream>

TXTCrypter::Cipher::Cipher(char * filePath)
{
	this->filePath = filePath;
}

TXTCrypter::Cipher::~Cipher()
{
	Unload(p_FirstLine);
}

void TXTCrypter::Cipher::ReadFile()
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

void TXTCrypter::Cipher::WriteFile()
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

void TXTCrypter::Cipher::Unload(LineNode * line)
{
	if (line == nullptr)
	{
		return;
	}

	Unload(line->NextLineNode);
	delete line;
}
