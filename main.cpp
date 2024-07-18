    #include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Trie.h"
#include "GenerateWords.h"

using namespace std;

int main() {
    TrieNode* root = getNode();  // Create trie root

    // Read file
    ifstream file("Dic.txt");

    string word;
    while (file >> word) {
        insert(root, word, 1);  // Insert words into trie
    }
    file.close();

    // Input char from console
    vector<char> chars;
    cout << "Enter characters(end with a character not in the alphabet): ";
    char ch;
    while (cin >> ch && isalpha(ch)) {
        chars.push_back(ch);  // Add characters to vector
    }

    vector<string> validWords; // Store valid words
    vector<bool> used(chars.size(), false);  // Vector to track used characters

    // Generate valid words from the characters
    generateWords(root, chars, validWords, "", used);

    // Print
    cout << validWords.size() << endl; 
    
    for (const string& word : validWords) {
        cout << word << endl;
    }

    return 0;
}
 