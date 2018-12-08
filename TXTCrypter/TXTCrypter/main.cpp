#include <iostream>
#include <fstream>

enum ECipher
{
	Ceasar = 0
};


bool validateInput(int argc, char* argv[], ECipher& cipher);
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

	std::ofstream file;

	//Validate the file input
	if (!validateFile(argv[1]))
	{
		//Return error code to user and print error
		std::cout << "Invalid file path. Please check the file path input" << std::endl;
		return 2;
	}

	switch (cipher)
	{
	case Ceasar:

		break;
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

	return false;
}

bool validateFile(char * arg)
{
	std::fstream file(arg);
	if (file.is_open())
	{
		return true;
	}

	return false;
}
