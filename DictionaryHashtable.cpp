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

#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
 	return myset.insert(word).second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
	std::unordered_set<std::string>::const_iterator got = myset.find(word);

	if (got == myset.end())
		return false;
	else
		return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable()
{
	// no need to because stl automatically takes care of it
}
