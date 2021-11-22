#include "MapSum.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    MapSum mapSum = MapSum();
    mapSum.insert("apple", 3);
    std::cout << mapSum.sum("ap") << std::endl; // return 3 (apple = 3)
    mapSum.insert("app", 2);
    std::cout << mapSum.sum("ap") << std::endl; // return 5 (apple + app = 3 + 2 = 5)
    return 0;
}
