/*
  * Abhinav Rana
  * U06971709
  * Anna Kaplan 
  * A99039352
  * DictionaryTrie.cpp
  * The class for a dictionary ADT, implemented as a trie
  * You may implement this class as either a mulit-way trie
  * or a ternary search trie, but you must use one or the other.
  *
*/

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H
#include <vector>
#include <string>
#include <map>
 struct MWTNode
  {
     std::vector<MWTNode*> nodeVector = {NULL, NULL, NULL, NULL, NULL, NULL, NULL,
     NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
     NULL, NULL, NULL, NULL, NULL, NULL, NULL}; 
     bool finalVector = false;
     unsigned int frequency = 0;
     std::string word;
  };

class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

private:
  // Add your own data members and methods here  
   MWTNode* root;

   void deleteAll(MWTNode*);
   void findPrefix(std::string, std::multimap<int, std::string, std::greater<int>>&);
   void timeToGoDeep(MWTNode*, std::multimap<int, std::string, std::greater<int>>&);

};
#endif

