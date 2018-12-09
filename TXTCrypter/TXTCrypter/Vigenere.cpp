#include "Vigenere.h"

TXTCrypter::Vigenere::~Vigenere()
{
}

void TXTCrypter::Vigenere::Encrypt(char * key)
{
	//Load the text file
	ReadFile();

	//Encrypt the loaded text
	EncryptFile(key);

	//Write the encrypted text back to the text file
	WriteFile();

}

void TXTCrypter::Vigenere::EncryptFile(std::string key)
{
	LineNode* currentLine = p_FirstLine;

	do
	{
		std::string newLine;

		//Loop through all character
		for (int i = 0; i < currentLine->Line.length(); i++)
		{
			char keyChar = GetKeyChar(key, i);
			char newChar = GetCryptChar(currentLine->Line[i], keyChar);

			newLine += newChar;
		}

		currentLine->Line = newLine;
		currentLine = currentLine->NextLineNode;
	} while (currentLine != nullptr);
}

char TXTCrypter::Vigenere::GetKeyChar(std::string key, int index)
{
	int strLength = key.length();

	//Get the correct index if needed
	while (index >= strLength)
	{
		index -= strLength;
	}

	//return correct char
	return key[index];
}

char TXTCrypter::Vigenere::GetCryptChar(char currentChar, char keyChar)
{
	return 0;
}
