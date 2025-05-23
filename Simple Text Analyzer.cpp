#include <iostream>
#include <string> 
#include <limits>
#include <cctype>

void printWelcome()
{
    std::cout << "Welcome to the Simple Text Analyzer!\n";
    std::cout << "This program will analyze the text you provide and give you some statistics about it.\n";
}

void getText(std::string& text)
{
	std::cout << "Please enter the text you want to analyze (type 'exit' to quit):\n";
	std::getline(std::cin, text);
}

void analyzeText(const std::string& text, int& letterCount, int& digitCount, int& gapCount) {
	if(text == "exit"){
		std::cout << "Exiting the program.\n";
		exit(0);
	}
	else {
		if (text.empty()) {
			std::cout << "No text provided.\n";
			return;
		}
		else {
			for(char ch : text) {
				if (std::isalpha(ch)) {
					letterCount++;
				}
				else if (std::isdigit(ch)) {
					digitCount++;
				}
				else if (std::isspace(ch)) {
					gapCount++;
				}
			}
			std::cout << "Analysis Results:\n";
			std::cout << "Number of letters: " << letterCount << "\n";
			std::cout << "Number of digits: " << digitCount << "\n";
			std::cout << "Number of gap marks: " << gapCount << "\n";
			std::cout << "Total characters: " << text.length() << "\n";
		} 
	}
}



void askContinue(std::string& continueChoice)
{
	std::cout << "Do you want to analyze another text? (yes/no): ";
	std::cin >> continueChoice;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	
	std::string text;
	int letterCount = 0;
	int digitCount = 0;
	int gapsCount = 0;
	std::string continueChoice;


	printWelcome();
	do
	{
		getText(text);
		analyzeText(text, letterCount, digitCount, gapsCount);
		askContinue(continueChoice);
	} while (continueChoice == "y" || continueChoice == "Y");
}

