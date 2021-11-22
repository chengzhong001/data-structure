#include <map>
#include <iostream>
#include "WordDictionary.h"

using namespace std;

int main(int argc, char const *argv[])
{

    WordDictionary wordseach;

    wordseach.addWord("apple");
    std::cout << std::boolalpha << wordseach.search("t") << std::endl;
    std::cout << std::boolalpha << wordseach.search("apple") << std::endl;
    std::cout << std::boolalpha << wordseach.search("ap...") << std::endl;
    return 0;
}
