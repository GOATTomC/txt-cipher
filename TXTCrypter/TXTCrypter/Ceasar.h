#pragma once
#include "Cipher.h"
#include <string>

namespace TXTCrypter
{
	//Linked list to store the lines from the file
	struct LineNode
	{
	public:
		std::string Line;
		LineNode* NextLineNode = nullptr;
	};

	//Class used for Ceasar encryptions
	class Ceasar : public Cipher
	{
	public:
		Ceasar(char* filePath) : Cipher(filePath){}
		~Ceasar();

		//Encrypts the file passed into it's constructor
		//Parameters: char* key = the key for the encryption (this case shift index)
		void Encrypt(char* key);

	private:
		LineNode* p_FirstLine = nullptr;
	};
}