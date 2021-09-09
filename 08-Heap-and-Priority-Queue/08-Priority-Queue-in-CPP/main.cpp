#include <iostream>
#include "Solution.h"
#include <unordered_set>
#include <set>

int main()
{
    vector<int> nums = {5, 3, 1, 4, 1, 2, 2, 3};
    int k = 2;
    
    vector<int> res = Solution::topKFrequent(nums, k);
    // for (int num : res)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    unordered_set<int> u_set;
    set<int> set;
    for(int num: nums){
        set.insert(num);
        u_set.insert(num);
    }

    for(int num: set){
        std::cout <<  num << " ";
    }
    std::cout << std::endl;
    for(int num: u_set){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
