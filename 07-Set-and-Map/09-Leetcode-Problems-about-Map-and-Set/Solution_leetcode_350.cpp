#include <vector>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        map<int, int> num_map1;
        for (int num : nums1)
        {
            if (!num_map1.count(num))
            {
                num_map1[num] = 1;
            }
            else
            {
                num_map1[num] = num_map1[num] + 1;
            }
        }
        for (int num : nums2)
        {
            if (num_map1.count(num))
            {
                res.push_back(num);
                num_map1[num] -= 1;
                if(num_map1[num]== 0){
                    num_map1.erase(num);
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums1 = {1, 2, 2, 3, 1};
    vector<int> nums2 = {2, 2};


    vector<int> res = Solution().intersection(nums1, nums2);

    for(int num: res){
        std::cout << num << "\n";
    }

    return 0;
}
