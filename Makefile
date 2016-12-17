
  #Abhinav Rana
  # U06971709
  # Anna Kaplan 
  # A99039352
  # Makefile to compile and link all the files in the this assignment


CC=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g

all: test util.o benchdict benchhash

test: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

benchdict: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

benchhash: util.o DictionaryTrie.o DictionaryBST.o DictionaryHashtable.o

DictionaryTrie.o: DictionaryTrie.h

DictionaryBST.o: DictionaryBST.h

DictionaryHashtable.o: DictionaryHashtable.h

util.o: util.h

clean:
	rm -f test *.o core* *~
