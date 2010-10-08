#include <set>
#include <fstream>
#include <iostream>

#include "utf8_decode.h"

std::set<int> getCharacters(char* filename)
{
	std::set<int> chars;

	std::ifstream file;
	file.open(filename, std::ios::in);

	std::string string;

	if(!file.is_open())
	{
		std::cout << "Failed to open file: '" << filename << "'" << std::endl;
		return chars;
	}

	//read the file
	while(!file.eof())
	{
		std::getline(file, string);

		// this loop gets each character in the line as an int
		utf8_decode_init((char*)string.c_str(), string.length());

		int character = utf8_decode_next();

		while(character > 0) // no errors or end of string
		{
			// save it to the set
			chars.insert(character);

			character = utf8_decode_next();			
		}
	}

	file.close();

	return chars;
}


int main(int argv, char** argc)
{
	if(argv > 0)
	{
		// get the characters used
		std::set<int> chars = getCharacters(argc[1]);

		// for debuging print out the characters used
		for(std::set<int>::iterator itr = chars.begin(); itr != chars.end(); itr++)
		{
			std::cout << (*itr) << std::endl;
		}
	}

	return 0;
}
