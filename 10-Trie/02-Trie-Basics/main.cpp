#include <iostream>
#include <map>
#include <vector>
#include "FileOperation.h"
#include "BSTSet.h"
#include "Trie.h"

int main(int argc, char const *argv[])
{
    std::vector<std::string> words;

    if (FileOps::readFile("pride-and-prejudice.txt", words))
    {
        clock_t startTime = clock();

        BSTSet<std::string> bstset;
        for (std::string word : words)
            bstset.add(word);
        for (std::string word : words)
            bstset.contains(word);
        clock_t endTime = clock();
        double time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        std::cout << "BST Time: " << time << std::endl;

        startTime = clock();

        Trie trie;
        for (std::string word : words)
            trie.add(word);
    
        for (std::string word : words)
            trie.contains(word);
        endTime = clock();
        time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
        std::cout << "Trie Time: " << time << std::endl;
    }
}
