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
    // Delete array to allocate memory
    delete[] m_words;
}
    
void WordList::addWord(const std::string & s)
{
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
        delete[] m_words;
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
    // Check if index is in bounds. If not, return false
    if (index >= m_numWords)
    {
        return false;
    }
    // Remove the word from WordList at given index
    // Use a loop that starts at index, moving each word one position to the left
    // to replace at given index and fill the "hole" simultaneously
    for (unsigned i = index; i < m_numWords - 1; ++i)
    {
        m_words[i] = m_words[i + 1];
    }
    // Decrement m_numWords and return true
    m_numWords --;
    return true;
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
    

    
    