#ifndef GENERATEWORDS_H
#define GENERATEWORDS_H

#include "trie.h"
#include <vector>
#include <string>

using namespace std;

void generateWords(TrieNode* root, const vector<char>& chars, vector<string>& validWords, string currentWord, vector<bool>& used);

#endif // GENERATEWORDS_H
