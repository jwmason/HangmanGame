#include <string>
#include "WordList.hpp"


// Note:  in the definition, we do not specify that initialCapacity has a default value a second time.
// The word 'explicit' is also not repeated here. 
WordList::WordList(size_t initialCapacity)
: m_words{new std::string[ initialCapacity ]}, m_capacity{ initialCapacity }, m_numWords{ 0 }
{

}
    
    
// The destructor is important.  Memory management of the word list is 1.5 points out of 9 on this project
// and it is mostly (but not entirely) within this function.
// Think very carefully about what you do here. 
    
WordList::~WordList()
{
    // TODO implement me.
}    
    
void WordList::addWord(const std::string & s)
{
    // TODO implement me.
}
    
bool WordList::removeWord(size_t index)
{
    // TODO implement me.
    return false;
}

    
std::string & WordList::wordAt(size_t index)
{
    // TODO implement me.
}

const std::string & WordList::wordAt(size_t index) const
{
    // TODO implement me.
}


size_t WordList::getCapacity() const
{
    return m_capacity;
}


size_t WordList::getSize() const
{
    return m_numWords;
}
    

    
    