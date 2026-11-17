#include <iostream>
#include<random>

#include"hangman.h"

int main()
{
	std::string someString = "alpha";

	char someLetter = 'l';

	int positionToStartTheSearchAt = 0;

	size_t locationOfLetter = someString.find(someLetter, positionToStartTheSearchAt);

	if (locationOfLetter != std::string::npos)
	{
		std::cout << "The letter '" << someLetter << "' is at index " << locationOfLetter << std::endl;
	
	}

	else
	{
		std::cout << "the letter was NOT found (and its index is: " << locationOfLetter << std::endl;
	}

	if(someString.find(someLetter))
	std::cout << "The letter '" << someLetter << "' is? at index " << someString.find(someLetter) << std::endl;
	playHangman();
}
	