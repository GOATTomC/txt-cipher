#pragma once
#include "Cipher.h"

namespace TXTCrypter
{
	class Vigenere : public Cipher
	{
	public:
		Vigenere(char* filePath) : Cipher(filePath) {}
		~Vigenere();

		void Encrypt(char* key);

	private:
		//Encrypts all the text from the loaded file
		void EncryptFile(std::string key);

		//Returns the character to use from the key
		char GetKeyChar(std::string key, int index);

		//Returns the encrypted char
		char GetCryptChar(char currentChar, char keyChar);
	};
}