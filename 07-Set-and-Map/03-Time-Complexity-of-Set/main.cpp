#include <iostream>
#include <set>
// #include "Set.h"
#include "BSTSet.h"
#include "LinkedListSet.h"
#include "FileOperation.h"

template <typename T>
double testSet(T set, string filename)
{
    int optCount = 1000;
    clock_t startTime = clock();
    std::cout << filename << std::endl;
    vector<string> words;
    if (FileOps::readFile(filename, words))
    {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words)
        {
            set->add(word);
        }
        std::cout << "Total different words: " << set->getSize() << std::endl;
    }

    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

template <typename T>
double stdtestSet(T set, string filename)
{
    int optCount = 1000;
    clock_t startTime = clock();
    std::cout << filename << std::endl;
    vector<string> words;
    if (FileOps::readFile(filename, words))
    {
        std::cout << "Total words: " << words.size() << std::endl;
        for (string word : words)
        {
            set.insert(word);
        }
        std::cout << "Total different words: " << set.size() << std::endl;
    }

    clock_t endTime = clock();
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}

int main()
{
    string filename = "pride-and-prejudice.txt";
    BSTSet<string> *bstSet = new BSTSet<string>();
    LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();

    double time1 = testSet(bstSet, filename);
    
    
    double time2 = testSet(linkedListSet, filename);
    

    std::set<string> stdSet;
    double time3 = stdtestSet(stdSet, filename);

    std::cout << "time1耗时: " << time1 << "， time2耗时: " << time2  << "， time3耗时: " << time3<< endl;

    return 0;
}
