/** 
  * Abhinav Rana
  * U06971709
  * benchdict.cpp
  * This program is used to run a benchmark
  * that compares the different find
  * methods implementations in the BST, 
  * Hashtable & Trie dictionaries.
  */

#include "util.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

std::vector<std::string> loadingVector(istream&, unsigned int); //loads the words into this
  
//function tests DictionaryTrie find method 
void testTrie(unsigned int, unsigned int, unsigned int, std::string); 

//function tests DictionaryBST find method
void testBST(unsigned int, unsigned int, unsigned int, std::string);

//function tests DictionaryHash find method
void testHash(unsigned int, unsigned int, unsigned int, std::string);

int main(int argc, char* argv[]) {
  // Check for arguments
    
  if(argc != 5) 
  {
    std::cout << "Invalid number of arguments." << std::endl;
    std::cout << "Usage: ./benchdict minSize stepSize iterations dictionary" << std::endl;
    return -1;
  }
 
  // Calls the different dictionary tests.
  testTrie(atoi(argv[1]),atoi(argv[2]), atoi(argv[3]), argv[4]);
  testBST(atoi(argv[1]),atoi(argv[2]), atoi(argv[3]), argv[4]);
  testHash(atoi(argv[1]),atoi(argv[2]), atoi(argv[3]), argv[4]);
}

  // This method calls all corresponding tests for the MWT dictionary 
  
  void testTrie(unsigned int minSize, unsigned int stepSize, unsigned int iterations,
              std::string dictionaryFile) {

  std::vector<std::string> results;
  std::vector<long long> times;
  long long duration;
  long long sum = 0;  
  Timer TimeWizard;  // had to make a reference to Yu-Gi-Oh  

  // Display title
  std::cout << "DictionaryTrie:" << std::endl;

  // Open a stream to read input file
  std::ifstream ifs;
  std::vector<std::string> allWords; //loads all the required words here
  std::vector<std::string> noWords; // has the 
  DictionaryTrie* dictTrie;


  ifs.open(dictionaryFile);

  // Find average times
  for (unsigned i = 0; i < iterations; i++) {

    dictTrie = new DictionaryTrie();
    //loading dictionary
    allWords = loadingVector(ifs, (minSize+(i*stepSize)) + 100);
    
    if (allWords.size() < (minSize+(i*stepSize)))
     std::cout << "WARNING: There are fewer than the required number of words" << std::endl;
   
    for (int j = 0; j < (minSize+(i*stepSize)); j++)
      dictTrie->insert(allWords[j], 0);

    for (int k = (minSize+(i*stepSize)); k < allWords.size(); k++)
      noWords.push_back(allWords[k]);
    
    /* timing 100 finds that are not in the dictionary */
    for (auto item : noWords) {
      TimeWizard.begin_timer();
      dictTrie->find(item);
      times.push_back(TimeWizard.end_timer());
    }

    for (auto item : times) 
      sum += sum + item;
    
    duration = (sum/times.size());
                 
    // Print the results
    std::cout << ((minSize)+(i*stepSize)) << "\t" << duration  << std::endl;

    delete dictTrie;
    allWords.clear();
    noWords.clear();
  }

  std::cout << std::endl;

  
} // end of function 

/* This method calls all corresponding tests for the BST dictionary */

void testBST(unsigned int minSize, unsigned int stepSize, unsigned int iterations,
              std::string dictionaryFile) {

  std::vector<std::string> results;
  std::vector<long long> times;
  long long duration;
  long long sum = 0;
  Timer TimeWizard;

  // Display title
  std::cout << "DictionaryBST:" << std::endl;

  // Open a stream to read input file
  std::ifstream ifs;
  std::vector<std::string> allWords; //loads all the required words here
  std::vector<std::string> noWords; // has the 
  DictionaryBST* dictBST;

  ifs.open(dictionaryFile);

  // Find average times
  for (unsigned i = 0; i < iterations; i++) {

    dictBST = new DictionaryBST();
    //loading dictionary
    allWords = loadingVector(ifs, (minSize+(i*stepSize)) + 100);
    if (allWords.size() < (minSize+(i*stepSize)))
     std::cout << "WARNING: There are fewer than the required number of words" << std::endl;
   
    for (int j = 0; j < (minSize+(i*stepSize)); j++)
      dictBST->insert(allWords[j]);

    for (int k = (minSize+(i*stepSize)); k < allWords.size(); k++)
      noWords.push_back(allWords[k]);
    
    /* timing 100 finds that are not in the dictionary */
    for (auto item : noWords) {
      TimeWizard.begin_timer();
      dictBST->find(item);
      times.push_back(TimeWizard.end_timer());
    }

    for (auto item : times) 
      sum += sum + item;
    
    duration = (sum/times.size());
                 
    // Print the results
    std::cout << ((minSize)+(i*stepSize)) << "\t" << duration  << std::endl;

    delete dictBST;
    allWords.clear();
    noWords.clear();
  }

  std::cout << std::endl;
}


 //This method calls all corresponding tests for the Hashtable dictionary 
void testHash(unsigned int minSize, unsigned int stepSize, unsigned int iterations,
              std::string dictionaryFile) {

  std::vector<std::string> results;
  std::vector<long long> times;
  long long duration;
  long long sum = 0;
  Timer TimeWizard;

  // Display title
  std::cout << "DictionaryHashtable:" << std::endl;

  // Open a stream to read input file
  std::ifstream ifs;
  std::vector<std::string> allWords; //loads all the required words here
  std::vector<std::string> noWords; // has the 
  DictionaryHashtable* dictHash;


  ifs.open(dictionaryFile);

  // Find average times
  for (unsigned i = 0; i < iterations; i++) {

    dictHash = new DictionaryHashtable();
    //loading dictionary
    allWords = loadingVector(ifs, (minSize+(i*stepSize)) + 100);
    if (allWords.size() < (minSize+(i*stepSize)))
      std::cout << "WARNING: There are fewer than the required number of words" << std::endl;
   
    for (int j = 0; j < (minSize+(i*stepSize)); j++)
      dictHash->insert(allWords[j]);

    for (int k = (minSize+(i*stepSize)); k < allWords.size(); k++)
      noWords.push_back(allWords[k]);
    
    /* timing 100 finds that are not in the dictionary */
    for (auto item : noWords) {
      TimeWizard.begin_timer();
      dictHash->find(item);
      times.push_back(TimeWizard.end_timer());
    }

    for (auto item : times) 
      sum = sum + item;
    
    duration = (sum/times.size());
                 
    // Print the results
    std::cout << ((minSize)+(i*stepSize)) << "\t" << duration  << std::endl;

    delete dictHash;
    allWords.clear();
    noWords.clear();
  }

  std::cout << std::endl;
  
}

//loads the words into the all words vector
 
std::vector<std::string> loadingVector(istream& words, unsigned int num_words)
{
  std::vector<std::string> dict;
  string junk;
  string data = "";
  string temp_word = "";
  string word = "";
  vector<string> word_string;
  unsigned int i = 0;
  unsigned int j = 0;

  for(; j < num_words; j++)
    {
      getline(words, data);
      if(words.eof()) break;
      temp_word = "";
      word = "";
      data = data + " .";
      std::istringstream iss(data);
      iss >> junk;
      while(1)
        {
          iss >> temp_word;
          if(temp_word == ".") break;
          if(temp_word.length() > 0) word_string.push_back(temp_word);
        }
      for(i = 0; i < word_string.size(); i++)
        {
          if(i > 0) word = word + " ";
          word = word + word_string[i];
        }
      dict.push_back(word);
      word_string.clear();
    }
    
    return dict;
}



