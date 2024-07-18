#include "GenerateWords.h"

// Generate valid words from given characters
void generateWords(TrieNode* root, const vector<char>& chars, vector<string>& validWords, string currentWord, vector<bool>& used) {
    
    if (currentWord.length() >= 3 && findNode(root, currentWord)) { // Valid English words do not require to have all of provided letters but must have at least 3 letters
        bool found = false;
        for (const string& word : validWords) {
            if (word == currentWord) {
                found = true;
                break;
            }
        }
        if (!found) {
            validWords.push_back(currentWord);  // Add to list
        }
    }
    for (int i = 0; i < chars.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            generateWords(root, chars, validWords, currentWord + chars[i], used);  // Recur for next character
            used[i] = false;
        }
    }
}
