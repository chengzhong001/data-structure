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
       
        Trie trie;
        for (int i = 0; i < 10; i++)
        {
            auto word = words[i];
            std::cout << word << "\n";
            trie.add(word);
        }

        std::cout << std::boolalpha << trie.isPrefix("t") << std::endl;
        
        trie.add("apple");
        std::cout << std::boolalpha << trie.contains("apple") << std::endl;
        std::cout << std::boolalpha << trie.isPrefix("ap") << std::endl;

       
    }
}
