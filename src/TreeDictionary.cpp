#include "TreeDictionary.h"


Node::Node(std::string word, unsigned int frequency, int bal, Node *right, Node *left) {
    this->word = word;
    this->balance = bal;
    this->count = frequency;
    this->right = right;
    this->left = left;
}

void TreeDictionary::RRotation(Node *&pA, Node *&pB) {
    if (!pB->right || pA->right) {
        pB->balance = pA->balance = 0;
    } else {
        pB->balance = 1;
        pA->balance = -1;
    }
    pA->left = pB->right;
    pB->right = pA;
    pA = pB;
}

void TreeDictionary::LRRotation(Node *&pA, Node *&pB) {
    Node *pC = pB->right;
    if (pC->balance > 0) {
        pA->balance = pC->balance = 0;
        pB->balance = -1;
    } else {
        if (pC->balance == 0) {
            pA->balance = pC->balance = pB->balance = 0;
        } else {
            pA->balance = 1;
            pB->balance = pC->balance = 0;
        }
    }
    pA->left = pC->right;
    pB->right = pC->left;
    pC->left = pB;
    pC->right = pA;
    pA = pC;
}

void TreeDictionary::LRotation(Node *&pA, Node *&pB) {
    if (!pB->left || pA->left) {
        pB->balance = pA->balance = 0;
    } else {
        pA->balance = 1;
        pB->balance = -1;
    }
    pA->right = pB->left;
    pB->left = pA;
    pA = pB;
}

void TreeDictionary::RLRotation(Node *&pA, Node *&pB) {
    Node *pC = pB->left;
    if (pC->balance > 0) {
        pB->balance = pC->balance = 0;
        pA->balance = -1;
    } else {
        if (pC->balance == 0) {
            pA->balance = pC->balance = pB->balance = 0;
        } else {
            pB->balance = 1;
            pA->balance = pC->balance = 0;
        }
    }
    pA->right = pC->left;
    pB->left = pC->right;
    pC->left = pA;
    pC->right = pB;
    pA = pC;
}

bool TreeDictionary::balanceAddLeft(Node *&pA) {
    switch (pA->balance) {
        case 1:
            pA->balance = 0;
            return false;
        case 0:
            pA->balance = -1;
            return true;
        case -1:
            Node *pB = pA->left;
            if (pB->balance < 0) {
                RRotation(pA, pB);
                return false;
            } else {
                LRRotation(pA, pB);
                return false;
            }
    }
}

bool TreeDictionary::balanceDelLeft(Node *&pA) {
    switch (pA->balance) {
        case 0:
            pA->balance = 1;
            return false;
        case -1:
            pA->balance = 0;
            return true;
        case 1:
            Node *pB = pA->right;
            if (pB->balance < 0) {
                RLRotation(pA, pB);
                return true;
            } else {
                LRotation(pA, pB);
                if (pA->left->right) {
                    return false;
                }
                return true;
            }
    }
}

bool TreeDictionary::balanceAddRight(Node *&pA) {
    switch (pA->balance) {
        case 0:
            pA->balance = 1;
            return true;
        case -1:
            pA->balance = 0;
            return false;
        case 1:
            Node *pB = pA->right;
            if (pB->balance < 0) {
                RLRotation(pA, pB);
                return false;
            } else {
                LRotation(pA, pB);
                return false;
            }
    }
}

bool TreeDictionary::balanceDelRight(Node *&pA) {
    switch (pA->balance) {
        case 0:
            pA->balance = -1;
            return false;
        case 1:
            pA->balance = 0;
            return true;
        case -1:
            Node *pB = pA->left;
            if (pB->balance <= 0) {
                RRotation(pA, pB);
                if (pA->right->left) {
                    return false;
                }
                return true;
            } else {
                LRRotation(pA, pB);
                return true;
            }
    }
}

bool TreeDictionary::del(Node *&rootLeft, Node *&toDel) {
    if (rootLeft->right) {
        if (del(rootLeft->right, toDel)) {
            return balanceDelRight(rootLeft);
        }
        return false;
    }
    toDel->word = rootLeft->word;
    toDel = rootLeft;
    rootLeft = rootLeft->left;
    return true;
}

