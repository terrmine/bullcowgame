#include <iostream>
#include <string>
#include "FBullsAndCows.h"

using FText = std::string;
using int32 = int;

FBullsAndCows BCGame; // instantiate a new game
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
// entry point
int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0;
}


// introduce the game
void PrintIntro() {

	
	std::cout << "Welcome to Bulls And Cows \n";
	std::cout << "can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram i'm thinking off?.";
	std::cout << "\n";
	return;
}



// play the game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText guess = GetValidGuess();


		FBullCowCount  BullCowCount = BCGame.SubmitGuess(guess);
		
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";

		return;
	}
}

		

// get the guess 
FText GetValidGuess() {
	EGuessStatus status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTries();

		// get a guess
		std::cout << "Try " << CurrentTry << ". enter your guess:";
		FText guess = "";
		std::getline(std::cin, guess);
		// check status and give feedback
		status = BCGame.CheckGuessValidity(guess);
		switch (status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "please enter an isogram word.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "please remove caps.\n";
			break;

		default:
			return guess;
		}
		std::cout << std::endl;
	}
	while (status != EGuessStatus::OK); // keep looping until we get no errors
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText response = "";
	std::getline(std::cin, response);
	return (response[0] == 'y') || (response[0] == 'Y');
}



