

#ifndef LEVEL 
#define LEVEL
#include<bits/stdc++.h>
#include "trie.h"
#include "conversion.cpp"

 

void Trie:: levelByLevelSearch(Trie* &head)
{
    cout<<"level order started "<<endl;
    Trie* curr = this;

    // stores the number of child to that node
    int noOfChildNodes = 0;

    //Pushing default nodes value in totalNodes
    totalNodes.push_back(1);
    
    // Traversing through all the children of the default node to count them.
    noOfChildNodes = curr->child.size();

    // adding total child nodes of current nodes + previous node.
    int total = noOfChildNodes + totalNodes.back();
    totalNodes.push_back(total);

    bitset<5> m = conversionOfDigits(noOfChildNodes);
    noOfChildren.push_back(m);

    queue <Trie*> q;
    cout<< "going on "<<endl;

    //pushing all the default nodes chars in queue
    for(auto itr = curr->child.begin(); itr != curr->child.end(); itr++)
    {
        cout<<"entered in for loop "<<endl;
        q.push(itr->second);
        cout<<"Pushed in queue "<<endl;
        cout<< itr->first <<endl;

        bitset<5> m = conversionOfChar(itr->first);
        charsInBits.push_back(m);
        cout<<"Processed "<<endl;
        // setting leafNode vector according to  node is leaf or not 
        Trie* M = itr->second;
        if( M->isLeaf == true)
            leafNode.push_back(1);
        else
            leafNode.push_back(0);
        
        cout<<"exited from loop "<<endl;
    }
    
    cout<< "q  created "<<endl;

    while(!q.empty())
    {
        Trie* temp = q.front();
        q.pop();        

        cout<<"popped from queue "<<endl;

        // searching time of particular node is set to 0
        searchTime.push_back(0);
        
        // Initialize number of childs to be zero.
       int NoOfChild = 0;

        // Traversing through all the children to count them.
        int noOfChild = temp->child.size();

        // adding total child nodes of current nodes + previous node.
        total = noOfChild + totalNodes.back();
        totalNodes.push_back(total);

        m = conversionOfDigits(noOfChild);
        noOfChildren.push_back(m);

        for(auto itr = temp->child.begin(); itr != temp->child.end(); itr++)
        {
            cout<< "entered in q's for loop "<<endl;
            q.push(itr->second);
            bitset<5> m = conversionOfChar(itr->first);
            charsInBits.push_back(m);

            // setting leafNode vector according to  node is leaf or not 
            Trie* M = itr->second;
            if( M->isLeaf == true)
                leafNode.push_back(1);
            else
                leafNode.push_back(0);
        }
    }
    cout<< " came out of the loop "<<endl;
}

#endif 
 