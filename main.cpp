
#ifndef MAIN
#define MAIN
#include<bits/stdc++.h>
#include <stdio.h>
#include <sys/ioctl.h> // For FIONREAD
#include <termios.h>
#include <stdbool.h>
#include "trie.h"
#include "LevelOrdering.cpp"
#include "insertion.cpp"
#include "search.cpp"

void Trie :: writeToFile1()
{
    ofstream outfile("noOfChildren.txt");
   
    for( int i = 0 ; i < noOfChildren.size(); i++)
    {
        outfile << noOfChildren[i] <<endl;
    }
    outfile.close();
}

void Trie :: writeToFile2()
{
    ofstream outfile("charsInBits.txt");

    for( int i = 0 ; i < charsInBits.size(); i++)
    {
        outfile << charsInBits[i]<<endl;
    }
    outfile.close();
}

void Trie :: writeToFile3()
{
    ofstream outfile ("totalNodes.txt");

    for( int i = 0 ; i < totalNodes.size(); i++)
    {
        outfile << totalNodes[i]<<endl;
    }
    outfile.close();
}

void Trie :: writeToFile4()
{
    ofstream outfile("leafNode.txt");
    
    for( int i = 0 ; i < leafNode.size(); i++)
    {
        outfile << leafNode[i]<<endl;
    }
    outfile.close();
}

void Trie:: writeToFile5()
{
    ofstream outfile("searchTime.txt");
    for( int i = 0 ; i < searchTime.size(); i++)
    {
        outfile << searchTime[i]<<endl;
    }
    outfile.close();
}

    void Trie :: print() 
    {
         cout<<" prinitng children of node " <<endl;
         for( auto i : noOfChildren)
         {
            cout<< i <<"  ";
         }
        cout <<endl;

        cout<<" prinitng chars in nodes" <<endl;
        for( auto i : charsInBits)
        {
            cout << i <<"  ";
        }
        cout <<endl<<endl;

        for( auto i : totalNodes)
        {
            cout<< i << " ";
        }
        cout<<endl;

        for( auto i : leafNode)
        {
            cout<< i <<" ";
        }
        cout<<endl;

        for(auto i : searchTime)
        {
            cout<< i <<" ";
        }
        cout<<endl;
    }

 void Trie :: readingFromFile1()
 {
     ifstream infile;

    infile.open("totalNodes.txt");
    int n;
    while(!infile.eof())
    {
        infile >> n;
        totalNodes.push_back(n);
    }
    
    //closing the file 
    infile.close();
 }

void Trie :: readingFromFile2()
 {
      ifstream infile;

    infile.open("searchTime.txt");
    int n;

    while(!infile.eof())
    {
        infile >> n;
        searchTime.push_back(n);
    }
    
    //closing the file 
    infile.close();
 }

void Trie :: readingFromFile3()
 {
     ifstream infile;

    infile.open("noOfChildren.txt");
    bitset<5> str;
    while(!infile.eof())
    {
        infile >> str;
        noOfChildren.push_back(str);
    }
    
    //closing the file 
    infile.close();
 }

void Trie :: readingFromFile4()
 {
     ifstream infile;

    infile.open("leafNode.txt");
    bitset<1> str;
    while(!infile.eof())
    {
        infile >> str;
        leafNode.push_back(str);
    }
    
    //closing the file 
    infile.close();
 }

 void Trie :: readingFromFile5()
 {
     ifstream infile;

    infile.open("charsInBits.txt");
    bitset<5> str;
    while(!infile.eof())
    {
        infile >> str;
        charsInBits.push_back(str);
    }
    
    //closing the file 
    infile.close();
 }

int kbhit(void) {
    static bool initflag = false;
    static const int STDIN = 0;

    if (!initflag) {
        // Use termios to turn off line buffering
        struct termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initflag = true;
    }

    int nbbytes;
    ioctl(STDIN, FIONREAD, &nbbytes);  // 0 is STDIN
    return nbbytes;
}

#include <unistd.h>
int main()
{
    cout<< "Program started " <<endl;
    Trie t;
    Trie* head = new Trie();
   /*
    ifstream infile;
    string str;
    cout<<"opening a file "<<endl;
    infile.open("text.txt");
    
    while(!infile.eof())
    {
        infile >> str;
        t.insert(head,str);
    }
    
    //closing the file 
    infile.close();
    cout<< "Reading a file completed "<<endl;

    t.levelByLevelSearch(head);
    cout<< "Level order completed "<<endl;
    t.writeToFile1();
    t.writeToFile2();
    t.writeToFile3();
    t.writeToFile4();
    t.writeToFile5();
    //t.print();
    cout<<" Storing done "<<endl;
   */

    string searchString = "";
    cout<<"about to start reading "<<endl;
    t.readingFromFile1();
    cout<< "1st file reading done "<<endl;
    t.readingFromFile2();
    t.readingFromFile3();
    t.readingFromFile4();
    t.readingFromFile5();
    cout<<"reading done "<<endl;

   //printf("Press key");
    while (!kbhit()) {
       // printf(".");
        fflush(stdout);
        sleep(0);
    }
    char c;
    char a;

    // Once space bar is pressed we will come out of the program
    while(c != ' ')
    {
         c = getchar();

         if(c == '\n')
		{
			cout<< "New search "<<endl;
		}
        //printf("\nChar received:%c\n", c);
        cout<<endl;
        if(c != ' ')
        {

            if( c != '\n')
            {    
                searchString += c;
                const char * d = searchString.c_str();
                t.searchInTrie(d);
            }
        
            else
            {
                searchString = "";
            }
        }
        else
        {
            cout<<"Exiting...... "<<endl;
            return 0;
        }
        
       // printf("Done.\n");
    }

   // t.searchInTrie("a");
   
    return 0;
}

#endif  