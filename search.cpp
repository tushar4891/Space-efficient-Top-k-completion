
#ifndef SEARCH
#define SEARCH

#include<bits/stdc++.h>
using namespace std;
 
#include "trie.h"
#include "LevelOrdering.cpp"

struct Node
{
    int hit;
    int index;
};

struct comp
{
    bool operator () ( const Node lhs, const Node rhs)
    {
        return lhs.hit < rhs.hit || (lhs.hit == rhs.hit && lhs.index > rhs.index);
    }
};

int binarySearch(int start, int end, const char *str, vector<bitset<5> > charsInBits)
{
    // int value of current char in string.
    int charValue = *str - 'a';
    bool flag = false;
    if( start == end)
    {
        bitset<5> m = charsInBits[start];
        int midValue = (int) m.to_ulong();
        if(midValue == charValue)
            return start;
        else
        {
            cout<<"Word not found "<<endl;
            return -1;
        }
    }
    
    if( start > end)
        return -1;

    while( start <= end)
    {
        int mid = (start + end )/2;

        // finding mid word
        bitset<5> m = charsInBits[mid];

        // intger value of mid bitset
        int midValue = (int) m.to_ulong();

        if(charValue < midValue)
            end = mid - 1;
        else
        {
            if(charValue > midValue)
                start = mid + 1;    
            else
            {
                if(charValue == midValue)
                {
                        flag = true;
                        return mid;
                }
                else
                {
                    cout<<"exited "<<endl;
                    return -1;
                }
                
            }
        }
    } 
    if(!flag)
        return -1;
}

// Printing all the words till leaf node
  void searchUtil(Node element, vector<bitset<5> >noOfChildren, vector<bitset<5> >charsInBit, vector<int> totalNodes,
                vector<bitset<1> > leafNode , string s, vector<int> searchTime, int& noOfStrings)
{

    // finding out char at position startPos
    s = s + (char) ((int) charsInBit[element.index - 1].to_ulong() + 'a');

    // if current node has further children.
    if(( (int) noOfChildren[element.index].to_ulong() > 0) && noOfStrings > 0)
     {
         if(leafNode[element.index -1] == 1)
        {
                cout<< s <<endl;
                (noOfStrings)--;
        }

        searchTime[element.index]++;

        // Finding out total child nodes does this node have
        int totalChildNode = (int) noOfChildren[element.index].to_ulong();

        // starting position of nodes.
          int start = totalNodes[element.index];

        // ending position of nodes
        int end = start + totalChildNode -1; 

        // We need to insert all the elements between range startPos and endPos
        // into max heap so that max search time node will be chosen.
        priority_queue<Node, vector<Node>, comp > pq;

        for( int i = start; i <= end; i++)
        {
            pq.push({searchTime[i], i});
        }
   
        while(!pq.empty() && noOfStrings > 0)
        {
            // popping out the max hit time element
            Node maxEle = pq.top();
            pq.pop();

            searchUtil(maxEle, noOfChildren, charsInBit, totalNodes, leafNode, s, searchTime, noOfStrings);
            
        }
        s.pop_back();
        
     }

     // current node does not have any further children
     else
     {
         cout<< s << endl;
         noOfStrings--;
         searchTime[element.index]++;
     }
     
}

void Trie :: searchInTrie(const char* str)
{
    if(*str == ' ')
        return;

    int noOfStrings = k;

    bitset<5> currentNodeChildInBit = noOfChildren[0];
    int currentNodeChild = (int) currentNodeChildInBit.to_ulong();
    int start = 0;
    int end = currentNodeChild - 1;
    string s = "";
    
    int currNode;

    while(*str)
    {
       // cout<< "Char I am seeing in Trie = "<< *str <<endl;
        char currentChar = *str;
        s = s + *str;

        // finidng out the position of current char in charInBits
        if(*str != ' ')
            currNode = binarySearch(start, end, str, charsInBits);
        else
        {
            return;
        }
        

        // when currNode == -1, it means it is the leaf node 
        // so break the condition.
        if( currNode == -1)
        {
            //cout<<"No such word found "<<endl;
                return;
        }

        // incrementing currNode to get its perfecct position.
        currNode++;

        // updating searchtime of node.
        searchTime[currNode]++;

          /*cout<< "after receiving char = "<< *str <<endl;
            for( auto i : searchTime)
            {
                cout<< i <<" ";
            }
            cout<<endl;
          */
         
        // we need to find out from where the child nodes of current node
        // gets started 
        int childNodeStartedPosition = totalNodes[currNode];

        // number of childs to current nodes.
        bitset<5> m = noOfChildren[currNode];
        int intValueOfM = (int) m.to_ulong();

        str++;
        if(*str)
        {
             start = childNodeStartedPosition - 1;
             end = start + intValueOfM -1;
        }
        
    }
    
    if(leafNode[currNode] == 1)
    {
        cout<< s <<endl;
        noOfStrings--;
    }

    bitset<5> m = noOfChildren[currNode];

    // checking whether last char of given string has further char's or not.
    // For that we are checking, last char's value in vector noOfChildren.
    if( noOfChildren[currNode].to_ulong() > 0)
    {
        int totalChildNode = (int) noOfChildren[currNode].to_ulong();

        // starting position of nodes.
        int startPos = totalNodes[currNode];

        // ending position of nodes.
        int endPos = startPos + totalChildNode -1; 
        
        // We need to insert all the elements between range startPos and endPos
        // into max heap so that max search time node will be chosen.
        priority_queue<Node, vector<Node>, comp > pq;
        for( int i = startPos; i <= endPos; i++)
        {
            pq.push({searchTime[i], i});
        }
   
        while(!pq.empty() && noOfStrings > 0)
        {

            // popping out the max hit time element
            Node maxEle = pq.top();
            pq.pop();

            searchUtil(maxEle, noOfChildren, charsInBits, totalNodes, leafNode, s, searchTime, noOfStrings);
        }
            
    }
}

#endif 