

#include<bits/stdc++.h>
#include "trie.h"

using namespace std;

bitset<5> Trie :: conversionOfChar(char x)
{
    unordered_map<char, bitset<5> > stringConversion;
    stringConversion['a'] = 0;
    stringConversion['b'] = 1;
    stringConversion['c'] = 2;
    stringConversion['d'] = 3;
    stringConversion['e'] = 4;
    stringConversion['f'] = 5;
    stringConversion['g'] = 6;
    stringConversion['h'] = 7;
    stringConversion['i'] = 8;
    stringConversion['j'] = 9;
    stringConversion['k'] = 10;
    stringConversion['l'] = 11;
    stringConversion['m'] = 12;
    stringConversion['n'] = 13;
    stringConversion['o'] = 14;
    stringConversion['p'] = 15;
    stringConversion['q'] = 16;
    stringConversion['r'] = 17;
    stringConversion['s'] = 18;
    stringConversion['t'] = 19;
    stringConversion['u'] = 20;
    stringConversion['v'] = 21;
    stringConversion['w'] = 22;
    stringConversion['x'] = 23;
    stringConversion['y'] = 24;
    stringConversion['z'] = 25;

    auto pos = stringConversion.find(x);
    return pos->second;

}

bitset<5> Trie :: conversionOfDigits(int x)
{
    map< int, bitset<5> > digitConversion;
    digitConversion[0] = 0;
    digitConversion[1] = 1;
    digitConversion[2] = 2;
    digitConversion[3] = 3;
    digitConversion[4] = 4;
    digitConversion[5] = 5;
    digitConversion[6] = 6;
    digitConversion[7] = 7;
    digitConversion[8] = 8;
    digitConversion[9] = 9;
    digitConversion[10] = 10;
    digitConversion[11] = 11;
    digitConversion[12] = 12;
    digitConversion[13] = 13;
    digitConversion[14] = 14;
    digitConversion[15] = 15;
    digitConversion[16] = 16;
    digitConversion[17] = 17;
    digitConversion[18] = 18;
    digitConversion[19] = 19;
    digitConversion[20] = 20;
    digitConversion[21] = 21;
    digitConversion[22] = 22;
    digitConversion[23] = 23;
    digitConversion[24] = 24;
    digitConversion[25] = 25;
    digitConversion[26] = 26;

    auto pos = digitConversion.find(x);
    return pos->second;
}