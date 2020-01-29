#include "TreeDictionary.h"


//int main() {
//    TreeDictionary *tree = new TreeDictionary();
//    tree->addWord("Ghost");
//    tree->addWord("Anya");
//    tree->addWord("Anya");
//    tree->addWord("Anya");
//    tree->addWord("Anya");
//    tree->addWord("Anya");
//    tree->addWord("Kenny");
//    tree->addWord("Hello");
//    tree->addWord("James");
//    tree->addWord("Easy");
//    tree->addWord("Claw");
//    tree->addWord("Denis");
//    tree->addWord("Bottle");
//    tree->addWord("Fedya");
//    tree->addWord("James");
//    tree->addWord("Claw");
//    tree->addWord("James");
//    tree->addWord("Easy");
//    tree->addWord("Claw");
//    tree->addWord("Idea");
//    std::cout << *tree << std::endl;
//    std::cout << tree->countWords() << std::endl;
//    std::cout << tree->findWord("Anya") << std::endl;
//    std::cout << tree->findWord("Ghost") << std::endl;
//    std::cout << tree->findWord("Timmy") << std::endl;
//    tree->deleteWord("Claw");
//    tree->deleteWord("Bottle");
//    tree->deleteWord("Anya");
//    tree->deleteWord("Ghost");
//    std::cout << *tree << std::endl;
//    std::cout << "///////////////////////////////////////////////////////" << std::endl;
//    std::cout << tree->countWords() << std::endl;
//    std::cout << tree->findWord("Anya") << std::endl;
//    std::cout << tree->findWord("Ghost") << std::endl;
//    std::cout << tree->findWord("Timmy") << std::endl;
//    tree->addWord("Magic");
//    std::cout << *tree;
//    std::cout << "///////////////////////////////////////////////////////" << std::endl;
//    tree->addWord("40");
//    tree->addWord("60");
//    tree->addWord("30");
//    tree->addWord("50");
//    tree->addWord("70");
//    tree->addWord("20");//1
//    tree->addWord("20");//2
//    tree->addWord("20");//3
//    tree->addWord("35");
//    tree->deleteWord("20");//3-1
//    std::cout << tree->findWord("20");
//
//    delete tree;
//    return 0;
//}

void print_menu() {
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Add word to dictionary" << std::endl;
    std::cout << "2. Find word in dictionary" << std::endl;
    std::cout << "3. Delete word from dictionary" << std::endl;
    std::cout << "4. Print tree" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << ">";
}

int get_variant(int count) {
    int variant;
    std::string s;
    getline(std::cin, s);

    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        std::cout << "Incorrect input. Try again: ";
        getline(std::cin, s);
    }

    return variant;
}

int main() {
    TreeDictionary *tree = new TreeDictionary();
    int variant;
    std::string word;
    do {
        print_menu();
        variant = get_variant(5);
        switch (variant) {
            case 1:
                std::cout << "Enter word to add: ";
                getline(std::cin, word);
                tree->addWord(word);
                break;

            case 2:
                std::cout << "Enter word to find: ";
                getline(std::cin, word);
                std::cout << tree->findWord(word) << std::endl;
                break;

            case 3:
                std::cout << "Enter word to delete: ";
                getline(std::cin, word);
                tree->deleteWord(word);
                break;

            case 4:
                std::cout << *tree;
                break;
        }

        if (variant != 5)
            std::cout << "\n\n\n\n";
    } while (variant != 5);
    delete tree;
    return 0;
}