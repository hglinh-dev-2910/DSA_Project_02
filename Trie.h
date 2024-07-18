#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ALPHABET_SIZE 26  // Size of alphabet
#define NIL -1  // NIL value for unassigned node

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];  // Pointers to child nodes
    int value;  // Value associated with the node
};

TrieNode* getNode();
TrieNode* get(TrieNode* p, const string& key, int d);
TrieNode* findNode(TrieNode* p, const string& key);
TrieNode* put(TrieNode* p, const string& key, int val, int d);
void insert(TrieNode*& root, const string& key, int val);
void collect(TrieNode* p, const string& prefix, vector<string>& results);
int searchLongestPrefixOf(TrieNode* p, const string& s, int d, int length);
string longestPrefixOf(TrieNode* root, const string& s);
TrieNode* del(TrieNode* p, const string& key, int d);
void remove(TrieNode*& root, const string& key);

#endif // TRIE_H
