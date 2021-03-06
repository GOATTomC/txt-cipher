#include <iostream>
#include <fstream>
#include "Ceasar.h"
#include "Vigenere.h"

//The choice of ciphers available to the user
enum ECipher
{
	Ceasar = 0,
	Vigenere
};

//Validates the input arguments
//parameters: int argc = amount of arguments,
//char* argv[] = the arguments,
//EChipher& cipher = OUT the cipher the user want to use
bool validateInput(int argc, char* argv[], ECipher& cipher);

//Validates the file path
//parameters: char* arg = the arg containing the file path
bool validateFile(char* arg);

//Entry point of the program
int main(int argc, char* argv[])
{
	ECipher cipher;

	//Validate the input from the user
	if (!validateInput(argc, argv, cipher))
	{
		//Return error code to user and print the wanted usage
		std::cout << "Invalid usage. Wanted usage: ./TXTCrypter.exe {filepath}.txt [Cipher] [Key]" << std::endl;
		return 1;
	}

	//Validate the file input
	if (!validateFile(argv[1]))
	{
		//Return error code to user and print error
		std::cout << "Invalid file path. Please check the file path input" << std::endl;
		return 2;
	}

	//Decide behaviour on chosen cipher
	switch (cipher)
	{
	case Ceasar:
	{
		TXTCrypter::Ceasar ceasar(argv[1]);
		ceasar.Encrypt(argv[3]);
		break;
	}
	case Vigenere:
	{
		TXTCrypter::Vigenere vigenere(argv[1]);
		vigenere.Encrypt(argv[3]);
		break;
	}
	default:
		break;
	}

	return 0;
}

bool validateInput(int argc, char* argv[], ECipher& cipher)
{
	//User want to use the Ceasar cipher
	if (strcmp(argv[2], "Ceasar") == 0 && argc == 4)
	{
		cipher = ECipher::Ceasar;
		return true;
	}
	else if (strcmp(argv[2], "Vigenere") == 0 && argc == 4)
	{
		cipher = ECipher::Vigenere;
		return true;
	}

	return false;
}

bool validateFile(char * arg)
{
	std::fstream file(arg);
	if (file.is_open())
	{
		return true;
	}
	file.close();

	return false;
}
