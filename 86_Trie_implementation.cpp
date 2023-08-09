// https://rb.gy/fr47x

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

#include <bits/stdc++.h>

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};


class Trie {

public:

    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root  = new TrieNode('\0');
    }

    void insertWord(string word, TrieNode* root){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        //Trie me aldready present hai data;

        TrieNode* child;
        //substr(len) - copy substring after length
        if(root->children[index] != NULL){
            child =  root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(word.substr(1), child);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertWord(word, root);
    }

    bool searchWord(string word, TrieNode* root){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode* child;

        //Character present hai
        if(root->children[word[0]-'a'] != NULL){
            child = root->children[index];
        }
        

        //Character present nahi hai
        else{
            return false;
        }

        return searchWord(word.substr(1), child);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchWord(word,root);
    }

    bool startsWithWord(string word, TrieNode* root){
        if(word.length() == 0){
            return true;
        }

        int index = word[0]-'a';
        TrieNode* child;

        //Character present hai
        if(root->children[word[0]-'a'] != NULL){
            child = root->children[index];
        }
        

        //Character present nahi hai
        else{
            return false;
        }

        return startsWithWord(word.substr(1), child);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithWord(prefix, root);
    }
};
