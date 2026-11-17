#pragma once

#include<vector>
#include<string>

//using namespace std;

std::vector<std::string>getAllDictionaryWords(std::string filename);

std::string pickRandomWord(std::vector<std::string> words);

void findAndReplace(std::string wordToGuess, std::string& placeholder, char characterToSearchFor);

void playHangman();