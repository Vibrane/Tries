/*
  * Abhinav Rana
  * U06971709
  * Anna Kaplan 
  * A99039352
  * test.cpp
  * Just does some basic testing of the DictionaryTrie
*/

#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<fstream>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{
  //Initialize words
  vector<std::string> words;
  vector<std::string> predictWords;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harr y");
  words.push_back("sriram");
  words.push_back("c se");
  words.push_back("crucio");
  words.push_back("aut ocomplete");
  words.push_back("autocom plete");
  words.push_back("cat");
  words.push_back("cats");
  words.push_back("california");
  words.push_back("tennis");
  words.push_back("catalog");

    
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
      {
        cout << "failed for DictionaryBST... ";
        return 0;
      }

      if(!t_ht)
	   {
	       cout << "failed for DictionaryHashset... ";
         return 0;
	   }
      if(!tt)
	   {
	       cout << "failed for DictionaryTrie... ";
         return 0;
	   }
      if(t_bst && t_ht && tt)
	   {
	       cout << "PASSED! :D ";
	   }
      cout << endl;
    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";\
          return 0;
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  
/*You are supposed to add more test cases in this file */

  for (auto item : words)
  {
    cout << "Finding word " << item << endl;
    if (!d_bst.find(item))
    {
      cout << "Failed to find in bst: " << item << endl;
      return 0;
    }

    if (!d_ht.find(item))
    {
      cout << "Failed to find in hash table: " << item << endl;
      return 0;
    }

     if (!dt.find(item))
    {
      cout << "Failed to find in dictionary trie: " << item << endl;
      return 0;
    }

  }


  predictWords = dt.predictCompletions("a" , 3);

  if (predictWords.empty())
    cout << "Empty Vector";

  else
  {
    for (auto item : predictWords)
      cout << item << ", "; 
    cout << endl;
  }


  cout << "Time for the super test " << endl;

  DictionaryTrie dictTrie;
  ifstream in;

  in.open("freq_dict.txt");
  Utils::load_dict(dictTrie, in);
  in.close();

predictWords.clear();
predictWords = dictTrie.predictCompletions("a" , 100);

for (auto item : predictWords)
  cout << item << endl;


  
  
  return 0;
}
