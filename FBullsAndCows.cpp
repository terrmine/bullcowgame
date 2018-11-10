#include "FBullsAndCows.h"
using int32 = int;
FBullsAndCows::FBullsAndCows() {
	Reset();
}


void FBullsAndCows::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	
	return;
}



int32 FBullsAndCows::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}


int32 FBullsAndCows::GetMaxTries() const { return MyMaxTries; }


int32 FBullsAndCows::GetCurrentTries() const
{
	return MyCurrentTry;
}

bool FBullsAndCows::IsGameWon() const
{
	return false;
}

EGuessStatus FBullsAndCows::CheckGuessValidity(FString guess) const 
{
	if (false) {
		return EGuessStatus::Not_Isogram;   //return error if the eord isnt an isogram
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;  // return error if the word is in caps
	}
	else if (guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;  //return error if the word isnt the same length
	}
	else { return EGuessStatus::OK; }
}


FBullCowCount FBullsAndCows::SubmitGuess(FString guess)
{
	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 HIDDENWORDLENGHT = MyHiddenWord.length();

	for (int32 MHWChar = 0; MHWChar < HIDDENWORDLENGHT; MHWChar++) {
	
		for (int32 GChar = 0; GChar < HIDDENWORDLENGHT; GChar++) {

			if (guess[GChar] == MyHiddenWord[MHWChar]) {

				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else { BullCowCount.Cows++; }
			}


		}
}
	return BullCowCount;
}
