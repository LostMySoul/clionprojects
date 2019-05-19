#include "TreeDictionary.h"

int main() {
    TreeDictionary *tree = new TreeDictionary();
    tree->addWord("Ghost");
    tree->addWord("Anya");
    tree->addWord("Anya");
    tree->addWord("Anya");
    tree->addWord("Anya");
    tree->addWord("Anya");
    tree->addWord("Kenny");
    tree->addWord("Hello");
    tree->addWord("James");
    tree->addWord("Easy");
    tree->addWord("Claw");
    tree->addWord("Denis");
    tree->addWord("Bottle");
    tree->addWord("Fedya");
    tree->addWord("James");
    tree->addWord("Claw");
    tree->addWord("James");
    tree->addWord("Easy");
    tree->addWord("Claw");
    tree->addWord("Idea");
    std::cout << *tree << std::endl;
    std::cout << tree->countWords() << std::endl;
    std::cout << tree->findWord("Anya") << std::endl;
    std::cout << tree->findWord("Ghost") << std::endl;
    std::cout << tree->findWord("Timmy") << std::endl;
    tree->deleteWord("Claw");
    tree->deleteWord("Bottle");
    tree->deleteWord("Anya");
    tree->deleteWord("Ghost");
    std::cout << *tree << std::endl;
    std::cout << "///////////////////////////////////////////////////////" << std::endl;
    std::cout << tree->countWords() << std::endl;
    std::cout << tree->findWord("Anya") << std::endl;
    std::cout << tree->findWord("Ghost") << std::endl;
    std::cout << tree->findWord("Timmy") << std::endl;
    tree->addWord("Magic");
    std::cout << *tree;
    std::cout << "///////////////////////////////////////////////////////" << std::endl;
    tree->addWord("40");
    tree->addWord("60");
    tree->addWord("30");
    tree->addWord("50");
    tree->addWord("70");
    tree->addWord("20");//1
    tree->addWord("20");//2
    tree->addWord("20");//3
    tree->addWord("35");
    tree->deleteWord("20");//3-1
    std::cout << tree->findWord("20");

    delete tree;
    return 0;
}