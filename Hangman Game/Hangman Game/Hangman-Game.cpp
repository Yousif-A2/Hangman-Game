#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<time.h>
using namespace std;

const int max_tries = 6; // number of try 
int Fill_Letter(char, string, string&);

string country_names[]{ // the list of country 
	"Saudi Arabia",
	"egypt",
	"kuwait",
	"qatar",
	"emirates",
	"bahrain",
	"india",
	"nepal",
	"pakistan",
	"oman",
};

int main() {
	// welcome the user 
	cout << "\t\t\tHangman Game";
	cout << " \n\n# Welcome to hangman game........ Guess country name.";
	cout << "\n\n# Each letter is represented by a star (*). ";
	cout << "\n\n# You have to type only one letter in one try. ";
	cout << "\n\n# You have " << max_tries << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// The funstion of pick random name of country from the country list
	string name;
	srand(time(NULL));
	int n = rand() % 10;
	name = country_names[n];

	// Initialize the secret word with the _ .
	string unknown_name(name.length(), '*');

	// loob to find out the name of country.
	int number_of_wrong_guess = 0;
	char letter;
	while (number_of_wrong_guess < max_tries)
	{
		cout << "\n\n" << unknown_name;
		cout << "\n\nGuess a letter of country name :";

		cin >> letter;			//Ger guess letter from the user
		
		if (Fill_Letter(letter, name, unknown_name) == 0)
		{
			cout << "\n\nWhoooops! The letter is not right!";
			number_of_wrong_guess++;
			cout << " You have " << max_tries - number_of_wrong_guess << " guess left.";
		}
			else
		{
			cout << "\nYou got a letter! Keep going!";
		}
		if (name == unknown_name)
		{
			cout << "\n\nCongratulations! You got the right name of the country\n";
			cout << "The name of the country is: " << name;
			cout << "\n\n\n";
			break;
		}
	}
	if (number_of_wrong_guess == max_tries) {
		cout << "\n\n Sorry, you lose...... you have been hanged!";
		cout << "\nThe name of country was: " << name;
		cout << "\n\n\n";
	}
	cin.ignore();
	cin.get();
}



// Function check if the letter include in the name of country.

int Fill_Letter(char guess_letter, string secret_word, string& unknown_name) {
	int matches = 0;
	int length = secret_word.length();
	for (int i = 0; i < length; i++)
	{
		if (guess_letter == unknown_name[i])		// Check if the letter already match before.
			return 0;

		if (guess_letter == secret_word[i])			// check if the letter on the name of country, then exhange the letter with STAR.
		{
			unknown_name[i] = guess_letter;
			matches++;
		}
	}
	return matches;
}