// ©2023 JDSherbert. All rights reserved.
#pragma once

#include <iostream>
#include <unordered_map>

class TrieNode 
{
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
};

class Trie 
{
private:
    TrieNode* root;

public:
    Trie();
    ~Trie();

    void Insert(const std::string& word);
    bool Search(const std::string& word) const;
    bool StartsWith(const std::string& prefix) const;
    void DeleteTrie(TrieNode* node);
};
