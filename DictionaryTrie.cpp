#include "util.h"
#include "DictionaryTrie.h"
#include <stack>
#include <set>


/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie()
{	
	root = new MWTNode();
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
 if (word.empty())
 	return false;
 
 MWTNode* current = root;	
 bool added;

 for (auto character : word)
 {
 	int letter = (int) character;
 	if (letter == 32)
 		letter = 0;
 	else
 		letter -= 96;

 	if (!current->nodeVector.at(letter))  //if NULL 
 	{
 		current->nodeVector.at(letter) = new MWTNode(); 
 		current = current->nodeVector.at(letter); //updates current  		
 	}

 	else //if its not null, then that node already exists
 		current = current->nodeVector.at(letter); 		
 	
 } //end of for loop. done iterating through all chars in word

 if (current->finalVector) //if true, then the word already existed
 	added = false;
 else //false, then word did not exist before
 {
 	current->finalVector = true;
 	current->frequency = freq;
 	current->word = word;
 	added = true;
 } 	 	
  return added;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
 if (word.empty())
 	return false;

 MWTNode* current = root;
 bool found;	
 
 for (auto character : word)
 {
 	int letter = (int) character;
 	if (letter == 32)
 		letter = 0;
 	else
 		letter -= 96;

 	if (!current->nodeVector.at(letter))  //if NULL 
 		return false; // that means full word does not even exist

 	else //if its not null  
 		current = current->nodeVector.at(letter); 	
 }

 if (current->finalVector)
 	found = true;
 else
 	found = false;

  return found;
}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{

 
  std::vector<std::string> words; // this stores the vector of words that has to be returned
  std::multimap<int, std::string, std::greater<int>> prefixMap; // this stores the words 
  																//with its frequency

 if (prefix.empty())
	{
		std::cout << "Invalid string input. Please try again" << std::endl;
		return words; // should be empty here
	}

 // checks for correct symbol input of the prefix word
 for (char item : prefix)
  {
  	int letter = (int) item;
 	if (letter == 32)
 		letter = 0;
 	else
 		letter -= 96;

 	if (letter < 0 || letter >= 27)
 	{
 		std::cout << "Invalid symbol input. Please try again" << std::endl;
		return words; // should be empty here
 	}
 }

 findPrefix(prefix, prefixMap); // this should find the prefix of the set of words

 unsigned int num = 0;
  for(auto iterator = prefixMap.begin(); 
    (num < num_completions) && (iterator != prefixMap.end()); iterator++) 
  {
    
    words.push_back(iterator->second);
    num++;
  }

return words;

}

/*
  Finds the prefix of the set of the words if exists or else returns an 
  empty vector
 */
void DictionaryTrie::findPrefix(std::string prefix, 
				std::multimap<int, std::string, std::greater<int>> &prefixMap)
{
	MWTNode* current = root; // just assign the current to be the root 

	for (char item : prefix)
  {
  	int letter = (int) item;
 	if (letter == 32)
 		letter = 0;
 	else
 		letter -= 96;

 	if (current->nodeVector.at(letter) == NULL)
  		return; //  word will just be empty;
  	else
  		current = current->nodeVector.at(letter);
  }
 	
//at this point current should be pointing to the root of the DFS portion 

timeToGoDeep(current, prefixMap); // time to recursively traverse all the nodes 

}
/*
Use the same concept as post order depth traversal from destructor
We also understand this is an exhaustive search approach, better ways can be 
implemented like by storing info in the node regarding highest frequency word
of the particular subtree.
We used multimap because it was a BST and easy to store based on frequency
*/
void DictionaryTrie::timeToGoDeep(MWTNode* current, 
	std::multimap<int, std::string, std::greater<int>> &prefixMap)
{
	if (current) //if the node exists
	{
		for (auto item : current->nodeVector)
			timeToGoDeep(item, prefixMap); //keep going as deep as possible

		if (current->finalVector) //checks to see if node is a final word and adds it
			prefixMap.insert(std::pair<int, std::string>(current->frequency, current->word));
	}
}

/* Destructor */
DictionaryTrie::~DictionaryTrie()
{
	deleteAll(root); //calls the recursive function to remove all the nodes 
				           // using post order depth traversal
}

/*
  Private function called by the destructor 
 */
void DictionaryTrie::deleteAll(MWTNode* n)
{
   if (n != NULL)  //only execute when N exists 
  { 
  	for (auto item: n->nodeVector) // post order traversal
    	deleteAll(item); //recursive call to find deeper nodes
    delete n;
  }
}

