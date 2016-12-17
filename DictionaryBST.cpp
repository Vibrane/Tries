/** 
  * Abhinav Rana
  * U06971709
  * Anna Kaplan 
  * A99039352
  * DictionaryBST.cpp
  *  The class for a dictionary ADT, implemented as a BST
  * When you implement this class, you MUST use a balanced binary
  * search tree in its implementation.  The C++ set implements 
  * a balanced BST, so we strongly suggest you use that to store 
  * the dictionary.
  */

#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
	return myset.insert(word).second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
	std::set<std::string>::const_iterator got = myset.find(word);

	if (got == myset.end())
		return false;
	else
		return true;
}

/* Destructor */
DictionaryBST::~DictionaryBST()
{
	// no need to because stl automatically takes care of it
}
