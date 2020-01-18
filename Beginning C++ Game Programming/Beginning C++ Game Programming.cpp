// Beginning C++ Game Programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

string jumbleWord(string);
void welcomePlayer(string);

int main()
{
	enum fields
	{
		WORD,
		HINT,
		NUM_FIELDS
	};

	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	srand(time(NULL));
	int choice = (rand() % NUM_WORDS);
	string word = WORDS[choice][WORD];
	string hint = WORDS[choice][HINT];

	string jumble = jumbleWord(word);

	welcomePlayer(jumble);

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != word) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			cout << hint;
		}
		else
		{
			cout << "Sorry, that's not it.";
		}

		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == jumble)
	{
		cout << "\nThat's it! You guessed it!\n";
	}

	cout << "\nThanks for playing.\n";

	return 0;
}

string jumbleWord(string word)
{
	string jumble = word;
	int length = jumble.size();

	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);

		char temp = jumble[index1];

		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	return jumble;
}

void welcomePlayer(string word)
{
	cout << "\t\t\tWelcome to Word Jumble!\n\n"
		<< "Unscramble the letters to make a word.\n"
		<< "Enter 'hint' for a hint.\n"
		<< "Enter 'quit' to quit the game.\n\n"
		<< "The jumble is: " << word;
}