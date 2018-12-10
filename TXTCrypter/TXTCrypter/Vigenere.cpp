#include "Vigenere.h"
#include <iostream>

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
			std::cout << newChar << std::endl;
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
	int alphabetIndexCurrent = 0;
	int alphabetIndexKey = 0;

	//Get the index of the character in the alphabet
	isupper(currentChar) ? alphabetIndexCurrent = (currentChar - 65) : alphabetIndexCurrent = (currentChar - 97);
	isupper(keyChar) ? alphabetIndexKey = (keyChar - 65) : alphabetIndexKey = (currentChar - 97);

	//TODO fix lower case index bug
	
	int newIndex = alphabetIndexCurrent + alphabetIndexKey;

	//Get new index in alphabet
	while (newIndex > 25)
	{
		newIndex -= 26;
	}

	char newChar;

	//Get the new char in the correct case
	isupper(currentChar) ? newChar = 65 + newIndex : newChar = 97 + newIndex;

	return newChar;
}
