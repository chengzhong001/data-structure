#include <iostream>
#include <map>
#include "Trie.h"

int main(int argc, char const *argv[])
{
  
    std::map<char, std::string> next1{ {'s', "string"}};
    std::map<std::string, int> next { {"CPU", 10}, {"GPU", 15}, {"RAM", 20}, };

    std::cout << next1['s'];
    return 0;
}
