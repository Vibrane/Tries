/** 
  * Abhinav Rana
  * U06971709
  * Anna Kaplan 
  * A99039352
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
  
unsigned int hashOne(std::string, unsigned int);
unsigned int hashTwo(std::string, unsigned int);

/* Global variables */


int main(int argc, char* argv[]) {
  // Check for arguments
  
  if(argc != 3) {
    std::cout << "Invalid number of arguments." << std::endl;
    std::cout << "Usage: ./benchhash dictfile num_words " << std::endl;
    return -1;
  }

  unsigned int num_words = atoi(argv[2]);

  std::vector<std::string> dict;
  std::ifstream words;
  words.open(argv[1]);

  unsigned int freq;
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
      iss >> freq;
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
    } // done with loading words


    string tempWord;
    int hashTableOne[2 * num_words];
    int h1;
    int hashTableTwo[2 * num_words];
    int h2;

    for (int i = 0; i < 2 * num_words; i++)
    {
      hashTableOne[i] = -1;
      hashTableTwo[i] = -1;
    }

  for (int i = 0; i < num_words; i++)
  {
    tempWord = dict[i]; // gets the word from the file 

    h1 = hashOne(tempWord, 2 * num_words);
    hashTableOne[h1]++;

    h2 = hashTwo(tempWord, 2 * num_words);
    hashTableTwo[h2]++;

  }   


  int hashOneHits[500]; // keeps track of the collisions
  std::vector<int> hashOneVector;
  

  //updates -1 collisions to be 0, to show that no collisions happened there
  for (int counter = 0; counter < 2 * num_words; counter++)
  {
    if (hashTableOne[counter] == -1)
        hashTableOne[counter]++;
    int x = hashTableOne[counter];
    hashOneHits[x]++;
  }

  std::cout << "Printing the statistics for hashFunction1 with hash table size: "
            << 2 * num_words << std::endl << std::endl << "#hits \t" 
            << "#slots receiving the #hits" <<std::endl << std::endl;

  std::vector<std::pair<int,int>> hashOnePair;
  for (int counter = 0; counter < 500; counter++)
      if (hashOneHits[counter] > 0)
        std::cout << counter << "\t" << hashOneHits[counter] << std::endl;
        
      
  for (int counter = 499; counter >= 0; counter--)
    if (hashOneHits[counter] > 0)
      hashOnePair.push_back(std::make_pair(counter, hashOneHits[counter]));

  int oneTotal = 0;
  int oneSum = 0;
  for (auto item : hashOnePair)
  {
    oneSum += (item.first * (item.second + oneTotal));
    oneTotal += item.second;
  }

  double oneAverage = (oneSum / (double)num_words);
  
  std::cout << "The average number of steps for a succesful search for hash function one is "
          << oneAverage << std::endl;
  std::cout << "The worst case steps that would be needed to find a word is " 
            << hashOnePair[0].first << std::endl; 

////////////////////////////////////////////////////////////////////////////////


 int hashTwoHits[100]; // keeps track of the collisions
 std::vector<int> hashTwoVector;
  
  //updates -1 collisions to be 0, to show that no collisions happened there
  for (int counter = 0; counter < 2 * num_words; counter++)
  {
    if (hashTableTwo[counter] == -1)
        hashTableTwo[counter]++;
    int x = hashTableTwo[counter];
    hashTwoHits[x]++;
  }

  std::cout << std::endl << "Printing the statistics for hashFunction2 with hash table size: "
            << 2 * num_words << std::endl << std::endl << "#hits \t" 
            << "#slots receiving the #hits" <<std::endl << std::endl;

  
  for (int counter = 0; counter < 100; counter++)
      if (hashTwoHits[counter] > 0)
      
        std::cout << counter << "\t" << hashTwoHits[counter] << std::endl;


  std::vector<std::pair<int,int>> hashTwoPair;  
  for (int counter = 99; counter >= 0; counter--)
    if (hashTwoHits[counter] > 0)
      hashTwoPair.push_back(std::make_pair(counter, hashTwoHits[counter]));

  int twoTotal = 0;
  int twoSum = 0;
  for (auto item : hashTwoPair)
  {
    twoSum += (item.first * (item.second + twoTotal));
    twoTotal += item.second;
  }

  double twoAverage = (twoSum / (double)num_words);
  
  std::cout << "The average number of steps for a succesful search for hash function two is "
          << twoAverage << std::endl;
  std::cout << "The worst case steps that would be needed to find a word is " 
            << hashTwoPair[0].first << std::endl; 

  return 0;
}

// Cite: http://research.cs.vt.edu/AVresearch/hashing/strings.php

unsigned int hashOne(std::string word, unsigned int tableSize) 
{
  int sum = 0;
  for (auto item : word) // each letter in the word
    sum += (int) item; // convert to the int and add to sum
  
  return sum % tableSize; //when finished looping the entire word
                          // return the remainder of sum / tableSize
}  


// Cite: https://courses.cs.washington.edu/courses/cse326/00wi/handouts/lecture15/sld013.htm

unsigned int hashTwo(std::string word, unsigned int tableSize)

{
  unsigned int h = 0;

  for (int i = word.length() - 1; i >= 0; i--)
    h = (word[i] + 128 * h) % tableSize;

  return h;

}



