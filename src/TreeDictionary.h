#pragma once

#include "iostream"
#include "string"

struct Node {
    std::string word;
    unsigned int count;
    int balance;
    Node *right, *left;
    Node(std::string word, unsigned int frequency = 1U, int bal = 0, Node *right = nullptr, Node *left = nullptr);
};

class TreeDictionary {
private:
    Node *root;
    int size;
    void RRotation(Node *&pA, Node *&pB);
    void LRRotation(Node *&pA, Node *&pB);
    void LRotation(Node *&pA, Node *&pB);
    void RLRotation(Node *&pA, Node *&pB);
    bool balanceAddLeft(Node *&pA);
    bool balanceAddRight(Node *&pA);
    bool balanceDelLeft(Node *&pA);
    bool balanceDelRight(Node *&pA);
    bool del(Node *&rootLeft, Node *&toDel);
    void copyTree(Node *root, Node *copy);
    void deleteTree(Node *root);
    unsigned int findWord(Node *root, std::string word);
    bool addWord(Node *&root, std::string &word);
    bool deleteWord(Node *&root, std::string &word);
    void printTree(std::ostream &os, Node *root);
    void print(std::ostream &os, Node *root, int i);

public:
    TreeDictionary();
    TreeDictionary(const TreeDictionary &copy);
    TreeDictionary(TreeDictionary &&move);
    ~TreeDictionary();
    TreeDictionary &operator=(const TreeDictionary &copy);
    TreeDictionary &operator=(TreeDictionary &&move);
    unsigned int findWord(std::string word);
    void addWord(std::string word);
    void deleteWord(std::string word);
    unsigned int countWords();
    friend std::ostream &operator<<(std::ostream &os, TreeDictionary &obj);
};

