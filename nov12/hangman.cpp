#include"hangman.h"

#include<fstream>
#include<iostream>
#include<random>

std::vector<std::string>getAllDictionaryWords(std::string filename)
{
	std::vector<std::string> words;

	std::ifstream fin(filename);

	if (fin.is_open() == false)
	{
		std::cout << "Could not find the file " << filename << std::endl;
		return{};
	}

	std::string currentWord;

	while (std::getline(fin, currentWord))
	{
		words.push_back(currentWord);
	}

	std::cout << "The number of words is: " << words.size() << std::endl;
	return words;

}
std::string pickRandomWord(std::vector<std::string> words)
{
	std::string randomWord;

	std::mt19937 rng(std::random_device{}());

	std::uniform_int_distribution<int> distribution(0, words.size() - 1);

	int randomIndex = distribution(rng);

	randomWord = words[randomIndex];

	return randomWord;
}

void findAndReplace(std::string wordToGuess, std::string& placeholder, char characterToSearchFor)
{

	for (int location = 0; location < wordToGuess.size(); ++location)
	{
		if (wordToGuess[location] == characterToSearchFor)
		{
			placeholder[location] = characterToSearchFor;
			std::cout << "correct!" << std::endl;
		}
		else
		{
			std::cout << "The character " << characterToSearchFor;
		}

	}
  




}
std::string generatePlaceholder(std::string wordToGuess)
{
	std::string placeholder;
	for (int i = 0; i < wordToGuess.size(); ++i)
	{
		placeholder.push_back('*');
	}
	return placeholder;
}



void playHangman()
{
	std::string absoluteFilepath = "C:\\Users\\Download\\source\\popular.txt";
	std::vector<std::string> dictionaryWords = getAllDictionaryWords(absoluteFilepath);

	std::string wordToGuess = pickRandomWord(dictionaryWords);
	std::string placeholder = generatePlaceholder(wordToGuess);

	
	std::cout << "If you are a cheater here is the word to guess: " << wordToGuess << std::endl;
	std::cout << "The word to guess is: " << placeholder << std::endl;

	int maxGuessesAllowed = placeholder.size();

	int currentNumberOfGuesses = 0;

	for (int i = 0; i < wordToGuess.size(); ++i)
	{
		placeholder.push_back('*');
	}

	while (placeholder != wordToGuess)
	{
		char guessedCharacter;
		std::cout << "Guess a letter: " << std::endl;
		std::cin >> guessedCharacter;

		std::cin >> guessedCharacter;

		findAndReplace(wordToGuess, placeholder, guessedCharacter);
	}

	if (currentNumberOfGuesses >= maxGuessesAllowed)
	{
		std::cout << "You lose!" << std::endl;
	}
	
}   


	
