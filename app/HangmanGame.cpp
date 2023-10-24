#include "HangmanGame.hpp"
#include <iostream>
#include <string>
#include <sstream>


HangmanGame::HangmanGame(std::istream &in, unsigned wordSize)
: wordsRemaining{}, pattern{""}
{
    std::string line, word;
    std::stringstream ss;

    while(  getline(in, line) )
    {
        ss.clear();
        ss << line;
        while( ss >> word )
        {
            if( word.size() == wordSize)
            {
                wordsRemaining.addWord( word );
            }
        }
    }
    for(unsigned i{0}; i < wordSize; i++)
    {
        pattern += "-"; 
    }
    // There are better ways to do that.

}



// This function WILL NOT be used in testing your program.
// You are welcome to make changes to it if you want.
// HOWEVER, IF THIS CAUSES YOUR PROGRAM TO NOT COMPILE, WE WILL BE UNABLE TO GRADE IT
void HangmanGame::playGame()
{
    // set this to true and re-build to have it run with showing all possible words remaining.
    // CAUTION:  YOU MIGHT NOT WANT TO DO THIS WITH LARGE WORD LISTS!
    constexpr bool SHOW_WORDS_REMAINING = false; 


    // the game ends when the player has guessed the word -- no dashes remain.
    while( pattern.find('-') != std::string::npos )
    {
        std::cout << "Pattern: " <<  getPattern() << std::endl;
        std::cout << "Guess a letter: ";
        char guess;
        std::cin >> guess;
        guessLetter( guess );
        if( SHOW_WORDS_REMAINING )
        {
            std::cout << "\tWords Remaining: " << std::endl;
            std::cout << "\t-----------------" << std::endl;
            for(size_t k{0}; k < wordsRemaining.getSize(); k++)
            {
                std::cout << "\t" << wordsRemaining.wordAt(k) << std::endl;
            }
            std::cout << "\t-----------------" << std::endl;
        }
    }

    std::cout << "You are right, the word was " << getPattern() << std::endl;
} 


bool HangmanGame::guessLetter(char guess) {
    // Create an array of WordList objects to represent different word families
    // Set the first word of each WordList in wordFamilies to be the pattern
    WordList* wordFamilies = new WordList[wordsRemaining.getSize()];

    // Iterate through the words in wordsRemaining
    for (unsigned i = 0; i < wordsRemaining.getSize(); ++i)
    {
        // Get word at index
        std::string word = wordsRemaining.wordAt(i);
        // Initialize pattern holder for word
        std::string famPattern = pattern;

        // Loop through char in word and check if guess char is in word
        for (unsigned j = 0; j < word.length(); ++j)
        {
            // Check if char is in word
            if (word[j] == guess)
            {
                // If it is, update the famPattern for the word
                famPattern[j] = guess;
            }
        }

        // Initialize a bool value to see if word belongs to existing family
        bool hasFam = false;

        // Put word in WordList Family with matching pattern
        // Loop through all possible families (maximum if each word is in a different family)
        for (unsigned k = 0; k < wordsRemaining.getSize(); ++k)
        {
            // Check if famPattern matches any existing families
            if (famPattern == wordFamilies[k].wordAt(0))
            {
                // Add word and break
                wordFamilies[k].addWord(word);
                hasFam = true;
                break;
            }
        }

        // If doesn't have a family, create a new one
        if (!hasFam)
        {
            // Loop through wordFamilies to find an empty family
            for (unsigned l = 0; l < wordsRemaining.getSize(); ++l)
            {
                // Check if the family is empty
                if (wordFamilies[l].getSize() == 0)
                {
                    // Initilize the family with pattern and first word then break
                    wordFamilies[l].wordAt(0) = word;
                    wordFamilies[l].addWord(famPattern);
                    break;
                }
            }
        }
    }

    // Find the largest family and delete the rest
    // Initialize holding variables
    unsigned largestFamSize = 0;
    unsigned largestFamIndex = 0;

    // Loop through every family
    for (unsigned i = 0; i < wordFamilies->getSize(); ++i)
    {
        // If the current family size is greater that current largest
        if (wordFamilies[i].getSize() > largestFamSize)
        {
            largestFamSize = wordFamilies[i].getSize();
            largestFamIndex = i;
        }
    }

    // Delete old wordsRemaining
    wordsRemaining.~WordList();    

    // Update wordsRemaining WordList and new pattern
    wordsRemaining = wordFamilies[largestFamIndex];
    pattern = wordFamilies[largestFamIndex].wordAt(0);

    // Delete the WordList of WordLists
    delete [] wordFamilies;

    // Returns true if player got a character, false if not
    return pattern.find(guess) != std::string::npos;
}


const std::string & HangmanGame::getPattern()
{
    return pattern; 
}

size_t HangmanGame::possibleWordsRemaining() const
{
    return wordsRemaining.getSize();
}

