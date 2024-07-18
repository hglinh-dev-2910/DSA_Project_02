#include "Trie.h"

// Creates trie node
TrieNode* getNode() {
    TrieNode* pNode = new TrieNode;
    pNode->value = NIL;  // Initialize value as NIL
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = nullptr;  // Initialize all children as NULL
    }
    return pNode;
}

// Get the node corresponding to key[d] in the Trie
TrieNode* get(TrieNode* p, const string& key, int d) {
    if (p == nullptr) return nullptr;  
    if (d == key.length()) return p;  // If end of key is reached, return node
    int c = key[d] - 'a';  // Get the index of the character
    return get(p->children[c], key, d + 1);  // Recur for next character
}

// Finds the node corresponding to the key
TrieNode* findNode(TrieNode* p, const string& key) {
    p = get(p, key, 0);
    return (p && p->value != NIL) ? p : nullptr;  // Return if it exists and has a valid value
}

// Inserts the key into trie
TrieNode* put(TrieNode* p, const string& key, int val, int d) {
    if (p == nullptr) {
        p = getNode();  // Create a new node if null
    }
    if (d == key.length()) {
        p->value = val;  // Assign value at the end of key
        return p;
    }
    int c = key[d] - 'a';  // Get the index of the character
    p->children[c] = put(p->children[c], key, val, d + 1);  // Recur for the next character
    return p;
}

// Inserts the key into the Trie
void insert(TrieNode*& root, const string& key, int val) {
    root = put(root, key, val, 0);
}

// Collects all words with the given prefix
void collect(TrieNode* p, const string& prefix, vector<string>& results) {
    if (p == nullptr) return;
    if (p->value != NIL) {
        results.push_back(prefix);  // Add prefix to results if it's a valid word
    }
    for (int c = 0; c < ALPHABET_SIZE; c++) {
        if (p->children[c]) {
            collect(p->children[c], prefix + static_cast<char>('a' + c), results);  // Recur for all children
        }
    }
}

// Recursively searches for the longest prefix of the string in the Trie
int searchLongestPrefixOf(TrieNode* p, const string& s, int d, int length) {
    if (p == nullptr) return length;
    if (p->value != NIL) length = d;  // Update length if it's a valid word
    if (d == s.length()) return length;  // If end of string is reached, return length
    int c = s[d] - 'a';  // Get the index of the character
    return searchLongestPrefixOf(p->children[c], s, d + 1, length);  // Recur for the next character
}

// Finds the longest prefix of the string in the Trie
string longestPrefixOf(TrieNode* root, const string& s) {
    int length = searchLongestPrefixOf(root, s, 0, 0);
    return s.substr(0, length);  // Return the longest prefix
}

// Recursively deletes the key from the Trie
TrieNode* del(TrieNode* p, const string& key, int d) {
    if (p == nullptr) return nullptr;
    if (d == key.length()) {
        p->value = NIL;  // Set value to NIL at the end of key
    } else {
        int c = key[d] - 'a';  // Get the index of the character
        p->children[c] = del(p->children[c], key, d + 1);  // Recur for the next character
    }
    if (p->value != NIL) return p;  // Return node if it has a valid value
    for (int c = 0; c < ALPHABET_SIZE; c++) {
        if (p->children[c] != nullptr) return p;  // Return node if any child is not null
    }
    delete p;  // Delete the node if it has no valid value and no children
    return nullptr;
}

// Deletes the key from the Trie
void remove(TrieNode*& root, const string& key) {
    root = del(root, key, 0);
}
