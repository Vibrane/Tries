/*
  * Abhinav Rana
  * U06971709
  * Anna Kaplan 
  * A99039352
  * DictionaryHashTable.cpp
  * The class for a dictionary ADT, implemented as a Hashtable
  * When you implement this class, you MUST use a Hashtable
  * in its implementation.  The C++ unordered_set implements 
  * a Hashtable, so we strongly suggest you use that to store 
  * the dictionary.
*/

#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H
#include <string>
#include <unordered_set>

class DictionaryHashtable
{
public:

  /* Create a new Dictionary that uses a Hashset back end */
  DictionaryHashtable();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryHashtable();

private:
  // Add your own data members and methods here
  
  std::unordered_set<std::string> myset;
  
  
};

#endif // DICTIONARY_HASHTABLE_H