void TreeDictionary::copyTree(Node *root, Node *copy) {
    if (!copy) {
        return;
    }
    root = new Node(copy->word, copy->balance, copy->count);
    copyTree(root->left, copy->left);
    copyTree(root->right, copy->right);
}

void TreeDictionary::deleteTree(Node *root) {
    if (!root) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

unsigned int TreeDictionary::findWord(Node *root, std::string word) {
    if (!root) { return 0; }
    if (root->word.compare(word) == 0) {
        return root->count;
    }
    if (root->word.compare(word) > 0) {
        return findWord(root->left, word);
    }
    if (root->word.compare(word) < 0) {
        return findWord(root->right, word);
    }
}

bool TreeDictionary::addWord(Node *&root, std::string &word) {
    if (!root) {
        root = new Node(word);
        return true;
    }
    if (root->word.compare(word) == 0) {
        root->count++;
        return false;
    }
    if (root->word.compare(word) > 0) {
        if (addWord(root->left, word)) {
            return balanceAddLeft(root);
        }
        return false;
    }
    if (root->word.compare(word) < 0) {
        if (addWord(root->right, word)) {
            return balanceAddRight(root);
        }
        return false;
    }
    return false;
}

bool TreeDictionary::deleteWord(Node *&root, std::string &word) {
    if (!root) {
        return false;
    }
    if (root->word.compare(word) > 0) {
        if (deleteWord(root->left, word)) {
            return balanceDelLeft(root);
        }
        return false;
    }
    if (root->word.compare(word) < 0) {
        if (deleteWord(root->right, word)) {
            return balanceDelRight(root);
        }
        return false;
    }
    Node *pDel = root;
    if (root->count > 1) {
        root->count--;
    } else {
        if (!root->right) {
            root = root->left;
            delete pDel;
            return true;
        }
        if (!root->left) {
            root = root->right;
            delete pDel;
            return true;
        }
        if (del(root->left, pDel)) {
            delete pDel;
            return balanceDelLeft(root);
        }
        return false;
    }
}

void TreeDictionary::printTree(std::ostream &os, Node *root) {
    if (!root) { return; }
    printTree(os, root->left);
    os << root->word << " - " << root->count << std::endl;
    printTree(os, root->right);
}

void TreeDictionary::print(std::ostream &os, Node *root, int ic) {
    if (!root) {
        return;
    }
    for (int i = 0; i < ic; i++) {
        os << "\t";
    }
    os << root->word << " " << root->balance << std::endl;
    print(os, root->left, ic + 1);
    print(os, root->right, ic + 1);
}

TreeDictionary::TreeDictionary() {
    root = nullptr;
    size = 0;
}

TreeDictionary::TreeDictionary(const TreeDictionary &copy) {
    copyTree(root, copy.root);
    size = copy.size;
}

TreeDictionary::TreeDictionary(TreeDictionary &&move) {
    size = move.size;
    std::swap(root, move.root);
}


TreeDictionary::~TreeDictionary() {
    size = 0;
    deleteTree(root);
}

TreeDictionary &TreeDictionary::operator=(const TreeDictionary &copy) {
    if (this == &copy) {
        return *this;
    }
    deleteTree(root);
    root = nullptr;
    size = copy.size;
    copyTree(root, copy.root);
}

TreeDictionary &TreeDictionary::operator=(TreeDictionary &&move) {
    size = move.size;
    std::swap(root, move.root);
    move.deleteTree(move.root);
    return *this;
}

unsigned int TreeDictionary::findWord(std::string word) {
    return findWord(root, word);
}

void TreeDictionary::addWord(std::string word) {
    size++;
    addWord(root, word);
}

void TreeDictionary::deleteWord(std::string word) {
    size--;
    deleteWord(root, word);
}

unsigned int TreeDictionary::countWords() {
    return size;
}

std::ostream &operator<<(std::ostream &os, TreeDictionary &obj) {
    obj.printTree(os, obj.root);
    os << "\n" << "--------------------------------------" << "\n";
    obj.print(os, obj.root, 0);
    return os;
}
