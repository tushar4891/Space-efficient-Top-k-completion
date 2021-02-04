
#ifndef INSERTION
#define INSERTION

#include<bits/stdc++.h>
#include "trie.h" 

void Trie :: insert(Trie* head,string str)
{
    Trie* curr = this; 
    cout << "string is "<<str <<endl;
    for( int i = 0; i < str.length(); i++)
    {
        auto pos = curr->child.find(str[i]);

        if(pos == curr->child.end())
            curr->child[str[i]] = new Trie();
        
       curr = curr->child[str[i]];
    }
    curr->isLeaf = true;
}

#endif 