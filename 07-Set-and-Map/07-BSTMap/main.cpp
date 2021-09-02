#include "FileOperation.h"
#include "BSTMap2.h"
// #include "LinkedListMap.h"
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    /* code */

    {
        std::cout << "pride-and-prejudice.txt" << std::endl;
        std::vector<std::string> words;

        if (FileOps::readFile("pride-and-prejudice.txt", words))
        {
            std::cout << "Total words: " << words.size() << std::endl;
            BSTMap<std::string, int> *map = new BSTMap<std::string, int>();
            for (string word : words)
            {
                if (map->contains(word))
                {
                    map->set(word, *(map->get(word)) + 1);
                    // std::cout << map->get(word) << std::endl;
                }
                else
                {
                    map->add(word, 1);
                }
            }

            std::cout << "Total different words: " << map->getSize() << std::endl;
            std::cout << "Frequency of pride: " << *(map->get("pride")) << std::endl;
        }
    }

    // {
    //     std::cout << "pride-and-prejudice.txt" << std::endl;
    //     std::vector<std::string> words;

    //     if (FileOps::readFile("pride-and-prejudice.txt", words))
    //     {
    //         std::cout << "Total words: " << words.size() << std::endl;
    //         LinkedListMap<std::string, int> *map = new LinkedListMap<std::string, int>();
    //         for (string word : words)
    //         {
    //             if (map->contains(word))
    //             {
    //                 map->set(word, *(map->get(word)) + 1);
    //                 // std::cout << map->get(word) << std::endl;
    //             }
    //             else
    //             {
    //                 map->add(word, 1);
    //             }
    //         }

    //         std::cout << "Total different words: " << map->getSize() << std::endl;
    //         std::cout << "Frequency of pride: " << *(map->get("pride")) << std::endl;
    //     }
    // }

    return 0;
}
