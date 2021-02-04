
#ifndef TRIE
#define TRIE
#include<bits/stdc++.h>
using namespace std;

// Trie structure 
  
class Trie
{
    public : 
            // storing the number of children of all the nodes in a trie tree
            vector< bitset<5> > noOfChildren;
            
            // storing all char's of node in Trie tree into bits
            vector< bitset<5> > charsInBits;

            // storing total children till particular node ( in prefix manner)
            vector<int> totalNodes;

            // whether node is leaf or not 
            vector<bitset<1> > leafNode;

            // searching time of node
            vector<int> searchTime;

            // number of search
            int k = 5;
            
            bool isLeaf;
            map<char, Trie*> child;

            void insert(Trie*, string);
            bitset<5> conversionOfChar(char);
            bitset<5> conversionOfDigits(int);
            void levelByLevelSearch(Trie*&);
            void searchInTrie(const char*);
            void writeToFile1();
            void writeToFile2();
            void writeToFile3();
            void writeToFile4();
            void writeToFile5();
            void readingFromFile1();
            void readingFromFile2();
            void readingFromFile3();
            void readingFromFile4();
            void readingFromFile5();
            void print();
};

#endif 