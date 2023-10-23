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
    // Check if there is space in m_capacity. If not, double the size
    if (m_numWords >= m_capacity)
    {
        // Double the capacity
        size_t newCapacity = m_capacity * 2;
        // Create a new array with the new capacity
        std::string * newArray = new std::string[newCapacity];
        // Loop through the old array and update the new one with every word
        for (unsigned i = 0; i < m_numWords; ++i)
        {
            newArray[i] = m_words[i];
        }
        // Delete old array
        delete [] m_words;
        // Update WordList with new array and capacity
        m_words = newArray;
        m_capacity = newCapacity;
    }
    // If capacity needs to be updated or not, add new word to array
    m_words[m_numWords] = s;
    m_numWords ++;
}
    
bool WordList::removeWord(size_t index)
{
    // TODO implement me.
    return false;
}

    
std::string & WordList::wordAt(size_t index)
{
    // Return word from WordList at index
    return m_words[index];
}


const std::string & WordList::wordAt(size_t index) const
{
    // Return word from WordList at index
    return m_words[index];
}


size_t WordList::getCapacity() const
{
    return m_capacity;
}


size_t WordList::getSize() const
{
    return m_numWords;
}
    

    
    