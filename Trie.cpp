// ©2023 JDSherbert. All rights reserved.
#include "Trie.h"

TrieNode::TrieNode() 
: isEndOfWord(false) 
{
}

Trie::Trie() 
: root(new TrieNode())
{
}

Trie::~Trie() 
{
    DeleteTrie(root);
}

void Trie::Insert(const std::string& word) 
{
    TrieNode* node = root;
    for (char ch : word) 
    {
        if (node->children.find(ch) == node->children.end()) 
        {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
  
    node->isEndOfWord = true;
}

bool Trie::Search(const std::string& word) const 
{
    const TrieNode* node = root;
    for (char ch : word) 
    {
        if (node->children.find(ch) == node->children.end()) 
        {
            return false;
        }
        
        node = node->children.at(ch);
    }
    
    return (node != nullptr) && (node->isEndOfWord);
}

bool Trie::StartsWith(const std::string& prefix) const 
{
    const TrieNode* node = root;
    for (char ch : prefix) 
    {
        if (node->children.find(ch) == node->children.end()) 
        {
            return false;
        }
        
        node = node->children.at(ch);
    }
    
    return (node != nullptr);
}

void Trie::DeleteTrie(TrieNode* node) 
{
    if (node != nullptr) 
    {
        for (auto& child : node->children) 
        {
            DeleteTrie(child.second);
        }
      
        delete node;
    }
}
