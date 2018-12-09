#pragma once
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

	//Base class for all encryptions
	class Cipher
	{
	public:
		Cipher(char* filePath);
		~Cipher();

	protected:
		char* filePath = nullptr;
		LineNode* p_FirstLine = nullptr;

		//Reads the file and stores the input
		void ReadFile();

		//Writes the encrypted text back to the txt file
		void WriteFile();


	};
}