#pragma once

namespace TXTCrypter
{
	//Base class for all encryptions
	class Cipher
	{
	public:
		Cipher(char* filePath);
		~Cipher();

	protected:
		char* filePath = nullptr;
	};
}