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
		void Encrypt();
	};
}