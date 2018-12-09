#pragma once
#include "Cipher.h"

namespace TXTCrypter
{
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

		//Encrypts all the text from the loaded file
		void EncryptFile(int shiftIndex);
	};
}