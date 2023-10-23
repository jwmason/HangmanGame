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



bool HangmanGame::guessLetter(char guess)
{

    // TODO implement me.
    // Create a copy of current pattern to see if the guess letter was correct or not
    std::string orig_pattern = pattern;
    // Loop through WordList wordsRemaining and update the pattern
    for (unsigned i = 0; i < wordsRemaining.getSize(); ++i)
    {}
    return false;
}


const std::string & HangmanGame::getPattern()
{
    return pattern; 
}

size_t HangmanGame::possibleWordsRemaining() const
{
    return wordsRemaining.getSize();
}

